// cl_f4 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_float.h"

typedef enum 		e_f4_rotation_axis
{
	rt_rotation_x,
	rt_rotation_y,
	rt_rotation_z
}					t_f4_rotation_axis;

typedef enum 		e_f4_rotation_direction
{
	rt_rotation_positive,
	rt_rotation_negative
}					t_f4_rotation_direction;

static RT_F			f4_min_component(RT_F4 vector)
{
	return (fmin(vector.x, fmin(vector.y, vector.z)));
}

static RT_F			f4_max_component(RT_F4 vector)
{
	return (fmax(vector.x, fmax(vector.y, vector.z)));
}

static RT_F4		f4_square(RT_F4 vector)
{
	return ((RT_F4)(
		vector.x * vector.x
		- vector.y * vector.y
		- vector.z * vector.z
		- vector.w * vector.w,
		2 * vector.x * vector.y,
		2 * vector.x * vector.z,
		2 * vector.x * vector.w));
}

static RT_F4		f4_mod(const RT_F4 *vector, RT_F value)
{
	RT_F4			result;

	result.x = RT_MOD(vector->x, value);
	result.y = RT_MOD(vector->y, value);
	result.z = RT_MOD(vector->z, value);
	return (result);
}

static RT_F4		f4_pow(RT_F4 vector, RT_F power)
{
	return ((RT_F4){
		RT_POW(vector.x, power),
		RT_POW(vector.y, power),
		RT_POW(vector.z, power),
		0.});
}


static RT_F4		f4_lerp(RT_F4 a, RT_F4 b, RT_F t)
{
	return ((RT_F4){
    	a.x + (b.x - a.x) * RT_MAX((RT_F)0., RT_MIN((RT_F)1., t)),
    	a.y + (b.y - a.y) * RT_MAX((RT_F)0., RT_MIN((RT_F)1., t)),
    	a.z + (b.z - a.z) * RT_MAX((RT_F)0., RT_MIN((RT_F)1., t)),
    	0.});
}

static RT_F4		f4_rotate_x(RT_F4 v, RT_F theta)
{
	RT_F4			copy;

	copy = v;
	v.y = copy.y * RT_COS(theta) + copy.z * RT_SIN(theta);
	v.z = -1 * copy.y * RT_SIN(theta) + copy.z * RT_COS(theta);
	return (v);
}

static RT_F4		f4_rotate_y(RT_F4 v, RT_F theta)
{
	RT_F4			copy;

	copy = v;
	v.x = copy.x * RT_COS(theta) + copy.z * RT_SIN(theta);
	v.z = -1 * copy.x * RT_SIN(theta) + copy.z * RT_COS(theta);
	return (v);
}

static RT_F4 		f4_rotate(
					RT_F4 v,
					t_f4_rotation_axis axis,
					t_f4_rotation_direction direction,
					RT_F theta)
{
	if (direction == rt_rotation_negative)
		theta *= -1;
	if (axis == rt_rotation_x)
		v = f4_rotate_x(v, theta);
	else if (axis == rt_rotation_y)
		v = f4_rotate_y(v, theta);
	return (v);
}

// cl_settings /////////////////////////////////////////////////////////////////////////////////////////////////////////

# include "rt_parameters.h"

typedef struct			s_cl_renderer_settings
{
	t_rt_light_mod		light_mod;
	RT_F4				light_ambient;
	t_rt_bool			illumination;
	RT_F				illumination_value;
	int					sample_count;
	int					sample_limit;
	int					sample_depth;
	int					motion_blur;
	int					motion_blur_sample_count;
	t_rt_tracing_mod	tracing_mod;
	uint				tracing_mod_mask;
	int					rm_step_limit;
	RT_F				rm_step_part;
	RT_F				rm_max_distance;
}						t_rt_settings;

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
// cl_color ////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_color;

static t_color		color_filter_sepia(RT_F4 *source)
{
	unsigned char	sepia_color;

	sepia_color = (255 * source->x) * 0.3 + (255 * source->y) * 0.59 + (255 * source->z) * 0.11;
	return((t_color){sepia_color, sepia_color, sepia_color, 255});
}

static t_color		color_unpack(RT_F4 source, int filter_sepia)
{
	source = RT_POW(source, (RT_F).4);
	source.x = RT_MIN(source.x, (RT_F)1.);
	source.y = RT_MIN(source.y, (RT_F)1.);
	source.z = RT_MIN(source.z, (RT_F)1.);
	if (filter_sepia)
	    return(color_filter_sepia(&source));
	return ((t_color){255 * source.x, 255 * source.y, 255 * source.z, 255});
}

// cl_material /////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct		s_material
{
	RT_F4			color;
	RT_F4			emission;
	RT_F			specular;
	RT_F			reflectance;
	RT_F			transparency;
	RT_F			transparency_index;
}					t_material;

// cl_intersection_x ///////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef struct		s_intersection
{
	t_ray			ray;
	RT_F4			hit;
	RT_F4			normal;
	t_material		material;
	int 			object_id;
	int				cups_flag;
	RT_F			displacement;
}					t_intersection;

static void			intersection_reset(t_intersection *intersection)
{
	intersection->ray.t = RT_INFINITY;
	intersection->object_id = -1;
	intersection->displacement = 0;
	intersection->normal = 0.;
}

static void			intersection_reflect(t_intersection *destination, const t_intersection *source)
{
	RT_F4			reflected;

	reflected = source->normal * ((RT_F)-2. * dot(source->normal, source->ray.direction));
	reflected += source->ray.direction;
	reflected = normalize(reflected);
	destination->ray.direction = reflected;
	destination->ray.origin = source->hit;
}

static void			intersection_refract(t_intersection *destination, const t_intersection *source)
{
	RT_F4			refracted;
	RT_F4			a, b;
	RT_F4			m;
	RT_F			sin_alpha;
	RT_F			sin_beta;
	RT_F			cos_beta;

	m = source->normal * (-1 * dot(source->normal, source->ray.direction));
	m += source->ray.direction;
	m = normalize(m);
	sin_alpha = length(cross(source->ray.direction * -1, source->normal));
	sin_beta = sin_alpha / source->material.transparency_index;
	cos_beta = RT_SQRT(1 - sin_beta * sin_beta);
	a = source->normal * (-1 * cos_beta);
	b = m * sin_beta;
	refracted = a + b;
	refracted = normalize(refracted);
	destination->ray.direction = refracted;
	destination->ray.origin = source->hit + destination->ray.direction * (RT_F)0.1;
}

// cl_object ///////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef enum		e_object_type
{
	object_type_light_ambient,
	object_type_light_point,
	object_type_light_direct,
	object_type_sphere,
	object_type_plane,
	object_type_cone,
	object_type_cylinder,
	object_type_box,
	object_type_paraboloid,
	object_type_moebius,
	object_type_limited,
	object_type_torus,
	object_type_mandelbulb,
	object_type_julia,
	object_type_perforated_cube,
	object_type_explosion,
	object_type_csg,
	object_type_end
}					t_object_type;

typedef struct		s_object
{
	char 			name[RT_NAME_SIZE];
	int				id;
	t_object_type	type;
	int 			texture_id;
	t_material		material;
	char			data[RT_OBJECT_CAPACITY];
	t_rt_bool 		is_visible;
	t_rt_bool 		is_selected;
}					t_object;

// cl_object_sphere ////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef struct					s_object_sphere
{
	RT_F4						position;
	RT_F						radius;
}								t_object_sphere;

static int     					object_sphere_intersect(global t_object *object, t_intersection *intersection)
{
	t_object_sphere				data;
	RT_F						k[3];
	RT_F						t;
	RT_F						discriminant;
	RT_F4						temp;

    data = *(global t_object_sphere *)object->data;
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

static void     				object_sphere_intersect_t(global t_object *object, t_intersection *intersection, RT_F *t)
{
	t_object_sphere				data;
	RT_F						k[3];
	RT_F						discriminant;
	RT_F4						temp;

    data = *(global t_object_sphere *)object->data;
	k[0] = dot(intersection->ray.direction, intersection->ray.direction);
	temp = intersection->ray.origin - data.position;
	k[1] = 2 * dot(temp, intersection->ray.direction);
	k[2] = dot(temp, temp) - data.radius * data.radius;
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant < 0.f)
	{
	    t[0] = RT_INFINITY;
	    t[1] = RT_INFINITY;
	    return ;
	}
	t[0] = (-k[1] - RT_SQRT(discriminant)) / (2 * k[0]);
	t[1] = (-k[1] + RT_SQRT(discriminant)) / (2 * k[0]);
	if (t[0] <= RT_EPSILON || t[0] >= intersection->ray.t)
	{
    	t[0] = RT_INFINITY;
    	t[1] = RT_INFINITY;
    	return ;
    }
}

static RT_F4					object_sphere_normal(global t_object *object, t_intersection *intersection)
{
	return (normalize(intersection->hit - ((global t_object_sphere *)object->data)->position));
}

static RT_F4					object_sphere_random(global t_object *object, global ulong *rng_state)
{
	t_object_sphere				data;
	RT_F 						theta;
	RT_F 						phi;
	RT_F4						random;

	data = *(global t_object_sphere *)object->data;
	theta = rng(rng_state) * RT_PI;
	phi = rng(rng_state) * 2 * RT_PI;
	random.x = 0.9 * data.radius * RT_SIN(theta) * RT_COS(phi);
	random.y = 0.9 * data.radius * RT_SIN(theta) * RT_SIN(phi);
	random.z = 0.9 * data.radius * RT_COS(theta);
	random += data.position;
	return (random);
}


static RT_F						object_sphere_center_shift(global t_object *object)
{
	t_object_sphere				data;

	data = *(global t_object_sphere *)object->data;
    return (data.radius);
}

static RT_F 					object_sphere_sdf(global t_object *object, t_intersection *intersection)
{
	t_object_sphere				data;

    data = *(global t_object_sphere *)object->data;
	return (length(data.position - intersection->hit) - data.radius);
}

// cl_object_plane /////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef enum 			e_rt_limit
{
	rt_limit_no,
	rt_limit_yes
}						t_rt_limit;

typedef struct			s_object_plane
{
	RT_F4				position;
	RT_F4				normal;
	t_rt_limit	is_limiting;
}						t_object_plane;

