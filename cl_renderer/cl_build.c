// cl_f4 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_float.h"

static RT_F			f4_min_component(RT_F4 vector)
{
	return (fmin(vector.x, fmin(vector.y, vector.z)));
}

static RT_F			f4_max_component(RT_F4 vector)
{
	return (fmax(vector.x, fmax(vector.y, vector.z)));
}
// cl_settings /////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct 		s_cl_renderer_settings
{
	int				sample_count;
	int				sample_limit;
	int 			sample_depth;
	int				russian_depth;
	int				srgb;
	int				light_pb;
	int 			light_explicit;
	int 			rm_mod;
	int 			rm_step_limit;
	RT_F			rm_step_part;
	int 			rm_max_distance;
}					t_cl_renderer_settings;

// cl_random ///////////////////////////////////////////////////////////////////////////////////////////////////////////

static RT_F			rng_lgc(global ulong *rng_state)
{
	int				gi;
	ulong			x;

	gi = get_global_id(0);
	x = rng_state[gi];
	x = (0x5DEECE66DL * x + 0xBL) & ((1L << 48) - 1);
	rng_state[gi] = x;
    return ((RT_F)x / (1L << 48));
}

static RT_F			rng_xor(global ulong *rng_state)
{
	int				gi;
	ulong			x;

	gi = get_global_id(0);
	x = rng_state[gi];
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
	rng_state[gi] = x;
	x %= 4294967296; // костыль
    return (x / 4294967296.0f);
}

static RT_F			rng(global ulong *rng_state)
{
	return (rng_lgc(rng_state));
}

// cl_ray //////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_float.h"

typedef	struct		s_ray
{
	RT_F4			origin;
	RT_F4			direction;
	RT_F 			t;
}					t_ray;

static RT_F4		ray_intersect(t_ray *ray)
{
	return (ray->origin + ray->direction * ray->t);
}
// cl_filter ///////////////////////////////////////////////////////////////////////////////////////////////////////////

static void			filter_jitter(RT_F *x, global ulong *rng_state)
{
	RT_F			dx;

	dx = 2. * rng(rng_state);
	if (dx < 1.)
    	dx = RT_SQRT(dx) - 1;
    else
    	dx = 1. - RT_SQRT((RT_F)2. - dx);
    *x += dx;
}

// cl_camera ///////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct 		s_camera
{
	RT_F4			position;
	RT_F4			rotation;
	RT_F4			axis_x;
	RT_F4			axis_y;
	RT_F4			axis_z;
	RT_F4			forward;
	RT_F4			forward_backup;
	int				width;
	int				height;
	int 			antialiasing;
    int 			focus;
    RT_F			aperture_size;
    RT_F			focal_length;
}					t_camera;

static void			camera_focus(constant t_camera *camera, t_ray *ray, global ulong *rng_state)
{
	RT_F4			focal_point;

	focal_point = camera->position + ray->direction * camera->focal_length;

	ray->origin.x += (.5 - rng(rng_state)) * camera->aperture_size;
	ray->origin.y += (.5 - rng(rng_state)) * camera->aperture_size;
	ray->origin.z += (.5 - rng(rng_state)) * camera->aperture_size;

	ray->direction = normalize(focal_point - ray->origin);
}

static t_ray		camera_build_ray(constant t_camera *camera, int2 *screen, global ulong *rng_state)
{
	t_ray			result;
	RT_F4			up;
	RT_F4			right;
	RT_F 			xf;
	RT_F 			yf;

	xf = (RT_F)screen->x;
	yf = (RT_F)screen->y;
	if (camera->antialiasing)
	{
		filter_jitter(&xf, rng_state);
    	filter_jitter(&yf, rng_state);
	}
	result.origin = camera->position;
	up = (RT_F4)camera->axis_y * (RT_F)(-1.f * yf + (camera->height - 1.f) / 2.f);
	right = (RT_F4)camera->axis_x * (RT_F)(xf - (camera->width - 1.f) / 2.f);
	result.direction = up + right + camera->forward;
	result.direction = normalize(result.direction);
	if (camera->focus)
		camera_focus(camera, &result, rng_state);
	return (result);
}
// cl_color ////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_color;

