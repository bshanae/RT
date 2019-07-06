# include "rp.h"

static void			create_coordiante_system(const t_vector3 *normal, t_vector3 *nt, t_vector3 *nb)
{
	if (fabsf(normal->x) > fabsf(normal->y))
		*nt = (t_vector3){normal->z, 0., -1.f * normal->x};
	else
		*nt = (t_vector3){0., -1.f * normal->z, normal->y};
	vector3_normalize(nt);
	*nb = vector3_cross(normal, nt);
}

static t_vector3	generate_sample(const float *r1, const float *r2)
{
	float 			sin_theta;
	float 			phi;

	phi = 2.f * M_PI * *r2;
	sin_theta = sqrtf(1.f - *r1 * *r1);

	return ((t_vector3)
	{
		sin_theta * cosf(phi),
		*r1,
		sin_theta * sinf(phi)
	});
}

static t_vector3	convert_sample(const t_vector3 *normal, const t_vector3 *sample, const t_vector3 *nt, const t_vector3 *nb)
{
	return ((t_vector3)
	{
		sample->x * nb->x + sample->y * normal->x + sample->z * nt->x,
		sample->x * nb->y + sample->y * normal->y + sample->z * nt->y,
		sample->x * nb->z + sample->y * normal->z + sample->z * nt->z,
	});
}

#define BIAS		0.001f

t_vector3			rp_cast_ray(t_rp *rp, t_intersection me, int depth)
{
	t_vector3		color;

	intersection_reset(&me);

	if (--depth < 0)
		return (COLOR_BLACK);
	if (!scene_intersect(rp->scene, &me))
		return (COLOR_WHITE);

	float		u;
	float 		max_color;

	u = drand48();
	max_color = fmaxf(fmaxf(me.color.x, me.color.y), me.color.z);
	if (RUSSIAN_ROULETTE && depth < PATH_DEPTH - 1 && u > max_color)
		return (COLOR_BLACK);

	// direct

	t_vector3		light_direct;

	scene_light_up(rp->scene, &me);
	light_direct = me.color;

	// indirect

	t_vector3		light_indirect;
	t_intersection	child;
	t_vector3		nt;
	t_vector3		nb;
	t_vector3		hit;
	float 			inv_pdf;
	float 			r1;
	float 			r2;
	t_vector3		sample_local;
	t_vector3		sample_world;
	t_vector3		sample_color;

	light_indirect = COLOR_BLACK;
	hit = ray_intersect(&me.ray);
	create_coordiante_system(&me.normal, &nt, &nb);
	inv_pdf = 2.f * M_PI;

	r1 = (float)drand48();
	r2 = (float)drand48();

	sample_local = generate_sample(&r1, &r2);

	sample_world = convert_sample(&me.normal, &sample_local, &nt, &nb);

	child.ray.origin = vector3_s_add(hit, vector3_mul(&sample_world, BIAS));
	child.ray.direction = sample_world;

	sample_color = rp_cast_ray(rp, child, depth);

	vector3_mul_eq(&sample_color, r1 * inv_pdf);

	vector3_add_eq(&light_indirect, &sample_color);

	color = vector3_s_add
		(
			vector3_div(&light_direct, 1.),
			vector3_mul(&light_indirect, 2.)
		);
	color.x *= me.color.x;
	color.y *= me.color.y;
	color.z *= me.color.z;
	return (color);
}

void 				rp_render(t_rp *rp)
{
	int 			x;
	int 			y;
	t_vector3		vp;
	t_intersection	intersection;

	srand48(time(NULL));
	x = 0;
	vp.z = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			vp.x = x - (WINDOW_WIDTH - 1) / 2.;
			vp.y = -y + (WINDOW_HEIGHT - 1) / 2.;
			intersection.ray = camera_cast_ray(rp->camera, &vp);
			vector3_s_add_eq(&rp->color_storage[x + y * WINDOW_WIDTH], rp_cast_ray(rp, intersection, PATH_DEPTH));
			rp->img_data[x + y * WINDOW_WIDTH] =
				color_unpack(vector3_div(&rp->color_storage[x + y * WINDOW_WIDTH], (float)rp->sample_counter));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(rp->mlx_ptr, rp->win_ptr, rp->img_ptr, 0, 0);
	printf("samples group no. %d\n", rp->sample_counter);
}