static int				object_plane_intersect(global t_object *object, t_intersection *intersection)
{
	t_object_plane		data;
	RT_F4				temp[2];
	RT_F				value[3];

	data = *(global t_object_plane *)object->data;
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

static RT_F4			object_plane_normal(global t_object *object, t_intersection *intersection)
{
	return (((global t_object_plane *)object->data)->normal);
}

static void				object_plane_intersect_t(t_object_plane *plane, t_intersection *intersection, RT_F *t)
{
	RT_F4				temp[2];
	RT_F				value[3];

	if (!(value[0] = dot(intersection->ray.direction, plane->normal)))
	{
		*t = RT_INFINITY;
		return ;
	}
	temp[0] = plane->position - intersection->ray.origin;
	value[1] = dot(temp[0], plane->normal) / value[0];
	if (value[1] <= RT_EPSILON || value[1] >= intersection->ray.t)
		*t = RT_INFINITY;
	else
		*t = value[1];
}

static RT_F 			object_plane_sdf(global t_object *object, t_intersection *intersection)
{
	t_object_plane		data;

    data = *(global t_object_plane *)object->data;
	return (dot(data.normal, intersection->hit - data.position));
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
	RT_F            length;
}					t_object_cone;

static RT_F         object_cone_cap_intersect(global t_object *object, t_intersection *intersection)
{
    t_object_cone	data;
    RT_F            t;

    data = *(global t_object_cone *)object->data;
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

static int			object_cone_intersect(global t_object *object, t_intersection *intersection)
{
	t_object_cone	data;
    RT_F4           temp[3];
	RT_F            discriminant;
    int             is_infinity;
    RT_F            angle[2];
	RT_F            t[2];
	RT_F            k[3];

	data = *(global t_object_cone *)object->data;
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
	t[1] = (-k[1] + RT_SQRT(discriminant)) / (2 * k[0]);
	if (t[0] <= RT_EPSILON || t[0] >= intersection->ray.t)
    	return (0);
	temp[1] = intersection->ray.origin + (intersection->ray.direction * t[0]);
    temp[2] = temp[1] - data.bottom;
    angle[0] = dot((temp[1] - data.top), data.axis);
    angle[1] = dot((temp[1] - data.bottom), data.axis);
    is_infinity = (length(temp[2]) > length(data.top - data.bottom))
                 || (dot(temp[2], data.axis) > 0.);
    t[1] = object_cone_cap_intersect(object, intersection);
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

static void			object_cone_intersect_t(global t_object *object, t_intersection *intersection, RT_F *t)
{
	t_object_cone	data;
    RT_F4           temp[3];
	RT_F            discriminant;
    int             is_infinity_part[2];
    RT_F            angle[2];
    RT_F			t_cup;
	RT_F            k[3];

	t[0] = RT_INFINITY;
    t[1] = RT_INFINITY;
	data = *(global t_object_cone *)object->data;
	temp[0] = intersection->ray.origin - data.top;
	k[0] = dot(intersection->ray.direction, intersection->ray.direction)
			- pow((RT_F)dot(intersection->ray.direction, data.axis), (RT_F)2.)
			* (1 + data.tangent * data.tangent);
	k[1] = 2 * (dot(temp[0], intersection->ray.direction) - (1 + data.tangent * data.tangent)
			* dot(intersection->ray.direction, data.axis) * dot(temp[0], data.axis));
	k[2] = dot(temp[0], temp[0]) - (1 + data.tangent * data.tangent)
			* pow((RT_F)dot(temp[0], data.axis), (RT_F)2.);
	if ((discriminant = k[1] * k[1] - 4 * k[0] * k[2]) < 0.)
        return ;

	t[0] = (-k[1] - RT_SQRT(discriminant)) / (2 * k[0]);
	t[1] = (-k[1] + RT_SQRT(discriminant)) / (2 * k[0]);
	if (t[0] <= RT_EPSILON || t[0] >= intersection->ray.t)
	{
		if (t[1] <= RT_EPSILON || t[1] >= intersection->ray.t)
		{
	 		t[0] = RT_INFINITY;
    		t[1] = RT_INFINITY;
			return ;
		}
		t[0] = t[1];
	}

	 for (int i = 0; i < 2; i++)
     {
     	temp[1] = intersection->ray.origin + (intersection->ray.direction * t[i]);
        temp[2] = temp[1] - data.bottom;
        angle[0] = dot((temp[1] - data.top), data.axis);
        angle[1] = dot((temp[1] - data.bottom), data.axis);
        is_infinity_part[i] = (length(temp[2]) > length(data.top - data.bottom))
                     || (dot(temp[2], data.axis) > 0.);
     }

    t_cup = object_cone_cap_intersect(object, intersection);
    if (is_infinity_part[0] && t_cup != INFINITY)
    	t[0] = t_cup;
    else if (is_infinity_part[1] && t_cup != INFINITY)
    	t[1] = t_cup;
   	else if (!is_infinity_part[0])
   		intersection->cups_flag = 0;
   	else
    {
    	t[0] = RT_INFINITY;
        t[1] = RT_INFINITY;
        return ;
    }
}

static RT_F4		calculate_cone_normal(global t_object *object, t_intersection *intersection)
{
    t_object_cone	data;
    RT_F4			temp[2];
    RT_F            tmp_value;
    RT_F4           result;

    data = *(global t_object_cone *)object->data;
    temp[0] = intersection->ray.origin - data.top;
    temp[1] = intersection->ray.origin + (intersection->ray.direction * intersection->ray.t);
    tmp_value = dot(intersection->ray.direction, data.axis)
                * intersection->ray.t + dot(temp[0], data.axis);
    result = (temp[1] - data.top) - (data.axis * ((1 + data.tangent * data.tangent) * tmp_value));
    return (normalize(result));
}

static RT_F4		object_cone_normal(global t_object *object, t_intersection *intersection)
{
    if (!intersection->cups_flag)
        return(calculate_cone_normal(object, intersection));
    else
        return(normalize(((global t_object_cone *)object->data)->axis * -1));
}

// cl_object_cylinder /////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef struct 		    s_object_cylinder
{
	RT_F4   		    top;
	RT_F4   		    bottom;
	RT_F4   		    axis;
	RT_F 			    radius;
	RT_F                length;
    RT_F                hypotenuse;
}					    t_object_cylinder;

static RT_F             object_cylinder_cap_intersect(global t_object *object, t_intersection *intersection)
{
    t_object_cylinder   data;
    RT_F                t[2];

    data = *(global t_object_cylinder *)object->data;
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

static int			    object_cylinder_intersect(global t_object *object, t_intersection *intersection)
{
	t_object_cylinder	data;
	RT_F4			    temp[2];
    RT_F			    angle[2];
	RT_F                discriminant;
	int             	is_infinity_part;
	RT_F                t[2];
	RT_F                k[3];

	data = *(global t_object_cylinder *)object->data;
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
    is_infinity_part = angle[0] > 0. || angle[1] < 0.;
    t[1] = object_cylinder_cap_intersect(object, intersection);

    if (is_infinity_part && t[1] != INFINITY)
        t[0] = t[1];
    else if (!is_infinity_part)
        intersection->cups_flag = 0;
    else
        return (0);
	intersection->ray.t = t[0];
	intersection->object_id = object->id;
	return (1);
}

static void			    object_cylinder_intersect_t(global t_object *object, t_intersection *intersection, RT_F *t)
{
	t_object_cylinder	data;
	RT_F4			    temp;
    RT_F			    angle[2];
	RT_F                discriminant;
	int             	is_infinity_part[2];
	RT_F                t_cups;
	RT_F                k[3];

	t[0] = RT_INFINITY;
    t[1] = RT_INFINITY;
	data = *(global t_object_cylinder *)object->data;
	temp = intersection->ray.origin - data.bottom;

	k[0] = dot(intersection->ray.direction, intersection->ray.direction)
			- pow((RT_F)dot(intersection->ray.direction, data.axis), (RT_F)2.);
	k[1] = 2 * (dot(intersection->ray.direction, temp)
			- dot(intersection->ray.direction, data.axis)
			* dot(temp, data.axis));
	k[2] =  dot(temp, temp) - pow((RT_F)dot(temp, data.axis), (RT_F)2.)
			- pow((RT_F)data.radius, (RT_F)2.);
	if ((discriminant = k[1] * k[1] - 4 * k[0] * k[2]) < 0.)
        return ;

	t[0] = (-k[1] - RT_SQRT(discriminant)) / (2 * k[0]);
	t[1] = (-k[1] + RT_SQRT(discriminant)) / (2 * k[0]);
	if (t[0] <= RT_EPSILON || t[0] >= intersection->ray.t)
	{
    	t[0] = RT_INFINITY;
        t[1] = RT_INFINITY;
    	return ;
    }

    for (int i = 0; i < 2; i++)
    {
    	temp = intersection->ray.origin + intersection->ray.direction * t[i];
    	angle[0] = dot(normalize(temp - data.top), data.axis);
        angle[1] = dot(normalize(temp - data.bottom), data.axis);
        is_infinity_part[i] = (angle[0] > 0. || angle[1] < 0.);
    }

    t_cups = object_cylinder_cap_intersect(object, intersection);
    if (is_infinity_part[0] && t_cups != INFINITY)
    	t[0] = t_cups;
    else if (is_infinity_part[1] && t_cups != INFINITY)
    	t[1] = t_cups;

    if ((!is_infinity_part[0] && t[0] < t[1]) || (!is_infinity_part[1] && t[1] < t[0]))
        intersection->cups_flag = 0;
    else if (is_infinity_part[0] && is_infinity_part[1] && t_cups == INFINITY)
    {
    	t[0] = RT_INFINITY;
        t[1] = RT_INFINITY;
        return ;
    }
}


static RT_F4		    calculate_cylinder_normal(global t_object *object, t_intersection *intersection)
{
    t_object_cylinder   data;
    RT_F4			    temp[2];
    RT_F4               result;

    data = *(global t_object_cylinder *)object->data;
    temp[0] = intersection->ray.origin + intersection->ray.direction * intersection->ray.t;
    temp[1] = temp[0] - data.bottom;
    result = temp[1] - (data.axis * dot(temp[1], data.axis));
    return (normalize(result));
}

static RT_F4		    object_cylinder_normal(global t_object *object, t_intersection *intersection)
{
    if (!intersection->cups_flag)
        return (calculate_cylinder_normal(object, intersection));
    else if (intersection->cups_flag == -1)
        return (normalize(((global t_object_cylinder *)object->data)->axis * -1));
    else
        return (normalize(((global t_object_cylinder *)object->data)->axis));
}

// cl_object_box ///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef struct 		s_object_box
{
	RT_F4   		position;
	RT_F4   		size;
}					t_object_box;

static int			object_box_intersect(global t_object *object, t_intersection *intersection)
{
	t_object_box	data;
	RT_F4			min;
	RT_F4			max;
	RT_F			inv_dir;
	RT_F 			t[2];
	RT_F 			t_near;
	RT_F 			t_far;
	RT_F 			t_temp;
	int 			i;

	data = *(global t_object_box *)object->data;
	min = data.position - data.size / (RT_F)2.;
	max = data.position + data.size / (RT_F)2.;
	i = 0;
	t_near = RT_EPSILON;
	t_far = RT_INFINITY;
	while (i < 3)
	{
		inv_dir = 1. / intersection->ray.direction[i];
        t[0] = (min[i] - intersection->ray.origin[i]) * inv_dir;
        t[1] = (max[i] - intersection->ray.origin[i]) * inv_dir;

		if (inv_dir < 0.)
		{
			t_temp = t[0];
			t[0] = t[1];
			t[1] = t_temp;
		}

		t_near = RT_MAX(t[0], t_near);
		t_far = RT_MIN(t[1], t_far);
		if (t_far <= t_near)
			return (0);
		i++;
	}
	if (t_near == RT_EPSILON || t_near >= intersection->ray.t)
        	return (0);
	intersection->ray.t = t_near;
    intersection->object_id = object->id;
	return (1);
}

static void			object_box_intersect_t(global t_object *object, t_intersection *intersection, RT_F *t_ptr)
{
	t_object_box	data;
	RT_F4			min;
	RT_F4			max;
	RT_F			inv_dir;
	RT_F 			t[2];
	RT_F 			t_near;
	RT_F 			t_far;
	RT_F 			t_temp;
	int 			i;

	t_ptr[0] = RT_INFINITY;
  	t_ptr[1] = RT_INFINITY;
	data = *(global t_object_box *)object->data;
	min = data.position - data.size / (RT_F)2.;
	max = data.position + data.size / (RT_F)2.;
	i = 0;
	t_near = RT_EPSILON;
	t_far = RT_INFINITY;
	while (i < 3)
	{
		inv_dir = 1. / intersection->ray.direction[i];
        t[0] = (min[i] - intersection->ray.origin[i]) * inv_dir;
        t[1] = (max[i] - intersection->ray.origin[i]) * inv_dir;

		if (inv_dir < 0.)
		{
			t_temp = t[0];
			t[0] = t[1];
			t[1] = t_temp;
		}
		t_near = RT_MAX(t[0], t_near);
		t_far = RT_MIN(t[1], t_far);
		if (t_far <= t_near)
			return ;
		i++;
	}
	if (t_near == RT_EPSILON || t_near >= intersection->ray.t)
    	return ;
	t_ptr[0] = t_near;
	t_ptr[1] = t_far;
}

static RT_F 		object_box_sdf(global t_object *object, t_intersection *intersection)
{
	t_object_box	data;
	RT_F4			d;
	RT_F4			point;

	data = *(global t_object_box *)object->data;
	point = data.position - intersection->hit;
	d = RT_ABS(point) - data.size;
	return (RT_MIN((RT_F)RT_MAX((RT_F)d.x, RT_MAX(d.y, d.z)), (RT_F)0.0)
		+ length((RT_F4){RT_MAX(d.x, (RT_F)0.f), RT_MAX(d.y, (RT_F)0.f), RT_MAX(d.z, (RT_F)0.f), (RT_F)0.f}));
}

static RT_F4		object_box_normal(global t_object *object, t_intersection *intersection)
{
	t_object_box	data;
	RT_F4			point;
	RT_F4			normal;
	RT_F			distance;
	RT_F			min;

	data = *(global t_object_box *)object->data;
	point = intersection->hit - data.position;
	normal  = 0;
	min = RT_INFINITY;

	distance = RT_ABS(data.size.x / (RT_F)2. - RT_ABS(point.x));
	if (distance < min)
	{
		normal = sign(point.x) * (RT_F4){1., 0., 0., 0.};
		min = distance;
	}

	distance = RT_ABS(data.size.y / (RT_F)2. - RT_ABS(point.y));
	if (distance < min)
	{
		normal = sign(point.y) * (RT_F4){ 0., 1., 0., 0.};
		min = distance;
	}

	distance = RT_ABS(data.size.z / (RT_F)2. - RT_ABS(point.z));
	if (distance < min)
		normal = sign(point.z) * (RT_F4){ 0., 0., 1., 0.};

	return (normal);
}
// cl_object_paraboloid ////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef struct 					s_object_paraboloid
{
	RT_F4						extremum_point;
	RT_F4						axis;
	RT_F 						radius;
}								t_object_paraboloid;

static int     					object_paraboloid_intersect(global t_object *object, t_intersection *intersection)
{
	t_object_paraboloid			data;
	RT_F4						vector_x;
    RT_F 						t;
    RT_F 						discriminant;
    RT_F 						k[3];
    RT_F 						x_dot_axis;
    RT_F 						dir_dot_axis;

    data = *(global t_object_paraboloid *)object->data;
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

static RT_F4					object_paraboloid_normal(global t_object *object, t_intersection *intersection)
{
	t_object_paraboloid			data;
	RT_F4						normal;
	RT_F						tmp_value;

	data = *(global t_object_paraboloid *)object->data;
	tmp_value = dot(data.axis, intersection->hit - data.extremum_point);
	normal = (intersection->hit - data.extremum_point) - (data.axis * tmp_value);
	return (normalize(normal));
}

// cl_object_moebius ///////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef struct		            s_object_moebius
{
    RT_F4   		            position;
    RT_F 			            radius;
    RT_F			            half_width;
}					            t_object_moebius;

// solving cubic equation //////////////////////////////////////////////////////////////////////////////////////////////

// Solution via Kardano formulas http://ateist.spb.ru/mw/kardano.htm

typedef struct					s_moebius_equation
{
	RT_F						q;
	RT_F						r;
	RT_F						bq;
	RT_F						br;
    RT_F						ba;
    RT_F						bb;
	RT_F						bq3;
	RT_F						br2;
	RT_F						cr2;
	RT_F						cq3;
	RT_F						sqrt_bq;
	RT_F						sgn_br;
	RT_F						ratio;
	RT_F						theta;
	RT_F						norm;
	RT_F						x0;
	RT_F						x1;
	RT_F						x2;
	int							i;
}								t_moebius_equation;

static void						ft_swap(RT_F *a, RT_F *b)
{
	RT_F						tmp;

	tmp = *b;
	*b = *a;
	*a = tmp;
}

static t_moebius_equation		init_structure(const RT_F *coefficients)
{
	t_moebius_equation			eq;

	eq.q = coefficients[2] * coefficients[2] - 3 * coefficients[1];
	eq.r = 2 * coefficients[2] * coefficients[2] * coefficients[2]
		- 9 * coefficients[2] * coefficients[1] + 27 * coefficients[0];
	eq.bq = eq.q / 9;
	eq.br = eq.r / 54;
	eq.bq3 = eq.bq * eq.bq * eq.bq;
	eq.br2 = eq.br * eq.br;
	eq.cr2 = 729 * eq.r * eq.r;
	eq.cq3 = 2916 * eq.q * eq.q * eq.q;
	eq.sgn_br = eq.br >= 0 ? 1 : -1;
	eq.i = 0;
	return (eq);
}

static int						solve_second_case(t_moebius_equation eq, const RT_F *coefficients, RT_F *r)
{
	eq.sqrt_bq = RT_SQRT(eq.bq);
	if (eq.br > 0)
	{
		r[0] = -2 * eq.sqrt_bq - coefficients[2] / 3;
		r[1] = eq.sqrt_bq - coefficients[2] / 3;
		r[2] = eq.sqrt_bq - coefficients[2] / 3;
	}
	else
	{
		r[0] = -eq.sqrt_bq - coefficients[2] / 3;
		r[1] = -eq.sqrt_bq - coefficients[2] / 3;
		r[2] = 2 * eq.sqrt_bq - coefficients[2] / 3;
	}
	return (3);
}

static int						solve_third_case(t_moebius_equation eq, const RT_F *coefficients, RT_F *r)
{
	eq.ratio = eq.sgn_br * RT_SQRT(eq.br2 / eq.bq3);
	eq.theta = acos(eq.ratio);
	eq.norm = -2 * RT_SQRT(eq.bq);
	eq.x0 = eq.norm * RT_COS((RT_F)eq.theta / 3) - coefficients[2] / 3;
	eq.x1 = eq.norm * RT_COS((RT_F)(eq.theta + 2.0 * RT_PI) / 3) - coefficients[2] / 3;
	eq.x2 = eq.norm * RT_COS((RT_F)(eq.theta - 2.0 * RT_PI) / 3) - coefficients[2] / 3;
	if (eq.x0 > eq.x1)
		ft_swap(&eq.x0, &eq.x1);
	if (eq.x1 > eq.x2)
	{
		ft_swap(&eq.x1, &eq.x2);
		if (eq.x0 > eq.x1)
			ft_swap(&eq.x0, &eq.x1);
	}
	r[0] = eq.x0;
	r[1] = eq.x1;
	r[2] = eq.x2;
	return (3);
}

static int						solve_fourth_case(t_moebius_equation eq, const RT_F *coefficients, RT_F *r)
{
	eq.ba = -eq.sgn_br * pow((RT_F)(RT_ABS(eq.br) + RT_SQRT(eq.br2 - eq.bq3)), (RT_F)(1.0 / 3.0));
	eq.bb = eq.bq / eq.ba;
	r[0] = eq.ba + eq.bb - coefficients[2] / 3;
	return (1);
}

static int						solve_moebius_equation(RT_F *coefficients, RT_F *r)
{
	t_moebius_equation			coeffs;

	coeffs = init_structure(coefficients);
	if (coeffs.br == 0 && coeffs.bq == 0)
	{
		while (coeffs.i++ < 3)
			r[coeffs.i] = -coefficients[2] / 3;
		return (3);
	}
	else if (coeffs.cr2 == coeffs.cq3)
		return (solve_second_case(coeffs, coefficients, r));
	else if (coeffs.br2 < coeffs.bq3)
		return (solve_third_case(coeffs, coefficients, r));
	else
		return (solve_fourth_case(coeffs, coefficients, r));
}

// calculating t ///////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct		            s_moebius_coefficients
{
	RT_F 			            radius;
	RT_F 			            ox;
	RT_F 			            dx;
	RT_F 			            oy;
	RT_F 			            dy;
	RT_F 			            oz;
	RT_F 			            dz;
	RT_F 			            max;
}					            t_moebius_coefficients;

static int						floating_point_sign(RT_F x)
{
    if (x < -RT_EPSILON)
    	return (-1);
    return (x > RT_EPSILON);
}

static int						is_inside_moebius_strip(t_moebius_coefficients *m, RT_F4 hit)
{
	RT_F						t;
	RT_F						s;

    t = atan2(hit.y, hit.x);
    if (floating_point_sign(RT_SIN(t / 2)) != 0)
    	s = hit.z / RT_SIN(t / 2);
    else
    	s = floating_point_sign(RT_COS(t)) ?
    		(hit.x / RT_COS(t) - m->radius) / RT_COS(t / 2) :
    		(hit.y / RT_SIN(t) - m->radius) / RT_COS(t / 2);
    hit.x -= (m->radius + s * RT_COS(t / 2)) * RT_COS(t);
    hit.y -= (m->radius + s * RT_COS(t / 2)) * RT_SIN(t);
    hit.z -= s * RT_SIN(t / 2);
    if (floating_point_sign(hit.x * hit.x + hit.y * hit.y + hit.z * hit.z))
    	return (0);
    return (s >= -m->max && s <= m->max);
}

static RT_F						choose_equation_root(RT_F *roots, int result, const t_ray *ray, t_moebius_coefficients *m)
{
    int							i;
    RT_F4						hit;

    i = 0;
    while (i < result)
    {
    	if (roots[i] > -1.)
    	{
    		hit = ray->direction * roots[i] + ray->origin;
    		if (is_inside_moebius_strip(m, hit))
    			return (roots[i]);
    	}
    	i++;
    }
    return (INFINITY);
}

static void						init_equation_coefficients(t_moebius_coefficients *m, RT_F *coefficients)
{

    coefficients[0] = (m->ox * m->ox * m->oy + m->oy * m->oy * m->oy - 2 * m->ox * m->ox * m->oz
    	- 2 * m->oy * m->oy * m->oz + m->oy * m->oz * m->oz - 2 * m->ox * m->oz * m->radius - m->oy * m->radius * m->radius);
    coefficients[1] = (m->dy * m->ox * m->ox - 2 * m->dz * m->ox * m->ox + 2 * m->dx * m->ox * m->oy
    	+ 3 * m->dy * m->oy * m->oy - 2 * m->dz * m->oy * m->oy - 4 * m->dx * m->ox * m->oz - 4 * m->dy * m->oy * m->oz
    	+ 2 * m->dz * m->oy * m->oz + m->dy * m->oz * m->oz - 2 * m->dz * m->ox * m->radius - 2 * m->dx * m->oz * m->radius -
    	m->dy * m->radius * m->radius);
    coefficients[2] = (2 * m->dx * m->dy * m->ox - 4 * m->dx * m->dz * m->ox + m->dx * m->dx * m->oy
    	+ 3 * m->dy * m->dy * m->oy - 4 * m->dy * m->dz * m->oy + m->dz * m->dz * m->oy - 2 * m->dx * m->dx * m->oz
    	- 2 * m->dy * m->dy * m->oz + 2 * m->dy * m->dz * m->oz - 2 * m->dx * m->dz * m->radius);
    coefficients[3] = m->dx * m->dx * m->dy + m->dy * m->dy * m->dy - 2 * m->dx * m->dx * m->dz - 2 * m->dy * m->dy * m->dz + m->dy * m->dz * m->dz;
    coefficients[0] /= coefficients[3];
    coefficients[1] /= coefficients[3];
    coefficients[2] /= coefficients[3];
}

static void						init_moebius_coefficients(t_moebius_coefficients *moebius, t_object_moebius *data, const t_ray *ray)
{
	moebius->radius = data->radius;
    moebius->ox = ray->origin.x;
    moebius->dx = ray->direction.x;
    moebius->oy = ray->origin.y;
    moebius->dy = ray->direction.y;
    moebius->oz = ray->origin.z;
    moebius->dz = ray->direction.z;
    moebius->max = data->half_width;
}

static RT_F						calculate_moebius_t(const t_ray *ray, t_object_moebius *data, t_moebius_coefficients *moebius)
{
	RT_F						coefficients[4];
    RT_F						root[3];
    int							result;

	init_moebius_coefficients(moebius, data, ray);
    init_equation_coefficients(moebius, coefficients);
    result = solve_moebius_equation(coefficients, root);
    return (choose_equation_root(root, result, ray, moebius));
}

static int     					object_moebius_intersect(global t_object *object, const t_intersection *intersection)
{
	t_object_moebius			data;
	t_moebius_coefficients      moebius_coefficients;
	RT_F						t;

#ifndef RT_DOUBLE
	return (0);
#endif
    data = *(global t_object_moebius *)object->data;
	t = calculate_moebius_t(&intersection->ray, &data, &moebius_coefficients);
	if (t == RT_INFINITY)
		return (0);
	intersection->ray.t = t;
	intersection->object_id = object->id;
	return (1);
}

// calculating normal //////////////////////////////////////////////////////////////////////////////////////////////////

static RT_F4					object_moebius_normal(global t_object *object, const t_intersection *intersection)
{
	t_object_moebius			data;
	t_moebius_coefficients      moebius_coefficients;
	RT_F4						normal;
	RT_F4						vector_x;

	data = *(global t_object_moebius *)object->data;
	vector_x = intersection->hit;
	init_moebius_coefficients(&moebius_coefficients, &data, &intersection->ray);

	normal.x = -2 * data.radius * vector_x.z + 2 * vector_x.x * vector_x.y - 4 * vector_x.x * vector_x.z;
	normal.y = -data.radius * data.radius + vector_x.x * vector_x.x + 3 * vector_x.y * vector_x.y
		- 4 * vector_x.y * vector_x.z + vector_x.z * vector_x.z;
    normal.z = -2 * data.radius * vector_x.x - 2 * vector_x.x * vector_x.x - 2 * vector_x.y
    	* vector_x.y + 2 * vector_x.y * vector_x.z;
	return (normalize(normal));
}

// cl_object_limited ///////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct 			    s_object_limited
{
	int     			    main_id;
	int     			    limit_id;
	char 				    main_name[64];
	char    			    limit_name[64];
}						    t_object_limited;

static int					object_limited_intersect(global t_object *object, t_intersection *intersection)
{
	global t_object			*scene_begin;
	t_object_limited		limited;
	global t_object			*main;
	t_object_plane			limit;

	RT_F					dot_value[2];
	RT_F					main_t[2];
	RT_F					limit_t;

	scene_begin = object - object->id;
	limited = *(global t_object_limited *)object->data;

	if (limited.main_id == -1 || limited.limit_id == -1)
	    return (0);

	main = scene_begin + limited.main_id;
	limit = *(global t_object_plane *)scene_begin[limited.limit_id].data;

	if (main->type == object_type_sphere)
		object_sphere_intersect_t(main, intersection, main_t);
	else if (main->type == object_type_cone)
    	object_cone_intersect_t(main, intersection, main_t);
	else if (main->type == object_type_cylinder)
    	object_cylinder_intersect_t(main, intersection, main_t);
	else if (main->type == object_type_box)
		object_box_intersect_t(main, intersection, main_t);
	else
		return (0);

	object_plane_intersect_t(&limit, intersection, &limit_t);

    dot_value[0] = dot(limit.position - intersection->ray.origin, limit.normal);
    dot_value[1] = dot(intersection->ray.direction, limit.normal);

    if (dot_value[0] > 0 && main_t[0] < limit_t)
    {
        intersection->ray.t = main_t[0];
        intersection->object_id = limited.main_id;
    }
    else if (dot_value[0] == 0 && dot_value[1] <= 0)
	{
		intersection->ray.t = main_t[0];
		intersection->object_id = limited.main_id;
    }
    else if (dot_value[0] <= 0 && limit_t > main_t[0] && limit_t < main_t[1])
    {
		intersection->ray.t = limit_t;
		intersection->object_id = limited.limit_id;
    }
    else if (dot_value[0] <= 0 && main_t[0] != RT_INFINITY && limit_t < main_t[0])
    {
		intersection->ray.t = main_t[0];
		intersection->object_id = limited.main_id;
	}
	else
		return (0);
	return (1);
}
// cl_object_torus /////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef struct 		s_object_torus
{
	RT_F4   		position;
	RT_F 			t_0;
	RT_F          	t_1;
}					t_object_torus;

static RT_F 		object_torus_sdf(global t_object *object, t_intersection *intersection)
{
	t_object_torus	data;
	RT_F2			q;
	RT_F4			point;

	data = *(global t_object_torus *)object->data;
	point = data.position - intersection->hit;
	q = (RT_F2)(length(point.xz) - data.t_0, point.y);
	return (length(q) - data.t_1);
}

// cl_object_julia /////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef struct		s_object_julia
{
	RT_F4			position;
	int				iterations;
	RT_F4			value;
}					t_object_julia;

static RT_F			object_julia_sdf(global t_object *object, t_intersection *intersection)
{
	t_object_julia	data;
	RT_F			md;
	RT_F			mz;
	RT_F4			point;

	data = *(global t_object_julia *)object->data;
	md = 1.;
	point = data.position - intersection->hit;
	mz = dot(point, point);

	for (int iter = 0; iter < data.iterations; iter++)
	{
		md *= 4. * mz;
		point = f4_square(point);
		point += data.value;
		mz = dot(point, point);
		if (mz > 4.)
			break ;
	}
	return (.25 * RT_SQRT(mz / md) * log(mz));
}

// cl_object_mandelbulb ////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef struct				s_object_mandelbulb
{
	RT_F4					position;
	int						iterations;
	RT_F					power;
}							t_object_mandelbulb;

static RT_F					object_mandelbulb_sdf(global t_object *object, t_intersection *intersection)
{
	t_object_mandelbulb		data;
	RT_F4					z;
	RT_F					zr;
	RT_F					dr;
	RT_F					r;
	RT_F					phi;
	RT_F					theta;
	RT_F4					point;

	data = *(global t_object_mandelbulb *)object->data;
	point = data.position - intersection->hit;
	r = 0.;
    dr = 1.;
	z = point;
	for (int iter = 0; iter < data.iterations; iter++)
	{
		r = length(z);
		if (r > 2.)
        	break ;
        theta = acos(z.z / r);
        phi = atan2(z.y, z.x);

        dr = RT_POW((RT_F)r, (RT_F)(data.power - 1.)) * data.power * dr + 1.;

        zr = RT_POW(r, data.power);
        theta *= data.power;
        phi *= data.power;

        z = (RT_F4){RT_SIN(theta) * RT_COS(phi), RT_SIN(phi) * RT_SIN(theta), RT_COS(theta), 0.} * zr;
        z += point;
	}
	return (.5 * log(r) * r / dr);
}

// cl_object_perforated_cube ///////////////////////////////////////////////////////////////////////////////////////////

typedef struct 		            s_object_perforated_cube
{
    RT_F4                       position;
	int     		            iterations;
}					            t_object_perforated_cube;

static RT_F                     static_box_sdf(RT_F4 size, RT_F4 point)
{
    RT_F4                       d;

    d = RT_ABS(point) - size;
    return (RT_MIN((RT_F)RT_MAX((RT_F)d.x, RT_MAX(d.y, d.z)), (RT_F)0.0)
    	+ length((RT_F4){RT_MAX(d.x, (RT_F)0.f), RT_MAX(d.y, (RT_F)0.f), RT_MAX(d.z, (RT_F)0.f), (RT_F)0.f}));
}

static RT_F                     static_cross_sdf(RT_F4 point)
{
	RT_F4						tmp_point;
	RT_F4						size;
	RT_F						sdf_value[3];

	size = (RT_F4){RT_INFINITY, 1., 1., 0.};
	tmp_point = (RT_F4){point.x, point.y, point.z, 0.};
	sdf_value[0] = static_box_sdf(size, tmp_point);

	size = (RT_F4){1., RT_INFINITY, 1., 0.};
    tmp_point = (RT_F4){point.y, point.z, point.x, 0.};
    sdf_value[1] = static_box_sdf(size, tmp_point);

    size = (RT_F4){1., 1., RT_INFINITY, 0.};
    tmp_point = (RT_F4){point.z, point.x, point.y, 0.};
    sdf_value[2] = static_box_sdf(size, tmp_point);
    return (RT_MIN(sdf_value[0], RT_MIN(sdf_value[1], sdf_value[2])));
}

static RT_F 		            object_perforated_cube_sdf(global t_object *object, t_intersection *intersection)
{
	t_object_perforated_cube	data;
	RT_F                        box_sdf_value;
	RT_F                        cross_value;
	RT_F                        cross_period;
	RT_F                        cross_division;
	RT_F4                       cross_shift;
	RT_F4						shifted_point;
	RT_F4						point;

	data = *(global t_object_perforated_cube *)object->data;
	point = data.position - intersection->hit;

	box_sdf_value = static_box_sdf((RT_F4){1., 1., 1., 0.}, point);

	cross_period = (RT_F)2.;
	cross_division = (RT_F)3.;
	cross_shift = (RT_F4){1., 1., 1., 0.};

	for (int iter = 0; iter < data.iterations; iter++)
	{
		shifted_point = RT_ABS(point);

		shifted_point += cross_shift;
        shifted_point = f4_mod(&shifted_point, cross_period);
        shifted_point -= cross_shift;

        shifted_point *= cross_division;
        cross_value = static_cross_sdf(shifted_point) / cross_division;

        box_sdf_value = RT_MAX(box_sdf_value, (RT_F)-1. * cross_value);
        cross_period /= (RT_F)3.;
        cross_shift /= (RT_F)3.;
        cross_division *= (RT_F)3.;
	}
	return (box_sdf_value);
}

// cl_rm_csg ///////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct 			    s_object_csg
{
	int     			    positive_id;
	int     			    negative_id;
	char 				    positive_name[64];
	char    			    negative_name[64];
}						    t_object_csg;

static	RT_F		        csg_sdf_difference(const RT_F distance_a, const RT_F distance_b)
{
	return (RT_MAX(distance_a, -distance_b));
}

static RT_F			        sdf_csg_compute(global t_object *object, t_intersection *intersection)
{
	if (object->type == object_type_sphere)
		return (object_sphere_sdf(object, intersection));
	else if (object->type == object_type_box)
        return (object_box_sdf(object, intersection));
    return (RT_INFINITY);
}

static RT_F 		       object_csg_sdf(global t_object *object, t_intersection *intersection)
{
	global t_object_csg		*data;
	global t_object       	*scene_begin;
	RT_F					sdf[2];

    data = (global t_object_csg *)object->data;
	if (data->positive_id == -1 || data->negative_id == -1)
     	return (RT_INFINITY);
    scene_begin = object - object->id;
    sdf[0] = sdf_csg_compute(scene_begin + data->positive_id, intersection);
    sdf[1] = sdf_csg_compute(scene_begin + data->negative_id, intersection);
    return (csg_sdf_difference(sdf[0], sdf[1]));
}

 // cl_object_explosion ////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct			s_object_explosion
{
	RT_F4				position;
	RT_F				radius;
	RT_F				noise_amplitude;
}						t_object_explosion;

static RT_F				lerp(RT_F f0, RT_F f1, RT_F t)
{
	return (f0 + (f1 - f0) * RT_MAX((RT_F)0., RT_MIN((RT_F)1., t)));
}

static RT_F				hash(RT_F n)
{
	RT_F				x;

	x = RT_SIN(n) * (RT_F)43758.5453;
	return (x - floor(x));
}

static RT_F				noise(RT_F4 x)
{
	RT_F4				p;
	RT_F4				f;
	RT_F				n;

	p = (RT_F4){floor(x.x), floor(x.y), floor(x.z), 0.};
	f = (RT_F4){x.x - p.x, x.y - p.y, x.z - p.z, 0.};
	f = f * dot(f, ((RT_F4){(RT_F)3., (RT_F)3., (RT_F)3., 0.} - f * (RT_F)2.));
	n = dot(p, (RT_F4){(RT_F)1.f, (RT_F)57.f, (RT_F)113.f, 0.});

	return (lerp(
				lerp(
					lerp(hash(n +  0.f), hash(n +  1.f), f.x),
					lerp(hash(n + 57.f), hash(n + 58.f), f.x),
					f.y),
				lerp(
					lerp(hash(n + 113.f), hash(n + 114.f), f.x),
					lerp(hash(n + 170.f), hash(n + 171.f), f.x),
					f.y),
				f.z)
			);
	}

static RT_F				brownian_motion(RT_F4 x)
{
	RT_F				f;

	x = (RT_F4){
		dot((RT_F4){0.,  0.8,  0.6, 0.}, x),
		dot((RT_F4){-0.8,  0.36, -0.48, 0.}, x),
		dot((RT_F4){-0.6, -0.48,  0.64, 0.}, x),
		(RT_F)0.};

	f = 0.;

	f += (RT_F)0.5000 * noise(x);

	x *= (RT_F)2.32;
	f += (RT_F)0.2500 * noise(x);

	x *= (RT_F)3.03;
	f += (RT_F)0.1250 * noise(x);

	x *= (RT_F)2.61;
	f += (RT_F)0.0625 * noise(x);

	return (f / (RT_F)0.9375);
}

static RT_F 			object_explosion_sdf(global t_object *object, t_intersection *intersection)
{
	t_object_explosion	data;
	RT_F				displacement;

	data = *(global t_object_explosion *)object->data;
	displacement = (RT_F)-1. * brownian_motion(intersection->hit * data.noise_amplitude) * 1.7;
	intersection->displacement = displacement;
	return (length(data.position - intersection->hit) - data.radius - displacement);
}

# define EXPLOSION_COLOR		(RT_F4){.02, .02, .02, 1.}
# define EXPLOSION_EMISSION		(RT_F4){1., 0.6, 0., 1.}

static void 			object_explosion_build_material(global t_object *object, t_intersection *intersection)
{
	intersection->material.color = EXPLOSION_COLOR;
	intersection->material.emission = f4_pow((RT_F)1.3 * EXPLOSION_EMISSION * RT_ABS(intersection->displacement), 8.);
}
// cl_object_x /////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_control.h"
#include "rt_parameters.h"

static int			object_is_pair(global t_object *object)
{
	return (object->type == object_type_limited || object->type == object_type_csg);
}

static int			object_intersect(global t_object *object, t_intersection *intersection)
{
	if (object->is_visible == rt_false)
		return (0);
	if (object->type == object_type_sphere)
		return (object_sphere_intersect(object, intersection));
	else if (object->type == object_type_plane)
		return (object_plane_intersect(object, intersection));
	else if (object->type == object_type_cone)
		return (object_cone_intersect(object, intersection));
	else if (object->type == object_type_cylinder)
		return (object_cylinder_intersect(object, intersection));
	else if (object->type == object_type_box)
		return (object_box_intersect(object, intersection));
	else if (object->type == object_type_paraboloid)
		return (object_paraboloid_intersect(object, intersection));
	else if (object->type == object_type_moebius)
		return (object_moebius_intersect(object, intersection));
	else if (object->type == object_type_limited)
		return (object_limited_intersect(object, intersection));
	return (0);
}

static RT_F			object_sdf(global t_object *object, t_intersection *intersection)
{
	if (object->is_visible == rt_false)
		return (RT_INFINITY);
	if (object->type == object_type_sphere)
		return (object_sphere_sdf(object, intersection));
	else if (object->type == object_type_plane)
		return (object_plane_sdf(object, intersection));
	else if (object->type == object_type_julia)
		return (object_julia_sdf(object, intersection));
	else if (object->type == object_type_mandelbulb)
		return (object_mandelbulb_sdf(object, intersection));
	else if (object->type == object_type_torus)
		return (object_torus_sdf(object, intersection));
	else if (object->type == object_type_box)
		return (object_box_sdf(object, intersection));
	else if (object->type == object_type_perforated_cube)
		return (object_perforated_cube_sdf(object, intersection));
	else if (object->type == object_type_explosion)
		return (object_explosion_sdf(object, intersection));
	else if (object->type == object_type_csg)
		return (object_csg_sdf(object, intersection));
	return (RT_INFINITY);
}

static RT_F			object_center_shift(global t_object *object)
{
	if (object->type == object_type_sphere)
		return (object_sphere_center_shift(object));
	return (0);
}

// cl_camera_definition ////////////////////////////////////////////////////////////////////////////////////////////////

# include "rt_parameters.h"

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
	int 			filter_antialiasing;
	t_rt_filter_mod	filter_mod;
	int 			focus;
	RT_F			aperture_size;
	RT_F			focal_length;
	int 			focus_request;
	int 			select_request;
	int 			select_request_object;
	RT_F2			request_value;
}					t_camera;

// cl_texture //////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct 		s_texture
{
	char 			name[RT_TEXTURE_MAX_NUMBER][RT_NAME_SIZE];
	RT_F4			data[RT_TEXTURE_DATA_SIZE];
	int 			texture_length[RT_TEXTURE_MAX_NUMBER];
	int				width[RT_TEXTURE_MAX_NUMBER];
	int				height[RT_TEXTURE_MAX_NUMBER];
	int 			textures_number;
}					t_texture;

static RT_F4        get_color_from_texture(
                    global t_texture *texture,
                    int texture_id,
                    RT_F *u, RT_F *v)
{
    global RT_F4    *pointer;
    int             x;
    int             y;

    pointer = &texture->data[0];
    for (int i = 0; i < texture_id; i++)
        pointer += texture->texture_length[i];
    x = floor(*u * (RT_F)texture->width[texture_id]);
    y = floor((1 - *v) * (texture->height[texture_id] - (RT_F)0.001));

    if (x < 0) x = 0;
    if (y < 0) y = 0;

    if (x > (texture->width[texture_id] - 1))
    	x = texture->width[texture_id] - 1;
    if (y > (texture->height[texture_id] - 1))
        	y = texture->height[texture_id] - 1;
    return (pointer[y * texture->width[texture_id] + x]);
}

static RT_F4               projection(RT_F4 point_a, RT_F4 point_b, RT_F4  direction_bc)
{
    RT_F            cosine;
    RT_F4           projection;
    RT_F4           hypotenuse;
    RT_F4           cathet_bc;
    RT_F4           ba;
    ba = point_a - point_b;
    hypotenuse = length(ba);
    cosine = dot(direction_bc, normalize(ba));
    cathet_bc = cosine * hypotenuse;
    projection = point_b + direction_bc * cathet_bc;
    return(projection);
}

static void                local_default(RT_F4 *top, RT_F4 *bottom, RT_F4 *intersection)
{
    *top += -(*bottom);
    *intersection += -(*bottom);
    *bottom += -(*bottom);
}

static void         cylinder_texture(
                    global t_camera *camera,
                    global t_texture *texture,
                    global t_object *object,
                    t_intersection intersection,
                    RT_F *u, RT_F *v)
{
    t_object_cylinder data;
    RT_F4           normal;
    RT_F4           top;
    data = *(global t_object_cylinder* )object->data;
    local_default(&data.top, &data.bottom, &intersection.hit);
    top = projection(intersection.hit, data.top, data.axis);
    normal = normalize(intersection.hit - top);
    if ((data.top - data.bottom).y == 0)
        *u = 0.5 + atan2(normal.y, normal.z) / (2 * RT_PI);
    else
        *u = 0.5 + atan2(normal.z, normal.x) / (2 * RT_PI);
    if (dot(normalize(data.bottom - intersection.hit), data.axis) >= -RT_EPSILON
        && dot(normalize(data.bottom - intersection.hit), data.axis) <= RT_EPSILON)
        *v = length(intersection.hit - data.bottom) / data.length;
    else if (dot(normalize(data.top - intersection.hit), data.axis) >= -RT_EPSILON
        && dot(normalize(data.top - intersection.hit), data.axis) <= RT_EPSILON)
        *v = 1 - length(intersection.hit - data.top) / data.length;
    else
        *v = 1 - (data.radius + length(top - data.top)) / data.length;
}
static void         cone_texture(
                    global t_camera *camera,
                    global t_texture *texture,
                    global t_object *object,
                    t_intersection intersection,
                    RT_F *u, RT_F *v)
{
    t_object_cone   data;
    RT_F4           top;
    RT_F4           normal;
    data = *(global t_object_cone* )object->data;
    local_default(&data.top, &data.bottom, &intersection.hit);
    top = projection(intersection.hit, data.top, data.axis);
    normal = normalize(intersection.hit - top);
    if ((data.top - data.bottom).y == 0)
        *u = 0.5 + atan2(normal.y, normal.z) / (2 * RT_PI);
    else
        *u = 0.5 + atan2(normal.z, normal.x) / (2 * RT_PI);
    if (!(dot(normalize(data.bottom - intersection.hit), data.axis) >= -RT_EPSILON
        && dot(normalize(data.bottom - intersection.hit), data.axis) <= RT_EPSILON))
        *v = 1 - length(intersection.hit - data.top) / data.length;
    else
        *v = length(intersection.hit - data.bottom) / data.length;
}

static void         sphere_texture(
					global t_camera *camera,
                    global t_texture *texture,
                    global t_object *object,
                    t_intersection *intersection,
                    RT_F *u, RT_F *v)
{
    t_object_sphere data;
    RT_F4           normal;

    data = *(global t_object_sphere* )object->data;
    normal = normalize(intersection->hit - data.position);

    *u = 0.5 + atan2(normal.z, normal.x) / (2 * _RT_PI);
    *v = 0.5 + asin(normal.y) / _RT_PI;
}

static RT_F         rt_mod(RT_F number, int div)
{
    int             tmp;
    //int             rezus;

    tmp = (int)number;
    if (tmp < 0)
        tmp = -tmp;
    if (tmp > div)
    {
        if (number < 0)
            return ((number + tmp / div * div));
        else
            return ((number - tmp / div * div));
     }
    return (number);
}

static void         plane_texture(
                    global t_texture *texture,
                    global t_object *object,
                    t_intersection *intersection,
                    RT_F *u, RT_F *v)
{
    t_object_plane   data;
    RT_F4            vector;

    data = *(global t_object_plane* )object->data;
    vector = intersection->hit - data.position;
    if (!(data.normal.z == 1 || data.normal.z == -1))
    {
        vector = f4_rotate(vector, rt_rotation_x, rt_rotation_positive, acos(-data.normal.x));
        vector = f4_rotate(vector, rt_rotation_y, rt_rotation_positive, acos(-data.normal.y));
    }
    *u = rt_mod(vector.x, texture->width[object->texture_id]);
    if ((*u /= texture->width[object->texture_id]) < 0)
        *u += 1;
    *v = rt_mod(vector.y, (int)texture->height[object->texture_id]);
    if ((*v /= texture->height[object->texture_id]) < 0)
        *v += 1;

    if (*u <= 0.5)
        *u += 0.5;
    else
        *u -= 0.5;
    if (*v <= 0.5)
        *v += 0.5;
    else
        *v -= 0.5;
}

static RT_F4		object_texture(
					global t_texture *texture,
					global t_camera *camera,
					global t_object *object,
					t_intersection *intersection)
{
	RT_F            u;
    RT_F            v;

	if (object->type == object_type_sphere)
            sphere_texture(camera, texture, object, intersection, &u, &v);
	else if (object->type == object_type_cone)
		cone_texture(camera, texture, object, *intersection, &u, &v);
	else if (object->type == object_type_cylinder)
		cylinder_texture(camera, texture, object, *intersection, &u, &v);
	else if (object->type == object_type_plane)
		plane_texture(texture, object, intersection, &u, &v);
	return (get_color_from_texture(texture, object->texture_id, &u, &v));
}
// cl_object_normal ////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

static RT_F4		object_normal_rm(global t_object *object, t_intersection *intersection)
{
	t_intersection	normal_intersection;
	RT_F4			nudged_hit;
	RT_F4			normal;
	RT_F4			normal_negative;
	RT_F4			nudge;

	nudge = (RT_F4){RT_RM_NORMAL_EPSILON, 0., 0., 0.};
	nudged_hit = intersection->hit + nudge;
	normal_intersection.hit = nudged_hit;
	normal.x = object_sdf(object, &normal_intersection);
	nudged_hit = intersection->hit - nudge;
	normal_intersection.hit = nudged_hit;
	normal_negative.x = object_sdf(object, &normal_intersection);
	normal.x -= normal_negative.x;

	nudge = (RT_F4){0., RT_RM_NORMAL_EPSILON, 0., 0.};
	nudged_hit = intersection->hit + nudge;
	normal_intersection.hit = nudged_hit;
	normal.y = object_sdf(object, &normal_intersection);
	nudged_hit = intersection->hit - nudge;
	normal_intersection.hit = nudged_hit;
	normal_negative.y = object_sdf(object, &normal_intersection);
	normal.y -= normal_negative.y;

	nudge = (RT_F4){0., 0., RT_RM_NORMAL_EPSILON, 0.};
	nudged_hit = intersection->hit + nudge;
	normal_intersection.hit = nudged_hit;
	normal.z = object_sdf(object, &normal_intersection);
	nudged_hit = intersection->hit - nudge;
	normal_intersection.hit = nudged_hit;
	normal_negative.z = object_sdf(object, &normal_intersection);
	normal.z -= normal_negative.z;

    return (normalize(normal));
}

static RT_F4		object_normal_rt(
					global t_object *object,
                    t_intersection *intersection)
{
	if (object->type == object_type_sphere)
		return (object_sphere_normal(object, intersection));
	else if (object->type == object_type_plane)
		return (object_plane_normal(object, intersection));
	else if (object->type == object_type_cone)
	    return (object_cone_normal(object, intersection));
	else if (object->type == object_type_cylinder)
	    return (object_cylinder_normal(object, intersection));
	else if (object->type == object_type_box)
		return (object_box_normal(object, intersection));
	else if (object->type == object_type_paraboloid)
		return (object_paraboloid_normal(object, intersection));
	else if (object->type == object_type_moebius)
		return (object_moebius_normal(object, intersection));
 	return (intersection->normal);
}

static RT_F4		object_normal(
					global t_object *object,
					t_intersection *intersection,
					constant t_rt_settings *settings)
{
	return (settings->tracing_mod == rt_tracing_rt ?
		object_normal_rt(object, intersection) :
		object_normal_rm(object, intersection));
}
// cl_scene_x //////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef enum 		e_rt_background
{
	rt_background_none,
	rt_background_one,
	rt_background_interpolation,
	rt_background_end
}					t_rt_background;

typedef struct		s_scene
{
	t_object		objects[RT_SCENE_CAPACITY];
	int				objects_length;
	int				lights[RT_SCENE_CAPACITY];
	int 			lights_length;
	t_texture		texture;
	const uchar		param_a[16];
	int				selected_id;
	t_rt_background	background;
	RT_F4			background_color;
}					t_scene;

static int			scene_intersect_rt(global t_scene *scene, t_intersection *intersection)
{
	int				result;

    result = 0;
    for (int object_i = 0; object_i < scene->objects_length; object_i++)
		result += object_intersect(scene->objects + object_i, intersection);
    return (result != 0);
}

static int			scene_intersect_rm(
					global t_scene *scene,
                    t_intersection *intersection,
                    constant t_rt_settings *settings)
{
	RT_F			temp_distance;
	RT_F			current_distance;

	intersection->ray.t = 0.;
	intersection->hit = intersection->ray.origin + intersection->ray.direction * 10 * RT_EPSILON;
	for (int step = 0; step < settings->rm_step_limit; step++)
    {
    	current_distance = RT_INFINITY;
    	for (int object_i = 0; object_i < scene->objects_length; object_i++)
		{
			temp_distance = object_sdf(scene->objects + object_i, intersection);
			if (temp_distance < current_distance)
			{
				current_distance = temp_distance;
				intersection->object_id = object_i;
			}
		}
    	if (current_distance < RT_RM_EPSILON)
		{
			if (intersection->ray.t < RT_RM_EPSILON)
			{
				intersection->ray.t = RT_INFINITY;
				return (0);
			}
			return (1);
		}
    	intersection->ray.t += current_distance;
		intersection->hit += intersection->ray.direction * current_distance * settings->rm_step_part;
    	if (intersection->ray.t > settings->rm_max_distance)
    		return (0);
    }
    return (0);
}

static int			scene_intersect(
					global t_scene *scene,
					global t_camera *camera,
					t_intersection *intersection,
					constant t_rt_settings *settings)
{
	int				result;

	intersection_reset(intersection);
	if (settings->tracing_mod == rt_tracing_rt)
		result = scene_intersect_rt(scene, intersection);
	else if (settings->tracing_mod == rt_tracing_rm)
    	result = scene_intersect_rm(scene, intersection, settings);
    else
    	return (0);

	if (result)
	{

		if (settings->tracing_mod == rt_tracing_rt)
			intersection->hit = ray_intersect(&intersection->ray);

		intersection->material = scene->objects[intersection->object_id].material;

		if (scene->objects[intersection->object_id].type == object_type_csg)
			intersection->material = scene->objects[((constant t_object_csg *)scene->objects[intersection->object_id].data)->positive_id].material;
		else if (scene->objects[intersection->object_id].type == object_type_explosion)
        	object_explosion_build_material(scene->objects + intersection->object_id, intersection);

		if (scene->objects[intersection->object_id].texture_id != -1)
			intersection->material.color = object_texture(&scene->texture, camera, scene->objects + intersection->object_id, intersection);

		intersection->normal = object_normal(scene->objects + intersection->object_id, intersection, settings);

}
	return (result);
}

static int			scene_intersect_force(
					global t_scene *scene,
					int object_id,
					global t_camera *camera,
					t_intersection *intersection,
					constant t_rt_settings *settings)
{
	int				result;

	intersection_reset(intersection);
	if (settings->tracing_mod == rt_tracing_rt)
		result = object_intersect(scene->objects + object_id, intersection);
    else
    	return (0);

	if (result)
	{

		if (settings->tracing_mod == rt_tracing_rt)
			intersection->hit = ray_intersect(&intersection->ray);

		if (scene->objects[intersection->object_id].type == object_type_csg)
			intersection->object_id = ((t_object_csg *)scene->objects[intersection->object_id].data)->positive_id;
		intersection->material = scene->objects[intersection->object_id].material;
		if (scene->objects[intersection->object_id].type == object_type_explosion)
        			object_explosion_build_material(scene->objects + intersection->object_id, intersection);

		if (scene->objects[intersection->object_id].texture_id != -1)
			intersection->material.color = object_texture(&scene->texture, camera, scene->objects + intersection->object_id, intersection);
		intersection->normal = object_normal(scene->objects + intersection->object_id, intersection, settings);
	}
	return (result);
}
// cl_sample_x /////////////////////////////////////////////////////////////////////////////////////////////////////////

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
	sin_theta = RT_SQRT(RT_MAX((RT_F)0.0f , (RT_F)1.0f - r[0] * r[0]));
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
// cl_light_basic //////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

typedef struct			s_object_light_ambient
{
}						t_object_light_ambient;

typedef struct			s_object_light_point
{
	RT_F4				position;
}						t_object_light_point;

typedef struct			s_object_light_direct
{
	RT_F4				direction;
}						t_object_light_direct;

static RT_F4			static_get_direction(
						t_intersection *intersection,
						global t_object *object)
{
	if (object->type == object_type_light_direct)
		return (((constant t_object_light_direct *)object->data)->direction * (RT_F)-1.);
	else if (object->type == object_type_light_point)
		return (((constant t_object_light_point *)object->data)->position - intersection->hit);
	return (0.);
}

static RT_F4			static_get_diffuse_intensity
						(t_intersection *intersection,
						RT_F4 *light_direction)
{
    RT_F	          		dot_value;

	dot_value = dot(*light_direction, intersection->normal);
	if (dot_value > 0.)
		return (dot_value / length(*light_direction));
	return (0.);
}

static RT_F4            static_get_specular_intensity
						(t_intersection *intersection,
						RT_F4 *light_direction)
{
	RT_F4            	halfway;
    RT_F	          	dot_value;

	halfway = normalize(*light_direction + intersection->ray.direction);
	dot_value = dot(halfway, intersection->normal);
	if (dot_value > 0.)
		return (RT_POW(dot_value, RT_LIGHT_BASIC_BLINN));
	return (0.);

}

static RT_F4			static_get_cartoon_intensity
		(t_intersection *intersection,
		 RT_F4 *light_direction)
{
	RT_F	          	dot_value;
	RT_F                intensity;

	dot_value = dot(*light_direction, intersection->normal);
	if (dot_value > 0.)
	{
		if ((intensity = dot_value / length(*light_direction)) > (RT_F)0.7)
			return ((RT_F)0.6);
		else if (intensity > (RT_F)0.3)
			return ((RT_F)0.4);
		else
			return ((RT_F)0.3);
	}
	return ((RT_F)0.2);
}

static int				static_is_shadowed(
						global t_scene *scene,
						global t_camera *camera,
						t_intersection *intersection,
						constant t_rt_settings *settings,
						RT_F4 *light_direction,
						RT_F *shadow_ratio)
{
	t_intersection   	shadow;
	const RT_F			default_transparence_shadow_ratio = 1.3;

	intersection_reset(&shadow);
	shadow.ray.origin = intersection->hit;
	shadow.ray.direction = normalize(*light_direction);
	if (!scene_intersect(scene, camera, &shadow, settings))
		return (0);
	if (shadow.material.transparency)
		*shadow_ratio = default_transparence_shadow_ratio + shadow.material.transparency;
	return (shadow.ray.t >= RT_EPSILON && shadow.ray.t <= length(*light_direction));
}

static RT_F4			light_basic(
						global t_scene *scene,
						global t_camera *camera,
						t_intersection *intersection,
						constant t_rt_settings *settings,
						int filter_cartoon_mod)
{
	global t_object		*object;
	RT_F4				color_diffuse;
	RT_F4				color_specular;
	RT_F4				color_cartoon;
	RT_F4				light_direction;
	RT_F				shadow_ratio;

	color_diffuse = 0.;
	color_specular = 0.;
	color_cartoon = 0.;
	shadow_ratio = 1.;
	for (int i = 0; i < scene->lights_length; i++)
	{
		object = scene->objects + scene->lights[i];
		if (object->type == object_type_light_ambient)
		{
			color_diffuse += object->material.emission;
			continue ;
		}
		light_direction = static_get_direction(intersection, object);
		if (static_is_shadowed(scene, camera, intersection, settings, &light_direction, &shadow_ratio))
		{
			color_diffuse *= (RT_F4){shadow_ratio, shadow_ratio, shadow_ratio, 0.};
			continue;
		}
		if (filter_cartoon_mod)
			color_cartoon += object->material.emission * static_get_cartoon_intensity(intersection, &light_direction);
		else
		{
			color_diffuse += object->material.emission *static_get_diffuse_intensity(intersection, &light_direction);
			color_specular += static_get_specular_intensity(intersection, &light_direction);
		}
	}
	if (filter_cartoon_mod)
		return (intersection->material.color * color_cartoon);
	return (intersection->material.color * color_diffuse + (RT_F4){1., 1., 1., 1.} * intersection->material.specular * color_specular);
}
// cl_light_area ///////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

static RT_F4		light_area(
					global t_scene *scene,
					global t_camera *camera,
					t_intersection *intersection_object,
					constant t_rt_settings *settings,
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
	RT_F			shadow_ratio;

	radiance = 0;
	shadow_ratio = 0.;
	for (int i = 0; i < scene->objects_length; i++)
	{
 		if (i == intersection_object->object_id)
			continue ;
		if (scene->objects[i].type != object_type_sphere)
			continue ;
		if (f4_max_component(scene->objects[i].material.emission) == 0.f)
			continue ;

		light_position = object_sphere_random(scene->objects + i, rng_state);
		light_direction = normalize(light_position - intersection_object->hit);

		intersection_light.ray.origin = intersection_object->hit;
		intersection_light.ray.direction = light_direction;

		if (!scene_intersect(scene, camera, &intersection_light, settings))
			continue ;

		shadow_ratio = (RT_F)1.;

		if (intersection_light.object_id != i && intersection_light.material.transparency > RT_EPSILON)
        {
        	shadow_ratio = intersection_light.material.transparency;
        	if (!scene_intersect_force(scene, i, camera, &intersection_light, settings))
        		continue ;
        }
        else if (intersection_light.object_id != i)
        	continue ;

		emission_intensity = dot(intersection_object->normal, intersection_light.ray.direction);
		if (emission_intensity < 0.00001f)
			continue ;

		sphere_radius = ((constant t_object_sphere *)scene->objects[intersection_light.object_id].data)->radius;
		cos_a_max = RT_SQRT(1.f - (sphere_radius * sphere_radius) / length(intersection_object->hit - light_position));
		omega = 2 * RT_PI * (1.f - cos_a_max);
		radiance += shadow_ratio * scene->objects[i].material.emission * emission_intensity * omega * RT_1_PI;
	}
	return (RT_MAX(RT_MIN(RT_LIGHT_AREA_MULTIPLIER * radiance, RT_LIGHT_AREA_CEILING), RT_LIGHT_AREA_FLOOR));
}

// cl_filter ///////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef enum		e_cl_stereo_type
{
	cl_stereo_type_a,
	cl_stereo_type_b
}					t_cl_stereo_type;

static RT_F4		filter_stereo(RT_F4 radiance, t_cl_stereo_type type)
{
	if (type == cl_stereo_type_a)
		return ((RT_F4){0., radiance.y, radiance.z, 1.});
	else if (type == cl_stereo_type_b)
		return ((RT_F4){radiance.x, 0., 0., 1.});
	return ((RT_F4)0);
}

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

static void			camera_focus(global t_camera *camera, t_ray *ray, global ulong *rng_state)
{
	RT_F4			focal_point;

	focal_point = camera->position + ray->direction * camera->focal_length;

	ray->origin.x += (.5 - rng(rng_state)) * camera->aperture_size;
	ray->origin.y += (.5 - rng(rng_state)) * camera->aperture_size;
	ray->origin.z += (.5 - rng(rng_state)) * camera->aperture_size;

	ray->direction = normalize(focal_point - ray->origin);
}

static RT_F4		camera_build_vp_point(global t_camera *camera, RT_F x, RT_F y)
{
	RT_F4			up;
	RT_F4			right;

	up = (RT_F4)camera->axis_y * (RT_F)(-1.f * y + (camera->height - 1.f) / 2.f);
	right = (RT_F4)camera->axis_x * (RT_F)(x - (camera->width - 1.f) / 2.f);
	return (up + right + camera->forward);
}

static t_ray		camera_build_ray_raw(global t_camera *camera, RT_F x, RT_F y)
{
	t_ray			result;

	result.origin = camera->position;
    result.direction = normalize(camera_build_vp_point(camera, x, y));
    return (result);
}

static t_ray		camera_build_ray(global t_camera *camera, int2 *screen, global ulong *rng_state)
{
	t_ray			result;
	RT_F 			xf;
	RT_F 			yf;

	xf = (RT_F)screen->x;
	yf = (RT_F)screen->y;
	if (camera->filter_antialiasing)
	{
		filter_jitter(&xf, rng_state);
    	filter_jitter(&yf, rng_state);
	}
	result = camera_build_ray_raw(camera, xf, yf);
	if (camera->focus)
		camera_focus(camera, &result, rng_state);
	return (result);
}

static void			camera_auto_focus(global t_camera *camera, global t_scene *scene, constant t_rt_settings *settings)
{
    t_intersection	intersection;

    intersection.ray = camera_build_ray_raw(camera, camera->request_value.x, camera->request_value.y);
    if (scene_intersect(scene, camera, &intersection, settings))
    	camera->focal_length = intersection.ray.t + object_center_shift(scene->objects + intersection.object_id);
}

static void			camera_select(global t_camera *camera, global t_scene *scene, constant t_rt_settings *settings)
{
    t_intersection	intersection;

	camera->select_request_object = -1;
    intersection.ray = camera_build_ray_raw(camera, camera->request_value.x, camera->request_value.y);

    if (scene_intersect(scene, camera, &intersection, settings))
    	camera->select_request_object = intersection.object_id;
}
 // cl_illumination_get ////////////////////////////////////////////////////////////////////////////////////////////////

static RT_F4					illumination(
 								global t_scene *scene,
 								global t_camera *camera,
 								t_intersection *intersection,
 								constant t_rt_settings *settings)
{
	t_object_sphere				sphere;
	RT_F						x;
	RT_F4						k;
	RT_F4						illumination;
	t_intersection              shadow;

	illumination = 0.;

	for (int i = 0; i < scene->objects_length; i++)
	{
		if (scene->objects[i].is_visible == rt_false)
        	continue ;
		if (scene->objects[i].is_selected == rt_true)
        	continue ;
        if (scene->objects[i].type != object_type_sphere)
			continue ;
		if (f4_max_component(scene->objects[i].material.emission) == (RT_F)0.f)
        	continue ;

		if (scene->objects[i].type == object_type_sphere)
		{
			sphere = *(global t_object_sphere *)scene->objects[i].data;

			k = normalize(intersection->ray.direction - normalize(sphere.position - intersection->ray.origin));
			x = dot(intersection->ray.origin - sphere.position, k) + sphere.radius;

			if (x < sphere.radius)
				continue;
		}

		shadow.ray.origin = sphere.position;
		shadow.ray.direction = normalize(camera->position - sphere.position);
		shadow.ray.origin += shadow.ray.direction;

		intersection_reset(&shadow);
		if (scene_intersect(scene, camera, &shadow, settings) && shadow.ray.t < length(camera->position - shadow.ray.origin))
			continue;

		illumination += RT_POW((RT_F)(settings->illumination_value * sphere.radius / x), RT_ILLUMINATION_POWER) * scene->objects[i].material.emission;
 	}
 	return (illumination);
 }

// cl_radiance /////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "rt_parameters.h"

static void					radiance_write(
							global RT_F4 *sample_store[RT_SAMPLE_ARRAY_LENGTH],
							int global_id,
							RT_F4 radiance,
							constant t_rt_settings *settings)
{
	if (!settings->motion_blur)
	{
		if (settings->sample_count == 1)
				sample_store[RT_SAMPLE_ARRAY_LENGTH - 1][global_id] = radiance;
		else
				sample_store[RT_SAMPLE_ARRAY_LENGTH - 1][global_id] += radiance;
	}
	else
	{
		if (settings->motion_blur_sample_count == 1)
		{
			for (int i = 0; i < RT_SAMPLE_ARRAY_LENGTH - 1; i++)
				sample_store[i][global_id] = 0.;
        }
        for (int i = 0; i < RT_SAMPLE_ARRAY_LENGTH - 1; i++)
        	sample_store[i][global_id] = sample_store[i + 1][global_id];
        sample_store[RT_SAMPLE_ARRAY_LENGTH - 1][global_id] = radiance;
	}
}

static RT_F4				radiance_read(
							global RT_F4 *sample_store[RT_SAMPLE_ARRAY_LENGTH],
							int global_id,
							constant t_rt_settings *settings)
{
	RT_F4					sum;
	RT_F4					alpha;
	int						i;
	int						count;

	if (!settings->motion_blur)
		return (sample_store[RT_SAMPLE_ARRAY_LENGTH - 1][global_id] / settings->sample_count);
	else
	{
		sum = 0.;
		alpha = 1.;
		i = 0;
		count = 0;
		for (i = RT_SAMPLE_ARRAY_LENGTH - 1; i > -1 && count < settings->motion_blur_sample_count; i--, count++)
       	{
       		sum  += sample_store[i][global_id];
       		alpha *= RT_MOTION_BLUR_ALPHA;
       	}
       	return (sum / settings->motion_blur_sample_count);
	}
}

# define RT_CHOICE_DIFFUSE	0
# define RT_CHOICE_REFLECT	1
# define RT_CHOICE_REFRACT	2

static RT_F4				radiance_trace(
							global t_scene *scene,
							global t_camera *camera,
							t_intersection *intersection,
							constant t_rt_settings *settings,
							global ulong *rng_state)
{
	RT_F4					radiance;
	RT_F4					light;
	RT_F4					mask;
	RT_F					cosine;
	RT_F					choice_value;
	RT_F					choice_result;

	RT_F4					background_f4;
	RT_F					background_f;

	radiance = (RT_F4){0.f, 0.f, 0.f, 1.f};
	mask = 1;

	for (int depth = 0; depth < settings->sample_depth; depth++)
	{
		if (settings->illumination)
			radiance += illumination(scene, camera, intersection, settings);


		if (!scene_intersect(scene, camera, intersection, settings))
		{
			if (scene->background == rt_background_none)
				;
			else if (scene->background == rt_background_one)
				radiance += scene->background_color * mask;
			else if (scene->background == rt_background_interpolation)
			{
				background_f4 = normalize(intersection->ray.direction);
				background_f = (RT_F)0.5 * (background_f4.y + (RT_F)1.0);
				radiance += mix(RT_BACKGROUND_INTER_A, RT_BACKGROUND_INTER_B, background_f) * mask;
			}
			break ;
		}

		if (scene->objects[intersection->object_id].is_selected == rt_true)
			break ;

		if (depth > settings->sample_depth / 2 + 1 && f4_max_component(intersection->material.color) < rng(rng_state))
			break ;

		radiance += mask * intersection->material.emission;

		if (settings->light_mod == rt_light_basic)
		{
			light = light_basic(scene, camera, intersection, settings, camera->filter_mod == rt_filter_cartoon);
			light = RT_MAX(light, settings->light_ambient);
            radiance += light * mask;
		}
		else if (settings->light_mod == rt_light_area)
		{
			light = light_area(scene, camera, intersection, settings, rng_state);
			light = RT_MAX(light, settings->light_ambient);
			radiance += light * mask * intersection->material.color;
		}

		choice_value = rng(rng_state);
		choice_result = RT_CHOICE_DIFFUSE;
		if (intersection->material.reflectance == (RT_F)1. || (intersection->material.reflectance > RT_EPSILON && choice_value < intersection->material.reflectance))
			choice_result = RT_CHOICE_REFLECT;
		else if (intersection->material.transparency == (RT_F)1. || (intersection->material.transparency >RT_EPSILON  && choice_value < intersection->material.transparency))
			choice_result = RT_CHOICE_REFRACT;

		if (choice_result == RT_CHOICE_REFLECT)
		{
			intersection_reflect(intersection, intersection);
			mask /= intersection->material.reflectance;
			depth--;
		}
		else if (choice_result == RT_CHOICE_REFRACT)
		{
			intersection_refract(intersection, intersection);
			mask /= intersection->material.transparency;
			depth--;
		}
		else if (choice_result == RT_CHOICE_DIFFUSE)
		{
		    intersection->ray.origin = intersection->hit;
            intersection->ray.direction = sample_uniform(&intersection->normal, &cosine, rng_state);
            mask *= intersection->material.color * cosine;
		}
	}
	return (radiance);
}
// cl_sample_store /////////////////////////////////////////////////////////////////////////////////////////////////////

static void			sample_store_map(global RT_F4 *sample_store, global RT_F4 *sample_store_mapped[RT_SAMPLE_ARRAY_LENGTH], global t_camera *camera)
{
	for (int i = 0; i < RT_SAMPLE_ARRAY_LENGTH; i++)
		sample_store_mapped[i] = sample_store + i * camera->width * camera->height;
}
// cl_main /////////////////////////////////////////////////////////////////////////////////////////////////////////////

# include "rt_parameters.h"

kernel void			cl_main(
					global t_camera *camera,
					global t_scene *scene,
					global t_color *image,
					global RT_F4 *sample_store,
					constant t_rt_settings *settings,
					global ulong *rng_state)
{
	int				global_id;
	int2			screen;
	global RT_F4	*sample_store_mapped[RT_SAMPLE_ARRAY_LENGTH];

	t_intersection	intersection;
	RT_F4			radiance;

	t_intersection	stereo_intersection;
	RT_F4			stereo_radiance[2];

    global_id = get_global_id(0);
	sample_store_map(sample_store, sample_store_mapped, camera);

	if (camera->select_request)
	{
		if (!global_id)
			camera_select(camera, scene, settings);
		return ;
	}

	if (camera->focus_request)
	{
		if (!global_id)
			camera_auto_focus(camera, scene, settings);
		return ;
	}

	screen.x = global_id % camera->width;
	screen.y = global_id / camera->width;

	intersection.ray = camera_build_ray(camera, &screen, rng_state);

	radiance = radiance_trace(scene, camera, &intersection, settings, rng_state);

	if (camera->filter_mod == rt_filter_stereo)
	{
		stereo_intersection.ray = camera_build_ray(camera, &screen, rng_state);
		stereo_intersection.ray.origin.x += 1;
		stereo_radiance[0] = filter_stereo(radiance, cl_stereo_type_a);
        stereo_radiance[1] = radiance_trace(scene, camera, &stereo_intersection, settings, rng_state);
        stereo_radiance[1] = filter_stereo(stereo_radiance[1], cl_stereo_type_b);
        radiance = stereo_radiance[0] + stereo_radiance[1];
	}

	radiance_write(sample_store_mapped, global_id, radiance, settings);
	image[global_id] = color_unpack(radiance_read(sample_store_mapped, global_id, settings), camera->filter_mod == rt_filter_sepia);
}