static t_color		color_unpack(RT_F4 source, int srgb)
{
    if (srgb)
		source = pow(source, .4f);
	source.x = fmin(source.x, 1.f);
	source.y = fmin(source.y, 1.f);
	source.z = fmin(source.z, 1.f);
	return ((t_color){255 * source.x, 255 * source.y, 255 * source.z, 255});
}

// cl_material /////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct 		s_material
{
	RT_F4			color;
	RT_F4			emission;
}					t_material;

// cl_intersection /////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef struct		s_intersection
{
	t_ray			ray;
	RT_F4			hit;
	RT_F4			normal;
	t_material		material;
	int 			object_id;
	int				cups_flag;
}					t_intersection;

static void			intersection_reset(t_intersection *intersection)
{
	intersection->ray.t = RT_INFINITY;
	intersection->object_id = -1;
}

// cl_object ///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef enum		e_object_type
{
	object_light_point,
	object_light_direct,
	object_sphere,
	object_plane,
	object_cone,
	object_cylinder,
	object_paraboloid,
	object_end
}					t_object_type;

typedef struct		s_object
{
	char 			name[32];
	int				id;
	t_object_type	type;
	t_material		material;
	char			data[RT_CL_OBJECT_CAPACITY];
}					t_object;

// cl_object_sphere ////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef struct					s_object_sphere
{
	RT_F4						position;
	RT_F						radius;
}								t_object_sphere;

static int     					sphere_intersect(constant t_object *object, t_intersection *intersection)
{
	t_object_sphere				data;
	RT_F						k[3];
	RT_F						t;
	RT_F						discriminant;
	RT_F4						temp;

    data = *(constant t_object_sphere *)object->data;
	k[0] = dot(intersection->ray.direction, intersection->ray.direction);
	temp = intersection->ray.origin - data.position;
	k[1] = 2 * dot(temp, intersection->ray.direction);
	k[2] = dot(temp, temp) - data.radius * data.radius;
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant < 0.f)
		return (0);
	t = (-k[1] - RT_SQRT(discriminant)) / (2 * k[0]);
	if (t <= RT_EPSILON || t >= intersection->ray.t)
		return (0);
	intersection->ray.t = t;
	intersection->object_id = object->id;
	return (1);
}

static RT_F4					sphere_normal(constant t_object *object, t_intersection *intersection)
{
	return (normalize(intersection->hit - ((constant t_object_sphere *)object->data)->position));
}

static RT_F4					sphere_random(constant t_object *object, global ulong *rng_state)
{
	t_object_sphere				data;
	RT_F 						theta;
	RT_F 						phi;
	RT_F4						random;

	data = *(constant t_object_sphere *)object->data;
	theta = rng(rng_state) * RT_PI;
	phi = rng(rng_state) * 2 * RT_PI;
	random.x = 0.99 * data.radius * RT_SIN(theta) * RT_COS(phi);
	random.y = 0.99 * data.radius * RT_SIN(theta) * RT_SIN(phi);
	random.z = 0.99 * data.radius * RT_COS(theta);
	random += data.position;
	return (random);
}

static RT_F 					sdf_sphere(constant t_object *object, RT_F4 point)
{
	t_object_sphere				data;

    data = *(constant t_object_sphere *)object->data;
	return (length(data.position - point) - data.radius);
}
// cl_object_plane /////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef struct		s_object_plane
{
	RT_F4			position;
	RT_F4			normal;
}					t_object_plane;

static int			plane_intersect(constant t_object *object, t_intersection *intersection)
{
	t_object_plane	data;
	RT_F4			temp[2];
	RT_F			value[3];

	data = *(constant t_object_plane *)object->data;
	if (!(value[0] = dot(intersection->ray.direction, data.normal)))
		return (0);
	temp[0] = data.position - intersection->ray.origin;
	value[1] = dot(temp[0], data.normal) / value[0];
	if (value[1] <= RT_EPSILON || value[1] >= intersection->ray.t)
		return (0);
	intersection->ray.t = value[1];
	intersection->object_id = object->id;
	return (1);
}

