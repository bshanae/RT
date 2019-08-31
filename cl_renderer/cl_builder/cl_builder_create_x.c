#include "cl_builder.h"

void				cl_builder_create_context(t_cl_builder *builder)
{
	printf("Kernel Builder : Initializing context\n");
	builder->context = clCreateContext(NULL, 1,
		&builder->device_id, 0, 0, &builder->error);
	RT_ASSERT(builder->error == 0)
}

void				cl_builder_create_program_a(t_cl_builder *builder)
{
	printf("Kernel Builder : Buffering program source\n");
	cl_program_concat(builder->program, CL_SOURCE_F4);
	cl_program_concat(builder->program, CL_SOURCE_SETTINGS);
	cl_program_concat(builder->program, CL_SOURCE_RANDOM);
	cl_program_concat(builder->program, CL_SOURCE_RAY);
	cl_program_concat(builder->program, CL_SOURCE_COLOR);
	cl_program_concat(builder->program, CL_SOURCE_MATERIAL);
	cl_program_concat(builder->program, CL_SOURCE_INTERSECTION);
	cl_program_concat(builder->program, CL_SOURCE_OBJECT);
	cl_program_concat(builder->program, CL_SOURCE_OBJECT_SPHERE);
	cl_program_concat(builder->program, CL_SOURCE_OBJECT_PLANE);
	cl_program_concat(builder->program, CL_SOURCE_OBJECT_CONE);
	cl_program_concat(builder->program, CL_SOURCE_OBJECT_CYLINDER);
	cl_program_concat(builder->program, CL_SOURCE_OBJECT_BOX);
	cl_program_concat(builder->program, CL_SOURCE_OBJECT_PARABOLOID);
	cl_program_concat(builder->program, CL_SOURCE_OBJECT_MOEBIUS);
	cl_program_concat(builder->program, CL_SOURCE_OBJECT_LIMITED);
	cl_program_concat(builder->program, CL_SOURCE_OBJECT_TORUS);
	cl_program_concat(builder->program, CL_SOURCE_OBJECT_JULIA);
	cl_program_concat(builder->program, CL_SOURCE_OBJECT_MANDELBULB);
	cl_program_concat(builder->program, CL_SOURCE_OBJECT_CSG);
	cl_program_concat(builder->program, CL_SOURCE_OBJECT_PERFORATED_CUBE);
	cl_program_concat(builder->program, CL_SOURCE_OBJECT_X);
	cl_program_concat(builder->program, CL_SOURCE_OBJECT_NORMAL);
	cl_program_concat(builder->program, CL_SOURCE_TEXTURE);
	cl_program_concat(builder->program, CL_SOURCE_SCENE);
	cl_program_concat(builder->program, CL_SOURCE_SAMPLE_X);
	cl_program_concat(builder->program, CL_SOURCE_LIGHT_BASIC);
	cl_program_concat(builder->program, CL_SOURCE_LIGHT_AREA);
	cl_program_concat(builder->program, CL_SOURCE_FILTER);
	cl_program_concat(builder->program, CL_SOURCE_CAMERA);
	cl_program_concat(builder->program, CL_SOURCE_RADIANCE_X);
	cl_program_concat(builder->program, CL_SOURCE_ILLUMINATION);
	cl_program_concat(builder->program, CL_SOURCE_SAMPLE_STORE);
	cl_program_concat(builder->program, CL_SOURCE_MAIN);
}

void				cl_builder_create_program_b(t_cl_builder *builder)
{
	printf("Kernel Builder : Compiling program\n");
	if (cl_program_build(builder->program, builder->context, CL_FLAGS) != 0)
		cl_builder_log(builder);
}

void				cl_builder_create_kernel(t_cl_builder *builder)
{
	printf("Kernel Builder : Creating kernel\n");
	builder->kernel = clCreateKernel(builder->program->program,
		CL_MAIN_FUNCTION, &builder->error);
	RT_ASSERT(builder->error == 0)
}

void				cl_builder_create_queue(t_cl_builder *builder)
{
	printf("Kernel Builder : Creating kernels' queue\n");
	builder->queue = clCreateCommandQueue(builder->context,
		 builder->device_id, 0, &builder->error);
	RT_ASSERT(builder->error == 0)

}