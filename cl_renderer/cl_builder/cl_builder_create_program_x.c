/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_builder_create_program_x.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 13:57:54 by ashari            #+#    #+#             */
/*   Updated: 2019/09/28 13:57:55 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cl_builder.h"

static void			cl_builder_create_program_objects(t_cl_builder *builder)
{
	cl_program_concat(builder->program, RT_SOURCE_CL_OBJECT);
	cl_program_concat(builder->program, RT_SOURCE_CL_OBJECT_SPHERE);
	cl_program_concat(builder->program, RT_SOURCE_CL_OBJECT_PLANE);
	cl_program_concat(builder->program, RT_SOURCE_CL_OBJECT_CONE);
	cl_program_concat(builder->program, RT_SOURCE_CL_OBJECT_CYLINDER);
	cl_program_concat(builder->program, RT_SOURCE_CL_OBJECT_BOX);
	cl_program_concat(builder->program, RT_SOURCE_CL_OBJECT_PARABOLOID);
	cl_program_concat(builder->program, RT_SOURCE_CL_OBJECT_MOEBIUS);
	cl_program_concat(builder->program, RT_SOURCE_CL_OBJECT_LIMITED);
	cl_program_concat(builder->program, RT_SOURCE_CL_OBJECT_TORUS);
	cl_program_concat(builder->program, RT_SOURCE_CL_OBJECT_JULIA);
	cl_program_concat(builder->program, RT_SOURCE_CL_OBJECT_MANDELBULB);
	cl_program_concat(builder->program, RT_SOURCE_CL_OBJECT_PERFORATED_CUBE);
	cl_program_concat(builder->program, RT_SOURCE_CL_OBJECT_CSG);
	cl_program_concat(builder->program, RT_SOURCE_CL_OBJECT_EXPLOSION);
	cl_program_concat(builder->program, RT_SOURCE_CL_OBJECT_X);
}

void				cl_builder_create_program_a(t_cl_builder *builder)
{
	printf("Kernel Builder : Buffering program source\n");
	cl_program_concat(builder->program, RT_SOURCE_CL_F4);
	cl_program_concat(builder->program, RT_SOURCE_CL_SETTINGS);
	cl_program_concat(builder->program, RT_SOURCE_CL_RANDOM);
	cl_program_concat(builder->program, RT_SOURCE_CL_RAY);
	cl_program_concat(builder->program, RT_SOURCE_CL_COLOR);
	cl_program_concat(builder->program, RT_SOURCE_CL_MATERIAL);
	cl_program_concat(builder->program, RT_SOURCE_CL_INTERSECTION_X);
	cl_builder_create_program_objects(builder);
	cl_program_concat(builder->program, RT_SOURCE_CL_CAMERA_DEFINITION);
	cl_program_concat(builder->program, RT_SOURCE_CL_TEXTURE);
	cl_program_concat(builder->program, RT_SOURCE_CL_OBJECT_NORMAL);
	cl_program_concat(builder->program, RT_SOURCE_CL_SCENE_X);
	cl_program_concat(builder->program, RT_SOURCE_CL_SAMPLE_X);
	cl_program_concat(builder->program, RT_SOURCE_CL_LIGHT_BASIC);
	cl_program_concat(builder->program, RT_SOURCE_CL_LIGHT_AREA);
	cl_program_concat(builder->program, RT_SOURCE_CL_FILTER);
	cl_program_concat(builder->program, RT_SOURCE_CL_CAMERA);
	cl_program_concat(builder->program, RT_SOURCE_CL_ILLUMINATION);
	cl_program_concat(builder->program, RT_SOURCE_CL_RADIANCE_X);
	cl_program_concat(builder->program, RT_SOURCE_CL_SAMPLE_STORE);
	cl_program_concat(builder->program, RT_SOURCE_CL_MAIN);
}

void				cl_builder_create_program_b(t_cl_builder *builder)
{
	printf("Kernel Builder : Compiling program\n");
	if (cl_program_build(builder->program, builder->context, RT_CL_FLAGS) != 0)
		cl_builder_log(builder);
}
