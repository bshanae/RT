#include "cl_builder.h"

void				cl_builder_create_context(t_cl_builder *builder)
{
	printf("Kernel Builder : Initializing context\n");
	builder->context = clCreateContext(NULL, 1,
		&builder->device_id, 0, 0, &builder->error);
	rt_assert_critical(builder->error == 0, "Builder : Context error");
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

void				cl_builder_create_kernel(t_cl_builder *builder)
{
	printf("Kernel Builder : Creating kernel\n");
	builder->kernel = clCreateKernel(builder->program->program,
		RT_CL_MAIN_FUNCTION, &builder->error);
	rt_assert_critical(builder->error == 0, "Builder : Kernel error");
}

void				cl_builder_create_queue(t_cl_builder *builder)
{
	printf("Kernel Builder : Creating kernels' queue\n");
	builder->queue = clCreateCommandQueue(builder->context,
		 builder->device_id, 0, &builder->error);
	rt_assert_critical(builder->error == 0, "Builder : Queue error");
}