static RT_F4		plane_normal(constant t_object *object, t_intersection *intersection)
{
	return (((constant t_object_plane *)object->data)->normal);
}

static RT_F 		sdf_plane(constant t_object *object, RT_F4 point)
{
	t_object_plane	data;

    data = *(constant t_object_plane *)object->data;
	return (dot(data.normal, point - data.position));
}
// cl_object_cone /////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef struct 		s_object_cone
{
	RT_F4   		top;
	RT_F4   		bottom;
	RT_F4   		axis;
	RT_F 			radius;
	RT_F          	tangent;
}					t_object_cone;

static RT_F         cone_cap_intersect(constant t_object *object, t_intersection *intersection)
{
    t_object_cone	data;
    RT_F            t;

    data = *(constant t_object_cone *)object->data;
    if (!dot(intersection->ray.direction, data.axis))
        return (INFINITY);
    t = dot((data.bottom - intersection->ray.origin), data.axis)
            / dot(intersection->ray.direction, data.axis);
    if (t <= RT_EPSILON)
        return (INFINITY);
    if (length(data.bottom - (intersection->ray.origin + (intersection->ray.direction * t))) < data.radius)
        intersection->cups_flag = 1;
    else
        return (INFINITY);
    return (t);
}

static int			cone_intersect(constant t_object *object, t_intersection *intersection)
{
	t_object_cone	data;
    RT_F4           temp[3];
	RT_F            discriminant;
    int             is_infinity;
    RT_F            angle[2];
	RT_F            t[2];
	RT_F            k[3];

	data = *(constant t_object_cone *)object->data;
	temp[0] = intersection->ray.origin - data.top;
	k[0] = dot(intersection->ray.direction, intersection->ray.direction)
			- pow((RT_F)dot(intersection->ray.direction, data.axis), (RT_F)2.)
			* (1 + data.tangent * data.tangent);
	k[1] = 2 * (dot(temp[0], intersection->ray.direction) - (1 + data.tangent * data.tangent)
			* dot(intersection->ray.direction, data.axis) * dot(temp[0], data.axis));
	k[2] = dot(temp[0], temp[0]) - (1 + data.tangent * data.tangent)
			* pow((RT_F)dot(temp[0], data.axis), (RT_F)2.);
	if ((discriminant = k[1] * k[1] - 4 * k[0] * k[2]) < 0.)
		return (0);
	t[0] = (-k[1] - RT_SQRT(discriminant)) / (2 * k[0]);
	if (t[0] <= RT_EPSILON || t[0] >= intersection->ray.t)
		return (0);

	temp[1] = intersection->ray.origin + (intersection->ray.direction * t[0]);
    temp[2] = temp[1] - data.bottom;
    angle[0] = dot((temp[1] - data.top), data.axis);
    angle[1] = dot((temp[1] - data.bottom), data.axis);
    is_infinity = (length(temp[2]) > length(data.top - data.bottom))
                 || (dot(temp[2], data.axis) > 0.);
    t[1] = cone_cap_intersect(object, intersection);
    if (t[1] != INFINITY && is_infinity)
	    t[0] = t[1];
    else if (!is_infinity)
        intersection->cups_flag = 0;
    else
        return (0);
	intersection->ray.t = t[0];
	intersection->object_id = object->id;
	return (1);
}

static RT_F4		calculate_cone_normal(constant t_object *object, t_intersection *intersection)
{
    t_object_cone	data;
    RT_F4			temp[2];
    RT_F            tmp_value;
    RT_F4           result;

    data = *(constant t_object_cone *)object->data;
    temp[0] = intersection->ray.origin - data.top;
    temp[1] = intersection->ray.origin + (intersection->ray.direction * intersection->ray.t);
    tmp_value = dot(intersection->ray.direction, data.axis)
                * intersection->ray.t + dot(temp[0], data.axis);
    result = (temp[1] - data.top) - (data.axis * ((1 + data.tangent * data.tangent) * tmp_value));
    return (normalize(result));
}

