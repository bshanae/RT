#define CONST           constant
#define BLINN           60.f

// /////////////////////////////////////////////////////////////////////////////
//						VECTOR3
// /////////////////////////////////////////////////////////////////////////////

typedef struct		    s_vector3
{
	float				x;
	float				y;
	float				z;
}					    t_vector3;

static float	      vector3_length(const t_vector3 *me)
{
	return (sqrt(me->x * me->x + me->y * me->y + me->z * me->z));
}

static float	      vector3_s_length(const t_vector3 me)
{
	return (sqrt(me.x * me.x + me.y * me.y + me.z * me.z));
}

static void				vector3_normalize(t_vector3 *me)
{
	float				    length;

	length = vector3_length(me);
	me->x /= length;
	me->y /= length;
	me->z /= length;
}

static t_vector3        vector3_s_normalize(t_vector3 me)
{
	float				    length;

	length = vector3_length(&me);
	me.x /= length;
	me.y /= length;
	me.z /= length;
	return (me);
}

static t_vector3		vector3_normalized(const t_vector3 *me)
{
	t_vector3		    result;

	result = *me;
	vector3_normalize(&result);
	return (result);
}

static float	 			vector3_dot(const t_vector3 *v1, const t_vector3 *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

static float	 			vector3_s_dot(t_vector3 v1, t_vector3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}


static t_vector3	    vector3_cross(const t_vector3 *v1, const t_vector3 *v2)
{
	t_vector3		    result;

	result.x = v1->y * v2->z - v1->z * v2->y;
	result.y = v1->z * v2->x - v1->x * v2->z;
	result.z = v1->x * v2->y - v1->y * v2->x;
	return (result);
}

static t_vector3		vector3_s_cross(t_vector3 v1, t_vector3 v2)
{
	t_vector3		    result;

	result.x = v1.y * v2.z - v1.z * v2.y;
	result.y = v1.z * v2.x - v1.x * v2.z;
	result.z = v1.x * v2.y - v1.y * v2.x;
	return (result);
}

static t_vector3	    vector3_sub(t_vector3 *v1, t_vector3 *v2)
{
	t_vector3		    result;

	result.x = v1->x - v2->x;
	result.y = v1->y - v2->y;
	result.z = v1->z - v2->z;
	return (result);
}

static t_vector3		vector3_s_sub(t_vector3 v1, t_vector3 v2)
{
	t_vector3		    result;

	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return (result);
}

static void				vector3_sub_eq(t_vector3 *v1, const t_vector3 *v2)
{
	v1->x -= v2->x;
	v1->y -= v2->y;
	v1->z -= v2->z;
}

static void			    vector3_s_sub_eq(t_vector3 *v1, t_vector3 v2)
{
	v1->x -= v2.x;
	v1->y -= v2.y;
	v1->z -= v2.z;
}


static t_vector3		vector3_add(const t_vector3 *v1, const t_vector3 *v2)
{
	t_vector3		    result;

	result.x = v1->x + v2->x;
	result.y = v1->y + v2->y;
	result.z = v1->z + v2->z;
	return (result);
}

static t_vector3		vector3_s_add(t_vector3 v1, t_vector3 v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

static void				vector3_add_eq(t_vector3 *v1, const t_vector3 *v2)
{
	v1->x += v2->x;
	v1->y += v2->y;
	v1->z += v2->z;
}

static void			    vector3_s_add_eq(t_vector3 *v1, t_vector3 v2)
{
	v1->x += v2.x;
	v1->y += v2.y;
	v1->z += v2.z;
}

static t_vector3		vector3_mul(const t_vector3 *v1, float	 k)
{
	t_vector3		    result;

	result.x = v1->x * k;
	result.y = v1->y * k;
	result.z = v1->z * k;
	return (result);
}

static t_vector3		vector3_s_mul(t_vector3 v1, float	 k)
{
	v1.x *= k;
	v1.y *= k;
	v1.z *= k;
	return (v1);
}

static void			    vector3_mul_eq(t_vector3 *v1, float	 k)
{
	v1->x = v1->x * k;
	v1->y = v1->y * k;
	v1->z = v1->z * k;
}

static t_vector3		vector3_div(const t_vector3 *v1, float	 k)
{
	t_vector3		    result;

	result.x = v1->x / k;
	result.y = v1->y / k;
	result.z = v1->z / k;
	return (result);
}

static t_vector3		vector3_s_div(t_vector3 v1, float	 k)
{
	t_vector3		    result;

	result.x = v1.x / k;
	result.y = v1.y / k;
	result.z = v1.z / k;
	return (result);
}

static void				vector3_div_eq(t_vector3 *v1, float	 k)
{
	v1->x = v1->x / k;
	v1->y = v1->y / k;
	v1->z = v1->z / k;
}

static float				*vector3_iter(t_vector3 *me, int i)
{
	if (i < 0 || i > 3)
		return (0);
	return (&me->x + i);
}

static void				vector3_rotate_x(t_vector3 *me, float	 theta)
{
	t_vector3		    copy;

	copy = *me;
	me->y = copy.y * cosf(theta) + copy.z * sinf(theta);
	me->z = -1 * copy.y * sinf(theta) + copy.z * cosf(theta);
}

static void				vector3_rotate_y(t_vector3 *me, float	 theta)
{
	t_vector3		    copy;

	copy = *me;
	me->x = copy.x * cosf(theta) + copy.z * sinf(theta);
	me->z = -1 * copy.x * sinf(theta) + copy.z * cosf(theta);
}

// /////////////////////////////////////////////////////////////////////////////
//						COLOR
// /////////////////////////////////////////////////////////////////////////////

typedef struct			s_rgb
{
	unsigned char		b;
	unsigned char		g;
	unsigned char		r;
	unsigned char		a;
}						t_rgb;

typedef union			u_color
{
	int					mix;
	t_rgb				rgb;
}						t_color;

static int              cl_color_unpack(t_vector3 vector)
{
    t_color             color;
	float	 	    *ptr;
	int 			    counter;
	float	 	    left;

	ptr = &vector.x;
	counter = 0;
	left = 0.;
	while (counter++ < 3)
	{
		if (*ptr > 1.)
		{
			left += *ptr - 1.;
			*ptr = 1.;
		}
		ptr++;
	}
	color.rgb.a = 0;
    color.rgb.r = (unsigned char)(255. * vector.x);
    color.rgb.g = (unsigned char)(255. * vector.y);
    color.rgb.b = (unsigned char)(255. * vector.z);
    return (color.mix);
}

// /////////////////////////////////////////////////////////////////////////////
//						RAY
// /////////////////////////////////////////////////////////////////////////////

# define RAY_T_MIN	    0.001
# define RAY_T_MAX	    INFINITY

typedef	struct		    s_ray
{
	t_vector3		    origin;
	t_vector3		    direction;
	float	 		t;
}					    t_ray;

static t_vector3		ray_intersect(const t_ray *me)
{
	t_vector3		    tmp;

	tmp = vector3_mul(&me->direction, me->t);
	return (vector3_add(&me->origin, &tmp));
}

// /////////////////////////////////////////////////////////////////////////////
//						LIGHT
// /////////////////////////////////////////////////////////////////////////////

typedef enum		    e_light_type
{
	light_ambient,
	light_point,
	light_directional
}					    t_light_type;

typedef	struct 		    s_light
{
	t_light_type	    type;
	float				    intensity;
	t_vector3		    vector;
}					    t_light;

// /////////////////////////////////////////////////////////////////////////////
//						MATERIAL
// /////////////////////////////////////////////////////////////////////////////

typedef struct 		    s_material
{
	t_vector3		    color;
	float	 	    diffuse;
	float	 	    specular;
	float	 	    reflect;
	float	 	    refract;
}					    t_material;

// //////////////////////////////////////////////////////////////////////////////
//						SHAPE
// //////////////////////////////////////////////////////////////////////////////

typedef	struct 			s_shape_cl
{
	int 				function_index;
	const t_material	material;
	int					highlight;
}						t_shape_cl;


// /////////////////////////////////////////////////////////////////////////////
//						INTERSECTION
// /////////////////////////////////////////////////////////////////////////////

typedef struct			s_intersection_cl
{
	t_ray				ray;
	t_vector3			normal;
	float	         diffuse_intensity;
	float	         specular_intensity;
	t_vector3           color;
	t_material			material;
	float	 		shadow_ratio;
	int 				highlight;
}						t_intersection_cl;

static void				cl_intersection_reset(t_intersection_cl *me)
{
	me->ray.t = RAY_T_MAX;
	me->diffuse_intensity = 0.;
	me->specular_intensity = 0.;
	me->shadow_ratio = 1.;
}

static t_vector3        intersection_light_direction
                        (t_intersection_cl *intersection,
                        constant t_light *light)
{
	t_vector3           temp[3];

	if (light->type == light_directional)
		temp[0] = light->vector;
	else if (light->type == light_point)
	{
		temp[1] = ray_intersect(&intersection->ray);
		temp[2] = light->vector;
		temp[0] = vector3_sub(temp + 2, temp + 1);
	}
	return (temp[0]);
}

// /////////////////////////////////////////////////////////////////////////////
//						SPHERE
// /////////////////////////////////////////////////////////////////////////////

typedef struct 			s_sphere_data
{
	t_vector3			center;
	float	 		radius;
}						t_sphere_data;

static int     			cl_sphere_intersect
						(constant t_shape_cl *shape,
						constant void *data_ptr,
						t_intersection_cl *intersection)
{
	CONST t_sphere_data *ptr;
	t_sphere_data		data;
float	 		k[3];
float	 		t;
float	 	    discriminant;
	t_vector3			temp;

    ptr = (constant t_sphere_data *)data_ptr;
    data.center = ptr->center;
    data.radius = ptr->radius;
	k[0] = vector3_dot(&intersection->ray.direction, &intersection->ray.direction);
	temp = vector3_sub(&intersection->ray.origin, &data.center);
	k[1] = 2 * vector3_dot(&temp, &intersection->ray.direction);
	k[2] = vector3_dot(&temp, &temp) - data.radius * data.radius;
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant < 0.)
		return (0);
	t = (-k[1] - sqrt(discriminant)) / (2 * k[0]);
	if (t <= RAY_T_MIN || t >= intersection->ray.t)
		return (0);
	intersection->ray.t = t;
	temp = ray_intersect(&intersection->ray);
	intersection->normal = vector3_sub(&temp, &data.center);
	vector3_normalize(&intersection->normal);
	intersection->color = shape->material.color;
	intersection->material = shape->material;
	intersection->highlight = shape->highlight;
	return (1);
}

// /////////////////////////////////////////////////////////////////////////////
//						PLANE
// /////////////////////////////////////////////////////////////////////////////

typedef struct 			s_plane_data
{
	t_vector3			position;
	t_vector3			normal;
}						t_plane_data;

static int 			    cl_plane_intersect
	                    (constant t_shape_cl *shape,
	                    constant void *data_ptr,
	                    t_intersection_cl *intersection)
{
	t_plane_data	    *data;
	t_vector3		    temp[2];
	float	 	    	value[3];

	data = (t_plane_data *)data_ptr;
	if (!(value[0] = vector3_dot(&intersection->ray.direction, &data->normal)))
		return (0);
	temp[0] = vector3_sub(&data->position, &intersection->ray.origin);
	value[1] = vector3_dot(temp, &data->normal) / value[0];
	if (value[1] <= RAY_T_MIN || value[1] >= intersection->ray.t)
		return (0);
	intersection->ray.t = value[1];
	intersection->normal = data->normal;
	intersection->color = shape->material.color;
	intersection->material = shape->material;
	intersection->highlight = shape->highlight;
	return (1);
}

// /////////////////////////////////////////////////////////////////////////////
//						CYLINDER
// /////////////////////////////////////////////////////////////////////////////

typedef struct 			s_cylinder_data
{
	t_vector3			top;
	t_vector3			bottom;
	float 				radius;
	t_vector3			axis;
}						t_cylinder_data;

static float			cl_cylinder_caps_intersect
						(constant t_shape_cl *shape,
						constant void *data_ptr,
						t_intersection_cl *intersection)
{
	t_cylinder_data		*data;
	float				t[2];

	data = (t_cylinder_data *)data_ptr;
	if (!vector3_dot(&intersection->ray.direction, &data->axis))
		return (INFINITY);
	t[0] = vector3_s_dot(vector3_sub(&data->top, &intersection->ray.origin), data->axis) / vector3_dot(&intersection->ray.direction, &data->axis);
	if (t[0] <= RAY_T_MIN)
		return (INFINITY);
	if (vector3_s_length(vector3_s_sub(data->top, vector3_s_add(intersection->ray.origin, vector3_mul(&intersection->ray.direction, t[0])))) < data->radius)
		intersection->normal = data->axis;
	else
		t[0] = INFINITY;
	t[1] = vector3_s_dot(vector3_sub(&data->bottom, &intersection->ray.origin), data->axis) / vector3_dot(&intersection->ray.direction, &data->axis);
	if (t[1] <= RAY_T_MIN)
		return (INFINITY);
	if (vector3_s_length(vector3_s_sub(data->bottom, vector3_s_add(intersection->ray.origin, vector3_mul(&intersection->ray.direction, t[1])))) < data->radius && t[1] < t[0])
		intersection->normal = vector3_mul(&data->axis, -1);
	else
		return (t[0]);
	return (t[1]);
}

static int				cl_cylinder_intersect
						(constant t_shape_cl *shape,
						constant void *data_ptr,
						t_intersection_cl *intersection)
{
	t_cylinder_data		*data;
	float				k[3];
	float				discriminant;
	float				t[2];
	t_vector3			temp[2];
	float				angle[2];

	data = (t_cylinder_data *)data_ptr;
	temp[0] = vector3_sub(&intersection->ray.origin, &data->bottom);
	k[0] = vector3_dot(&intersection->ray.direction, &intersection->ray.direction) - pow(vector3_dot(&intersection->ray.direction, &data->axis), 2.f);
	k[1] = 2 * (vector3_dot(&intersection->ray.direction, temp) - vector3_dot(&intersection->ray.direction, &data->axis) *  vector3_dot(temp, &data->axis));
	k[2] =  vector3_dot(temp, temp) - pow(vector3_dot(temp, &data->axis), 2.f) - pow(data->radius, 2.f);
	if ((discriminant = k[1] * k[1] - 4 * k[0] * k[2]) < 0.)
		return (0);
	t[0] = (-k[1] - sqrtf(discriminant)) / (2 * k[0]);
	if (t[0] <= RAY_T_MIN || t[0] >= intersection->ray.t)
		return (0);
	temp[0] = vector3_s_add(intersection->ray.origin, vector3_mul(&intersection->ray.direction, t[0]));	// p
	angle[0] = vector3_s_dot(vector3_sub(temp, &data->top), data->axis);
	angle[1] = vector3_s_dot(vector3_sub(temp, &data->bottom), data->axis);
	t[1] = cl_cylinder_caps_intersect(shape, data_ptr, intersection);
	if ((angle[0] > 0. || angle[1] < 0.) && t[1] != INFINITY)
		t[0] = t[1];
	else if (!(angle[0] > 0. || angle[1] < 0.))
	{
		temp[1] = vector3_sub(temp, &data->bottom); // p - b
		intersection->normal = vector3_s_sub(temp[1], vector3_mul(&data->axis, vector3_dot(temp + 1, &data->axis)));
	}
	else
		return (0);
	intersection->ray.t = t[0];
	intersection->color = shape->material.color;
	intersection->material = shape->material;
	intersection->highlight = shape->highlight;
	return (1);
}


// /////////////////////////////////////////////////////////////////////////////
//						AABB
// /////////////////////////////////////////////////////////////////////////////

typedef struct 			s_aabb_data
{
	t_vector3			min;
	t_vector3			max;
}						t_aabb_data;


static int 				cl_aabb_intersect
						(constant t_shape_cl *shape,
						constant void *data_ptr,
						t_intersection_cl *intersection)
{
	t_aabb_data			*data;
	float				inv_dir;
	float 				t[2];
	float 				t_near;
	float 				t_far;
	float 				t_temp;
	int 				i;
	t_vector3			normal;

	normal = (t_vector3){0., 0., 0.};
	data = (t_aabb_data *)data_ptr;
	i = 0;
	t_near = RAY_T_MIN;
	t_far = RAY_T_MAX;
	while (i < 3)
	{
		inv_dir = 1. / *vector3_iter(&intersection->ray.direction, i);
		t[0] = (*vector3_iter(&data->min, i) - *vector3_iter(&intersection->ray.origin, i)) * inv_dir;
		t[1] = (*vector3_iter(&data->max, i) - *vector3_iter(&intersection->ray.origin, i)) * inv_dir;
		if (inv_dir < 0.)
		{
			t_temp = t[0];
			t[0] = t[1];
			t[1] = t_temp;
		}
		if ((t_near = fmaxf(t[0], t_near)) == t[0])
		{
			normal = (t_vector3){0., 0., 0.};
			*vector3_iter(&normal, i) = inv_dir < 0. ? 1. : -1.;
		}
		t_far = fminf(t[1], t_far);
		if (t_far <= t_near)
			return (0);
		i++;
	}
	if (t_near == RAY_T_MIN || t_near >= intersection->ray.t)
		return (0);
	intersection->ray.t = t_near;
	intersection->normal = normal;
	intersection->color = shape->material.color;
	intersection->material = shape->material;
	intersection->highlight = shape->highlight;
	return (1);

}

// /////////////////////////////////////////////////////////////////////////////
//						CONE
// /////////////////////////////////////////////////////////////////////////////

typedef struct 			s_cone_data
{
	t_vector3			top;
	t_vector3			bottom;
	float 				radius;
	float          		tangens;
	t_vector3			axis;
}						t_cone_data;


static float			cl_cone_cap_intersect
						(constant t_shape_cl *shape,
						constant void *data_ptr,
						t_intersection_cl *intersection)
{
	t_cone_data		*data;
	float 			t;

	data = (t_cone_data *)data_ptr;
	if (!vector3_dot(&intersection->ray.direction, &data->axis))
		return (INFINITY);
	t = vector3_s_dot(vector3_sub(&data->bottom, &intersection->ray.origin), data->axis) / vector3_dot(&intersection->ray.direction, &data->axis);
	if (t <= RAY_T_MIN)
		return (INFINITY);
	if (vector3_s_length(vector3_s_sub(data->bottom, vector3_s_add(intersection->ray.origin, vector3_mul(&intersection->ray.direction, t)))) < data->radius)
		intersection->normal = vector3_mul(&data->axis, -1);
	else
		return (INFINITY);
	return (t);

}

int 				cl_cone_intersect
					(constant t_shape_cl *shape,
					constant void *data_ptr,
					t_intersection_cl *intersection)
{
	t_cone_data	    *data;
	float 			k[3];
	float 			discriminant;
	float 			t[2];
	t_vector3		temp[3];
	float 			angle[2];

	data = (t_cone_data *)data_ptr;
	temp[0] = vector3_sub(&intersection->ray.origin, &data->top);
	k[0] = vector3_dot(&intersection->ray.direction, &intersection->ray.direction) - pow(vector3_dot(&intersection->ray.direction, &data->axis), 2.f) * (1 + data->tangens * data->tangens);
	k[1] = 2 * (vector3_dot(temp, &intersection->ray.direction) - (1 + data->tangens * data->tangens) * vector3_dot(&intersection->ray.direction, &data->axis) * vector3_dot(temp, &data->axis));
	k[2] = vector3_dot(temp, temp) - (1 + data->tangens * data->tangens) * pow(vector3_dot(temp, &data->axis), 2.f);
	if ((discriminant = k[1] * k[1] - 4 * k[0] * k[2]) < 0.)
		return (0);
	t[0] = (-k[1] - sqrtf(discriminant)) / (2 * k[0]);
	if (t[0] <= RAY_T_MIN || t[0] >= intersection->ray.t)
		return (0);
	temp[1] = vector3_s_add(intersection->ray.origin, vector3_mul(&intersection->ray.direction, t[0])); // p
	temp[2] = vector3_sub(temp + 1, &data->bottom);
	angle[0] = vector3_s_dot(vector3_sub(temp + 1, &data->top), data->axis);
	angle[1] = vector3_s_dot(vector3_sub(temp + 1, &data->bottom), data->axis);
	int is_inf = (vector3_s_length(temp[2]) > vector3_s_length(vector3_sub(&data->top, &data->bottom)) || vector3_dot(temp + 2, &data->axis) > 0.);
	t[1] = cl_cone_cap_intersect(shape, data_ptr, intersection);
	if (t[1] != INFINITY && is_inf)
		t[0] = t[1];
	else if (!is_inf)
	{
		t[1] = vector3_dot(&intersection->ray.direction, &data->axis) * t[0] + vector3_dot(temp, &data->axis);
		intersection->normal = vector3_s_sub(vector3_s_sub(temp[1], data->top), vector3_s_mul(data->axis, (1 + data->tangens * data->tangens) * t[1]));
		vector3_normalize(&intersection->normal);
	}
	else
		return (0);
	intersection->ray.t = t[0];
	intersection->color = shape->material.color;
	intersection->material = shape->material;
	intersection->highlight = shape->highlight;
	return (1);
}

// /////////////////////////////////////////////////////////////////////////////
//						DISK
// /////////////////////////////////////////////////////////////////////////////

typedef struct 			s_disk_data
{
	t_vector3			position;
	t_vector3			normal;
	float 				radius;
}						t_disk_data;

int 					cl_disk_intersect
						(constant t_shape_cl *shape,
						constant void *data_ptr,
						t_intersection_cl *intersection)
{
	t_disk_data			*data;
	float 				t;

	data = (t_disk_data *)data_ptr;
	if (!vector3_dot(&intersection->ray.direction, &data->normal))
		return (0);
	t = vector3_s_dot(data->normal, vector3_sub(&data->position, &intersection->ray.origin)) / vector3_dot(&intersection->ray.direction, &data->normal);
	if (vector3_s_length(vector3_s_sub(vector3_s_add(intersection->ray.origin, vector3_mul(&intersection->ray.direction, t)), data->position)) > data->radius)
		return (0);
	if (t <= RAY_T_MIN || t >= intersection->ray.t)
		return (0);
	intersection->ray.t = t;
	intersection->normal = data->normal;
	intersection->color = shape->material.color;
	intersection->material = shape->material;
	intersection->highlight = shape->highlight;
	return (1);
}

// /////////////////////////////////////////////////////////////////////////////
//						CAMERA
// /////////////////////////////////////////////////////////////////////////////

typedef struct			s_camera_cl
{
	t_vector3			position;
	t_vector3			direction;
	t_vector3			vp_axis_x;
	t_vector3			vp_axis_y;
}						t_camera_cl;

static t_ray            cl_camera_cast_ray
                        (global t_camera_cl *me,
                        t_vector3 *vp_values)
{
	t_ray		        tmp;
	t_vector3           up;
	t_vector3           right;
	t_vector3	        point;

	right = me->vp_axis_x;
	up = me->vp_axis_y;
	vector3_mul_eq(&right, vp_values->x);
	vector3_mul_eq(&up, vp_values->y);
	point = vector3_add(&right, &up);
	tmp.origin = me->position;
	tmp.direction = me->direction;
	vector3_add_eq(&tmp.direction, &point);
	vector3_normalize(&tmp.direction);
	return (tmp);
}

// /////////////////////////////////////////////////////////////////////////////
//						SCENE
// /////////////////////////////////////////////////////////////////////////////

typedef struct			s_scene_setting
{
	int 				diffuse_light;
	int 				specular_light;
	int 				shadows;
	int 				tshadows;
}						t_scene_setting;

typedef	struct			s_scene_cl
{
	t_vector3       	background;
	t_scene_setting		settings;
	int 				shape_data_element_size;
	int 				shape_type_number;
	int 				shape_number;
	int 				light_number;
}						t_scene_cl;

// /////////////////////////////////////////////////////////////////////////////
//						SCENE INTERSECTION
// /////////////////////////////////////////////////////////////////////////////

#define CALL_INTERSECT(i, shape, ptr, inter, result)                            \
    if (i == 0)                                                                 \
        result += cl_sphere_intersect(shape, ptr, inter);                       \
    else if (i == 1)                                                            \
        result += cl_plane_intersect(shape, ptr, inter);						\
	else if (i == 2)                                                            \
        result += cl_cylinder_intersect(shape, ptr, inter);						\
    else if (i == 3)															\
    	result += cl_aabb_intersect(shape, ptr, inter);							\
	else if (i == 4)															\
    	result += cl_cone_intersect(shape, ptr, inter);							\
	else if (i == 5)															\
    	result += cl_disk_intersect(shape, ptr, inter);

static int 				cl_scene_intersect
                        (constant t_scene_cl *scene,
						constant void *shape_data,
					    constant t_shape_cl *shapes,
					    t_intersection_cl *intersection)
{
	int 				i;
	constant void		*data;
	int 				result;

	i = 0;
	result = 0;
	while (i < scene->shape_number)
	{
		data = shape_data + scene->shape_data_element_size * i;
		CALL_INTERSECT(shapes[i].function_index, shapes + i, data, intersection, result)
		i++;
	}

	return (result != 0);
}

// /////////////////////////////////////////////////////////////////////////////
//						SHADOW
// /////////////////////////////////////////////////////////////////////////////

static int              cl_scene_check_shadow
                        (constant t_scene_cl *scene,
                        constant void *shape_data,
                        constant t_shape_cl *shapes,
                        t_intersection_cl *intersection,
                        t_vector3 *light_direction)
{
	t_intersection_cl   shadow;

	cl_intersection_reset(&shadow);
	shadow.ray.origin = ray_intersect(&intersection->ray);
	shadow.ray.direction = *light_direction;
	cl_scene_intersect(scene, shape_data, shapes, &shadow);
	if (shadow.ray.t >= RAY_T_MIN && shadow.ray.t <= vector3_length(light_direction))
	{
		if (scene->settings.tshadows && shadow.material.refract)
		{
		    intersection->shadow_ratio = shadow.material.refract;
			return (0);
		}
		return (1);
	}
	return (0);
}

// /////////////////////////////////////////////////////////////////////////////
//						LIGHT TOOLS
// /////////////////////////////////////////////////////////////////////////////


static void             cl_intersection_lighting_diffuse
                        (t_intersection_cl *intersection,
                        constant t_light *light,
                        t_vector3 *light_direction)
{
float	          dot;

	if ((dot = vector3_dot(light_direction, &intersection->normal)) > 0.)
		intersection->diffuse_intensity += intersection->shadow_ratio * intersection->material.diffuse * light->intensity * dot / vector3_length(light_direction);
}

static void             cl_intersection_lighting_specular
                        (t_intersection_cl *intersection,
                        constant t_light *light,
                        t_vector3 *light_direction)
{
	t_vector3            halfway;
float	          dot;

	halfway = vector3_add(light_direction, &intersection->ray.direction);
	vector3_normalize(&halfway);
	if ((dot = vector3_dot(&halfway, &intersection->normal)) > 0.)
		intersection->specular_intensity += intersection->shadow_ratio * intersection->material.specular * light->intensity * pow(dot, BLINN);

}

static void             cl_intersection_make_color
                        (t_intersection_cl *intersection)
{
	t_vector3		    white;

	white = (t_vector3){1., 1., 1.};
	intersection->color = vector3_mul(&intersection->material.color, intersection->diffuse_intensity);
	vector3_mul_eq(&white, intersection->specular_intensity);
	vector3_add_eq(&intersection->color, &white);
}

// /////////////////////////////////////////////////////////////////////////////
//						LIGHT
// /////////////////////////////////////////////////////////////////////////////

static void				cl_scene_light_up
                        (constant t_scene_cl *scene,
                        constant void *shape_data,
                        constant t_shape_cl *shapes,
                        constant t_light *lights,
                        t_intersection_cl *intersection)
{
	int                 i;
	t_vector3           light_direction;

	i = 0;

	while(i < scene->light_number)
	{
		intersection->shadow_ratio = 1.;
		if (lights[i].type == light_ambient)
		{
			intersection->diffuse_intensity += lights[i].intensity;
			continue ;
		}
		else
			light_direction = intersection_light_direction(intersection, lights);
		if (scene->settings.shadows && cl_scene_check_shadow(scene, shape_data, shapes, intersection, &light_direction))
		{
		    i++;
			continue ;
		}
		if (scene->settings.diffuse_light)
			cl_intersection_lighting_diffuse(intersection, lights + i, &light_direction);
		if (scene->settings.specular_light)
			cl_intersection_lighting_specular(intersection, lights + i, &light_direction);
		i++;
	}
	cl_intersection_make_color(intersection);
}

// /////////////////////////////////////////////////////////////////////////////
//						REFLECTION
// /////////////////////////////////////////////////////////////////////////////

static void				cl_intersection_reflect
                        (t_intersection_cl *target,
                         const t_intersection_cl *source)
{
	t_vector3		    temp;

	temp = vector3_mul(&source->normal, -2. * vector3_dot(&source->normal, &source->ray.direction));
	vector3_add_eq(&temp, &source->ray.direction);
	vector3_normalize(&temp);
	target->ray.direction = temp;
	target->ray.origin = ray_intersect(&source->ray);
}

static void             cl_reflect(
                        t_intersection_cl *original,
                        constant t_scene_cl *scene,
                        constant void *shape_data,
                        constant t_shape_cl *shapes,
                        constant t_light *lights,
                        int *depth)
{
    t_vector3           result_color;
    t_intersection_cl   previous;
    t_intersection_cl   current;
float	         depth_ratio;
    int                 i;

    result_color = (t_vector3){0., 0., 0.};
    previous = *original;
    depth_ratio = original->material.reflect;
    i = 0;
    while (i <= *depth && previous.material.reflect)
    {
        cl_intersection_reset(&current);
        cl_intersection_reflect(&current, &previous);
        if (cl_scene_intersect(scene, shape_data, shapes, &current))
        {
            cl_scene_light_up(scene, shape_data, shapes, lights, &current);
            vector3_mul_eq(&current.color, depth_ratio);
            vector3_add_eq(&result_color, &current.color);
        }
        else
            vector3_s_add_eq(&result_color, vector3_s_mul(scene->background, depth_ratio));
        previous = current;
        depth_ratio *= original->material.reflect;
        i++;
    }
    vector3_add_eq(&original->color, &result_color);
}

// /////////////////////////////////////////////////////////////////////////////
//						REFRACTION
// /////////////////////////////////////////////////////////////////////////////

static void				cl_intersection_refract
                        (t_intersection_cl *target,
                        const t_intersection_cl *source)
{
    t_vector3		refracted;
    t_vector3		a, b;
    t_vector3		m;
	float			sin_alpha;
	float			sin_beta;
	float			cos_beta;

    m = vector3_mul(&source->normal, -1. * vector3_dot(&source->normal, &source->ray.direction));
    vector3_add_eq(&m, &source->ray.direction);
    vector3_normalize(&m);
    sin_alpha = vector3_s_length(vector3_s_cross(vector3_mul(&source->ray.direction, -1.), source->normal));
    sin_beta = sin_alpha / 1.008;
    cos_beta = sqrtf(1 - sin_beta * sin_beta);
    a = vector3_mul(&source->normal, -1 * cos_beta);
    b = vector3_mul(&m, sin_beta);
    refracted = vector3_add(&a, &b);
    vector3_normalize(&refracted);
    target->ray.direction = refracted;
    target->ray.origin = ray_intersect(&source->ray);
}

static void             cl_refract(
                        t_intersection_cl *original,
                        constant t_scene_cl *scene,
                        constant void *shape_data,
                        constant t_shape_cl *shapes,
                        constant t_light *lights,
                        int *depth)
{
    t_vector3           result_color;
    t_intersection_cl   previous;
    t_intersection_cl   current;
float	         depth_ratio;
    int                 i;

    result_color = (t_vector3){0., 0., 0.};
    previous = *original;
    depth_ratio = original->material.refract;
    i = 0;
    while (i <= *depth && previous.material.refract)
    {
        cl_intersection_reset(&current);
        cl_intersection_refract(&current, &previous);
        if (cl_scene_intersect(scene, shape_data, shapes, &current))
        {
            cl_scene_light_up(scene, shape_data, shapes, lights, &current);
            vector3_mul_eq(&current.color, depth_ratio);
            vector3_add_eq(&result_color, &current.color);
        }
        else
            vector3_s_add_eq(&result_color, vector3_s_mul(scene->background, depth_ratio));
        previous = current;
        depth_ratio *= original->material.refract;
        i++;
    }
    vector3_add_eq(&original->color, &result_color);
}

// /////////////////////////////////////////////////////////////////////////////
//						RAY_TRACER
// /////////////////////////////////////////////////////////////////////////////


kernel void				cl_trace_ray(
                        global int *image,
                        global t_camera_cl *camera,
						constant t_scene_cl *scene,
						constant void *shape_data,
						constant t_shape_cl *shapes,
						constant t_light *lights,
						constant int *reflection_depth,
						constant int *refraction_depth,
						constant int *win_width,
						constant int *win_height)
{
    int 				global_id;
    t_vector3           screen;
    t_vector3           vp;
    t_intersection_cl	intersection;
    int                 depth[2];

	global_id = get_global_id(0);

    screen.x = global_id % *win_width;
	screen.y = global_id / *win_width;

	vp.x = screen.x - (*win_width - 1.) / 2.;
    vp.y = -1 * screen.y + (*win_height - 1.) / 2.;

	intersection.ray = cl_camera_cast_ray(camera, &vp);

    depth[0] = *reflection_depth;
    depth[1] = *refraction_depth;

	cl_intersection_reset(&intersection);

   if (!cl_scene_intersect(scene, shape_data, shapes, &intersection))
	{
		image[global_id] = cl_color_unpack((t_vector3)scene->background);
		return ;
	}

	if (intersection.highlight)
	{
		image[global_id] = cl_color_unpack((t_vector3){1., 1., 1.});
		return ;
	}

	cl_scene_light_up(scene, shape_data, shapes, lights, &intersection);

	if (intersection.material.reflect && *reflection_depth > 0)
	   cl_reflect(&intersection, scene, shape_data, shapes, lights, depth + 0);

    if (intersection.material.refract && *refraction_depth > 0)
        cl_refract(&intersection, scene, shape_data, shapes, lights, depth + 1);

    image[global_id] = cl_color_unpack(intersection.color);

}