static RT_F4		cone_normal(constant t_object *object, t_intersection *intersection)
{
    if (!intersection->cups_flag)
        return(calculate_cone_normal(object, intersection));
    else
        return(normalize(((constant t_object_cone *)object->data)->axis * -1));
}

// cl_object_cylinder /////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef struct 		    s_object_cylinder
{
	RT_F4   		    top;
	RT_F4   		    bottom;
	RT_F4   		    axis;
	RT_F 			    radius;
}					    t_object_cylinder;

static RT_F             cylinder_cap_intersect(constant t_object *object, t_intersection *intersection)
{
    t_object_cylinder   data;
    RT_F                t[2];

    data = *(constant t_object_cylinder *)object->data;
    if (!dot(intersection->ray.direction, data.axis))
        return (INFINITY);
    t[0] = dot((data.top - intersection->ray.origin), data.axis)
            / dot(intersection->ray.direction, data.axis);
    if (t[0] <= RT_EPSILON)
        return (INFINITY);
    if (length(data.top - (intersection->ray.origin + (intersection->ray.direction * t[0]))) < data.radius)
        intersection->cups_flag = 1;
    else
        t[0] = INFINITY;
    t[1] = dot((data.bottom - intersection->ray.origin), data.axis)
            / dot(intersection->ray.direction, data.axis);
    if (t[1] <= RT_EPSILON)
        return (INFINITY);
    if (length(data.bottom - (intersection->ray.origin + (intersection->ray.direction * t[1]))) < data.radius
        && t[1] < t[0])
        intersection->cups_flag = -1;
    else
        return (t[0]);
    return (t[1]);
}

static int			    cylinder_intersect(constant t_object *object, t_intersection *intersection)
{
	t_object_cylinder	data;
	RT_F4			    temp[2];
    RT_F			    angle[2];
	RT_F                discriminant;
	RT_F                t[2];
	RT_F                k[3];

	data = *(constant t_object_cylinder *)object->data;
	temp[0] = intersection->ray.origin - data.bottom;

	k[0] = dot(intersection->ray.direction, intersection->ray.direction)
			- pow((RT_F)dot(intersection->ray.direction, data.axis), (RT_F)2.);
	k[1] = 2 * (dot(intersection->ray.direction, temp[0])
			- dot(intersection->ray.direction, data.axis)
			* dot(temp[0], data.axis));
	k[2] =  dot(temp[0], temp[0]) - pow((RT_F)dot(temp[0], data.axis), (RT_F)2.)
			- pow((RT_F)data.radius, (RT_F)2.);
	if ((discriminant = k[1] * k[1] - 4 * k[0] * k[2]) < 0.)
		return (0);
	t[0] = (-k[1] - RT_SQRT(discriminant)) / (2 * k[0]);
	if (t[0] <= RT_EPSILON || t[0] >= intersection->ray.t)
		return (0);
    temp[0] = intersection->ray.origin + intersection->ray.direction * t[0];	// p
    angle[0] = dot((temp[0] - data.top), data.axis);
    angle[1] = dot(temp[0] - data.bottom, data.axis);
    t[1] = cylinder_cap_intersect(object, intersection);
    if ((angle[0] > 0. || angle[1] < 0.) && t[1] != INFINITY)
        t[0] = t[1];
    else if (!(angle[0] > 0. || angle[1] < 0.))
        intersection->cups_flag = 0;
    else
        return (0);
	intersection->ray.t = t[0];
	intersection->object_id = object->id;
	return (1);
}

static RT_F4		    calculate_cylinder_normal(constant t_object *object, t_intersection *intersection)
{
    t_object_cylinder   data;
    RT_F4			    temp[2];
    RT_F4               result;

    data = *(constant t_object_cylinder *)object->data;
    temp[0] = intersection->ray.origin + intersection->ray.direction * intersection->ray.t;
    temp[1] = temp[0] - data.bottom;
    result = temp[1] - (data.axis * dot(temp[1], data.axis));
    return (normalize(result));
}

static RT_F4		    cylinder_normal(constant t_object *object, t_intersection *intersection)
{
    /*t_object_cylinder   data;
    RT_F4			    temp[2];
    RT_F4			    result;
    RT_F                tmp;

    data = *(constant t_object_cylinder *)object->data;
    temp[0] = intersection->ray.origin - data.bottom;
    temp[1] = intersection->ray.origin + (intersection->ray.direction * intersection->ray.t);
    tmp = dot(intersection->ray.direction, (data.axis * intersection->ray.t)) + dot(temp[0], data.axis);
    result = (temp[1] - data.bottom) - (data.axis * tmp);
    return (normalize(result));*/
    if (!intersection->cups_flag)
        return (calculate_cylinder_normal(object, intersection));
    else if (intersection->cups_flag == -1)
        return (normalize(((constant t_object_cylinder *)object->data)->axis * -1));
    else
        return (normalize(((constant t_object_cylinder *)object->data)->axis));
}
// cl_object_paraboloid ////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef struct 					s_object_paraboloid
{
	RT_F4						extremum_point;
	RT_F4						axis;
	RT_F 						radius;
}								t_object_paraboloid;

static int     					paraboloid_intersect(constant t_object *object, t_intersection *intersection)
{
	t_object_paraboloid			data;
	RT_F4						vector_x;
    RT_F 						t;
    RT_F 						discriminant;
    RT_F 						k[3];
    RT_F 						x_dot_axis;
    RT_F 						dir_dot_axis;

    data = *(constant t_object_paraboloid *)object->data;
    vector_x = intersection->ray.origin - data.extremum_point;
    x_dot_axis = dot(vector_x, data.axis);
    dir_dot_axis = dot(intersection->ray.direction, data.axis);
	k[0] = dot(intersection->ray.direction, intersection->ray.direction) - dir_dot_axis * dir_dot_axis;
   	k[1] = 2 * (dot(intersection->ray.direction, vector_x) - dir_dot_axis * (x_dot_axis + 2 * data.radius));
   	k[2] = dot(vector_x, vector_x) - x_dot_axis * (x_dot_axis + 4 * data.radius);
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant < 0.f)
		return (0);
	t = (-k[1] - RT_SQRT(discriminant)) / (2 * k[0]);
	if (t <= RT_EPSILON || t >= intersection->ray.t)
		return (0);
	intersection->ray.t = t;
	intersection->object_id = object->id;
	return (1);
}

static RT_F4					paraboloid_normal(constant t_object *object, t_intersection *intersection)
{
	t_object_paraboloid			data;
	RT_F4						normal;
	RT_F						tmp_value;

	data = *(constant t_object_paraboloid *)object->data;
	tmp_value = dot(data.axis, intersection->hit - data.extremum_point);
	normal = (intersection->hit - data.extremum_point) - (data.axis * tmp_value);
	return (normalize(normal));
}

// cl_object_x /////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

static int			object_intersect(constant t_object *object, t_intersection *intersection)
{
	if (object->type == object_sphere)
		return (sphere_intersect(object, intersection));
	else if (object->type == object_plane)
		return (plane_intersect(object, intersection));
	else if (object->type == object_cone)
		return (cone_intersect(object, intersection));
	else if (object->type == object_cylinder)
		return (cylinder_intersect(object, intersection));
	else if (object->type == object_paraboloid)
		return (paraboloid_intersect(object, intersection));
	return (0);
}

static RT_F			object_sdf(constant t_object *object, RT_F4 point)
{
	if (object->type == object_sphere)
		return (sdf_sphere(object, point));
	else if (object->type == object_plane)
		return (sdf_plane(object, point));
	return (RT_INFINITY);
}
// cl_object_normal ////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

static RT_F4		object_normal_rm(constant t_object *object, RT_F4 hit)
{
	RT_F4			nudged_hit;
	RT_F4			normal;
	RT_F4			normal_negative;
	RT_F4			nudge;

	nudge = (RT_F4){RT_CL_RM_NORMAL_EPSILON, 0., 0., 0.};
	nudged_hit = hit + nudge;
	normal.x = object_sdf(object, nudged_hit);
	nudged_hit = hit - nudge;
	normal_negative.x = object_sdf(object, nudged_hit);
	normal.x -= normal_negative.x;

	nudge = (RT_F4){0., RT_CL_RM_NORMAL_EPSILON, 0., 0.};
	nudged_hit = hit + nudge;
	normal.y = object_sdf(object, nudged_hit);
	nudged_hit = hit - nudge;
	normal_negative.y = object_sdf(object, nudged_hit);
	normal.y -= normal_negative.y;

	nudge = (RT_F4){0., 0., RT_CL_RM_NORMAL_EPSILON, 0.};
	nudged_hit = hit + nudge;
	normal.z = object_sdf(object, nudged_hit);
	nudged_hit = hit - nudge;
	normal_negative.z = object_sdf(object, nudged_hit);
	normal.z -= normal_negative.z;

    return (normalize(normal));
}

static RT_F4		object_normal_rt(
					constant t_object *object,
                    t_intersection *intersection)
{
	if (object->type == object_sphere)
		return (sphere_normal(object, intersection));
	else if (object->type == object_plane)
		return (plane_normal(object, intersection));
	else if (object->type == object_cone)
	    return (cone_normal(object, intersection));
	else if (object->type == object_cylinder)
	    return (cylinder_normal(object, intersection));
//	else if (object->type == object_paraboloid)
//		return (paraboloid_normal(object, intersection));
 	return (0);
}

static RT_F4		object_normal(
					constant t_object *object,
					t_intersection *intersection,
					constant t_cl_renderer_settings *settings)
{
	return (!settings->rm_mod ?
		object_normal_rt(object, intersection) :
		object_normal_rm(object, intersection->hit));
}
// cl_scene ////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef struct		s_scene
{
	t_object		objects[RT_CL_SCENE_CAPACITY];
	int				objects_length;
}					t_scene;

static int			scene_intersect_rt(constant t_scene *scene, t_intersection *intersection)
{
	int				result;

	result = 0;
	for (int object_i = 0; object_i < scene->objects_length; object_i++)
    	result += object_intersect(scene->objects + object_i, intersection);
    return (result != 0);
}

static int			scene_intersect_rm(
					constant t_scene *scene,
                    t_intersection *intersection,
                    constant t_cl_renderer_settings *settings)
{
	int				result;
	RT_F4			ray;
	RT_F			total_distance;
	RT_F			temp_distance;
	RT_F			current_distance;
	int				current_id;

	result = 0;
	total_distance = 0.;
	ray = intersection->ray.origin + 15 * intersection->ray.direction;
	for (int step = 0; step < settings->rm_step_limit; step++)
    {
    	current_distance = RT_INFINITY;
    	for (int object_i = 0; object_i < scene->objects_length; object_i++)
		{
			temp_distance = object_sdf(scene->objects + object_i, ray);
			if (temp_distance < current_distance)
			{
				current_distance = temp_distance;
				current_id = object_i;
			}
		}
    	if (current_distance < RT_EPSILON)
    	{
    		result = 1;
    		intersection->object_id = current_id;
    		intersection->ray.t = total_distance;
    		break ;
    	}
    	total_distance += current_distance;
		ray = ray + intersection->ray.direction * current_distance * settings->rm_step_part;
    	if (total_distance > settings->rm_max_distance)
    		break ;
    }
    if (result)
    	intersection->hit = ray;
    return (result);
}

static int			scene_intersect(
					constant t_scene *scene,
					t_intersection *intersection,
					constant t_cl_renderer_settings *settings)
{
	int				result;

	result = !settings->rm_mod ?
		scene_intersect_rt(scene, intersection) :
		scene_intersect_rm(scene, intersection, settings);
	if (result)
	{
		intersection->material = scene->objects[intersection->object_id].material;
		if (!settings->rm_mod)
			intersection->hit = ray_intersect(&intersection->ray);
		intersection->normal = object_normal(scene->objects + intersection->object_id, intersection, settings);
	}
	return (result);
}
// cl_sample ///////////////////////////////////////////////////////////////////////////////////////////////////////////

static void			create_coordinate_system(RT_F4 *normal, RT_F4 *nt, RT_F4 *nb)
{
	if (fabs(normal->x) > fabs(normal->y))
		*nt = (RT_F4){normal->z, 0., -1.f * normal->x, 0.};
	else
		*nt = (RT_F4){0., -1.f * normal->z, normal->y, 0.};
	*nt = normalize(*nt);
	*nb = cross(*normal, *nt);
}

static RT_F4		convert_sample(RT_F4 *normal, RT_F4 *sample, RT_F4 *nt, RT_F4 *nb)
{
	return ((RT_F4)
		{
			sample->x * nb->x + sample->y * normal->x + sample->z * nt->x,
			sample->x * nb->y + sample->y * normal->y + sample->z * nt->y,
			sample->x * nb->z + sample->y * normal->z + sample->z * nt->z,
			0.
		});
}

static RT_F4		sampler_transform(RT_F4 *normal, RT_F4 *sample)
{
	RT_F4		nt;
	RT_F4		nb;

	create_coordinate_system(normal, &nt, &nb);
	return (convert_sample(normal, sample, &nt, &nb));
}

static RT_F4		sample_uniform
					(RT_F4 *normal,
					RT_F *cosine,
					global ulong *rng_state)
{
	RT_F 			r[2];
	RT_F4			sample;
	RT_F			sin_theta;
	RT_F			phi;

	r[0] = rng(rng_state);
	r[1] = rng(rng_state);
	sin_theta = RT_SQRT(RT_MAX(0.0f , 1.0f - r[0] * r[0]));
	phi = 2.0f * RT_PI * r[1];
	*cosine = r[0];
	sample = (RT_F4)
		{
			sin_theta * RT_COS(phi),
			r[0],
			sin_theta * RT_SIN(phi),
			0.
		};
	return (sampler_transform(normal, &sample));
}

static RT_F4			sample_cosine(
						RT_F4 *normal,
						global ulong *rng_state)
{
	RT_F				r1;
	RT_F				r2;
	RT_F 				r1_offset;
	RT_F 				r2_offset;
	RT_F				theta;
	RT_F 				r;
	RT_F4				sample;

	r1 = rng(rng_state);
    r2 = rng(rng_state);
	r1_offset = 2. * r1 - 1.;
	r2_offset = 2. * r2 - 1.;

	if (r1_offset && r2_offset)
	{
		if (RT_ABS(r1_offset) > RT_ABS(r2_offset))
		{
			r = r1_offset;
			theta = RT_PI_4 * (r2_offset / r1_offset);
		}
		else
		{
			r = r2_offset;
			theta = RT_PI_2 - RT_PI_4 * (r1_offset / r2_offset);
		}
		sample.x = r * RT_COS(theta);
		sample.y = r * RT_SIN(theta);
	}
	else
	{
		sample.x = 0.;
		sample.y = 0.;
	}
	sample.z = RT_SQRT(RT_MAX((RT_F)0., (RT_F)1. - sample.x * sample.x - sample.y * sample.y));

	RT_F				temp = sample.y;
	sample.y = sample.z;
	sample.z = temp;
	return (sampler_transform(normal, &sample));
}
// cl_radiance_explicit ////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

static RT_F4		radiance_explicit(
					constant t_scene *scene,
					t_intersection *intersection_object,
					constant t_cl_renderer_settings *settings,
					global ulong *rng_state)
{
	t_intersection	intersection_light;
	RT_F4			radiance;
	RT_F4			light_position;
	RT_F4			light_direction;
	RT_F			emission_intensity;
	RT_F			cos_a_max;
	RT_F			omega;
	RT_F			sphere_radius;

	radiance = 0;
	for (int i = 0; i < scene->objects_length; i++)
	{
 		if (i == intersection_object->object_id)
			continue ;
		if (scene->objects[i].type != object_sphere)
			continue ;
		if (f4_max_component(scene->objects[i].material.emission) == 0.f)
			continue ;

		light_position = sphere_random(scene->objects + i, rng_state);
		light_direction = normalize(light_position - intersection_object->hit);

		intersection_light.ray.origin = intersection_object->hit + 10 * RT_EPSILON * light_direction;
		intersection_light.ray.direction = light_direction;
		intersection_reset(&intersection_light);

		if (!scene_intersect(scene, &intersection_light, settings))
			continue ;
		if (intersection_light.object_id != i)
			continue ;
		emission_intensity = dot(intersection_object->normal, intersection_light.ray.direction);
		if (emission_intensity < 0.00001f)
			continue ;

		sphere_radius = ((constant t_object_sphere *)scene->objects[intersection_light.object_id].data)->radius;
		cos_a_max = RT_SQRT(1.f - (sphere_radius * sphere_radius) / length(intersection_object->hit - light_position));
		omega = 2 * RT_PI * (1.f - cos_a_max);
		radiance += scene->objects[i].material.emission * emission_intensity * omega * RT_1_PI;
	}
	return (radiance);
}

// cl_radiance /////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

static void			radiance_add(
					constant t_scene *scene,
					t_intersection *intersection,
					global RT_F4 *sample,
					constant t_cl_renderer_settings *settings,
					global ulong *rng_state)
{
	RT_F4			radiance;
	RT_F4			explicit;
	RT_F4			mask;
	RT_F			cosine;

	radiance = (RT_F4){0.f, 0.f, 0.f, 1.f};
	mask = 1;
	for (int depth = 0; depth < settings->sample_depth; depth++)
	{
		if (!scene_intersect(scene, intersection, settings))
			break ;
		if (depth > settings->russian_depth && f4_max_component(intersection->material.color) < rng(rng_state))
			break ;

		radiance += mask * intersection->material.emission;
		if (settings->light_explicit)
		{
			explicit = radiance_explicit(scene, intersection, settings, rng_state, global_id);
			radiance += explicit * mask * intersection->material.color;
		}

		intersection->ray.origin = intersection->hit;

#ifdef RT_CL_UNIFORM
		intersection->ray.direction = sample_uniform(&intersection->normal, &cosine, rng_state);
		mask *= intersection->material.color * cosine;
#endif

#ifdef RT_CL_COSINE
		intersection->ray.direction = sample_cosine(&intersection->normal, rng_state);
		mask *= intersection->material.color;
#endif
	}

	if (settings->sample_count == 1)
		*sample = radiance;
	else
		*sample += radiance;
}

static RT_F4		radiance_get(
					global RT_F4 *sample,
					constant t_cl_renderer_settings *settings)
{
	return (*sample / settings->sample_count);
}
// cl_main /////////////////////////////////////////////////////////////////////////////////////////////////////////////

kernel void			cl_main(
					constant t_camera *camera,
					constant t_scene *scene,
					global t_color *image,
					global RT_F4 *sample_store,
					constant t_cl_renderer_settings *settings,
					global ulong *rng_state)
{
	int				global_id;
	int2			screen;
	t_intersection	intersection;

    global_id = get_global_id(0);

	screen.x = global_id % camera->width;
	screen.y = global_id / camera->width;

	intersection.ray = camera_build_ray(camera, &screen, rng_state);
	intersection_reset(&intersection);

    radiance_add(scene, &intersection, sample_store + global_id, settings, rng_state);
	image[global_id] = color_unpack(radiance_get(sample_store + global_id, settings), settings->srgb);
}


