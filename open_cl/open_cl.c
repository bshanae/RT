#include "open_cl.h"

void				raise_error(int line, const char *function_name, int error)
{
	ft_printf("Error no. %d on line %d in %s\n", error, line, function_name);
	exit(1);
}

cl_device_id		open_cl_create_device()
{
	cl_platform_id 	platform;
	cl_device_id 	device;
	int				error;

	error = clGetPlatformIDs(1, &platform, NULL);
	CHECK_ERROR
	error = clGetDeviceIDs(platform, CL_DEVICE_TYPE_CPU, 1, &device, NULL);
	CHECK_ERROR
	return (device);
}

void				open_cl_create_program(t_open_cl *me, const char *file_name)
{
	int 			error;
	int 			fd;
	char 			*big_buffer;
	u_long 			buffer_capacity;
	u_long 			buffer_unit;
	u_long 			buffer_length;
	char 			*log;
	u_long 			log_length;

	if ((fd = open(file_name, O_RDONLY)) == -1)
		raise_error(__LINE__, __FUNCTION__, 0);
	big_buffer = (char *)malloc(OCL_BUFF_INIT);
	buffer_capacity = OCL_BUFF_INIT;
	buffer_length = 0;
	while ((buffer_unit = read(fd, big_buffer + buffer_length, 64)) > 0)
	{
		buffer_length += buffer_unit;
		if (buffer_length + 64 > buffer_capacity)
		{
			ft_realloc((void **) &big_buffer, buffer_capacity, buffer_capacity * OCL_BUFF_MULT);
			buffer_capacity *= OCL_BUFF_MULT;
		}
	}

	me->program = clCreateProgramWithSource(me->context, 1, (const char **)&big_buffer, &buffer_length, &error);
	free(big_buffer);
	CHECK_ERROR

	error = clBuildProgram(me->program, 0, NULL, CL_FLAGS, NULL, NULL);
	if (error < 0)
	{
		clGetProgramBuildInfo(me->program, me->device_id, CL_PROGRAM_BUILD_LOG, 0, NULL, &log_length);
		log = ft_strnew(log_length);
		clGetProgramBuildInfo(me->program, me->device_id, CL_PROGRAM_BUILD_LOG, log_length + 1, log, NULL);
		ft_printf("LOG (%d): \n{%s}\n", error, log);
		free(log);
		exit(1);
	}
}

t_open_cl				*open_cl_new(int *image, int width, int height)
{
	t_open_cl			*new;
	int 				error;

	if (!(new = (t_open_cl *)malloc(sizeof(t_open_cl))))
		exit(21);
	new->device_id = open_cl_create_device();
	new->context = clCreateContext(NULL, 1, &new->device_id, NULL, NULL, &error);
	CHECK_ERROR
	open_cl_create_program(new, CL_SOURCE);
	new->queue = clCreateCommandQueue(new->context, new->device_id, 0, &error);
	CHECK_ERROR
	new->total_size = width * height;
	new->host.image = image;
	new->host.win_width = width;
	new->host.win_height = height;
	new->kernel = clCreateKernel(new->program, CL_FUNCTION, &error);
	CHECK_ERROR
	return (new);
}

void				open_cl_delete(t_open_cl **me)
{
	clReleaseMemObject((*me)->device.image);
	clReleaseMemObject((*me)->device.camera);
	clReleaseMemObject((*me)->device.scene);
	clReleaseMemObject((*me)->device.shape_data);
	clReleaseMemObject((*me)->device.shapes);
	clReleaseMemObject((*me)->device.lights);
	clReleaseMemObject((*me)->device.reflection_depth);
	clReleaseMemObject((*me)->device.refraction_depth);
	clReleaseMemObject((*me)->device.win_width);
	clReleaseMemObject((*me)->device.win_height);
	clReleaseKernel((*me)->kernel);
	clReleaseCommandQueue((*me)->queue);
	clReleaseProgram((*me)->program);
	clReleaseContext((*me)->context);
	free((*me)->host.shape_data);
	free((*me)->host.shapes);
	free((*me)->host.lights);
	free(*me);
	*me = NULL;
}

void				open_cl_alloc_device(t_open_cl *me, const t_scene *scene)
{
	int 			error;

	me->size.image = sizeof(int) * me->total_size;
	me->size.camera = sizeof(t_camera_cl);
	me->size.scene = sizeof(t_scene);
	me->size.shape_data = SHAPE_SIZE_MAX * scene->shapes.length;
	me->size.shapes = sizeof(t_shape_cl) * scene->shapes.length;
	me->size.lights = sizeof(t_light) * scene->lights.length;
	me->size.reflection_depth = sizeof(int);
	me->size.refraction_depth = sizeof(int);
	me->size.win_width = sizeof(int);
	me->size.win_height = sizeof(int);
	if (!(me->host.shape_data = malloc(me->size.shape_data)))
		exit(21);
	if (!(me->host.shapes = (t_shape_cl *) malloc(me->size.shapes)))
		exit(21);
	if (!(me->host.lights = (t_light *) malloc(me->size.lights)))
		exit(21);
	me->device.image = clCreateBuffer(me->context, CL_MEM_WRITE_ONLY, me->size.image, NULL, &error);
	CHECK_ERROR
	me->device.camera = clCreateBuffer(me->context, CL_MEM_READ_ONLY, me->size.camera, NULL, &error);
	CHECK_ERROR
	me->device.scene = clCreateBuffer(me->context, CL_MEM_READ_ONLY, me->size.scene, NULL, &error);
	CHECK_ERROR
	me->device.shape_data = clCreateBuffer(me->context, CL_MEM_READ_ONLY, me->size.shape_data, NULL, &error);
	CHECK_ERROR
	me->device.shapes = clCreateBuffer(me->context, CL_MEM_READ_ONLY, me->size.shapes, NULL, &error);
	CHECK_ERROR
	me->device.lights = clCreateBuffer(me->context, CL_MEM_READ_ONLY, me->size.lights, NULL, &error);
	CHECK_ERROR
	me->device.reflection_depth = clCreateBuffer(me->context, CL_MEM_READ_ONLY, me->size.reflection_depth, NULL, &error);
	CHECK_ERROR
	me->device.refraction_depth = clCreateBuffer(me->context, CL_MEM_READ_ONLY, me->size.refraction_depth, NULL, &error);
	CHECK_ERROR
	me->device.win_width = clCreateBuffer(me->context, CL_MEM_READ_ONLY, me->size.win_width, NULL, &error);
	CHECK_ERROR
	me->device.win_height = clCreateBuffer(me->context, CL_MEM_READ_ONLY, me->size.win_height, NULL, &error);
	CHECK_ERROR
}

void				open_cl_set_args(t_open_cl *me)
{
	int				error;

	error = clSetKernelArg(me->kernel, 0, sizeof(cl_mem), &me->device.image);
	error |= clSetKernelArg(me->kernel, 1, sizeof(cl_mem), &me->device.camera);
	error |= clSetKernelArg(me->kernel, 2, sizeof(cl_mem), &me->device.scene);
	error |= clSetKernelArg(me->kernel, 3, sizeof(cl_mem), &me->device.shape_data);
	error |= clSetKernelArg(me->kernel, 4, sizeof(cl_mem), &me->device.shapes);
	error |= clSetKernelArg(me->kernel, 5, sizeof(cl_mem), &me->device.lights);
	error |= clSetKernelArg(me->kernel, 6, sizeof(cl_mem), &me->device.reflection_depth);
	error |= clSetKernelArg(me->kernel, 7, sizeof(cl_mem), &me->device.refraction_depth);
	error |= clSetKernelArg(me->kernel, 8, sizeof(cl_mem), &me->device.win_width);
	error |= clSetKernelArg(me->kernel, 9, sizeof(cl_mem), &me->device.win_height);
	CHECK_ERROR
}

void 				open_cl_run(t_open_cl *me)
{
	int 			error;

	error = clEnqueueWriteBuffer(me->queue, me->device.camera, CL_TRUE, 0, me->size.camera, &me->host.camera, 0, NULL, NULL);
	CHECK_ERROR
	error = clEnqueueWriteBuffer(me->queue, me->device.scene, CL_TRUE, 0, me->size.scene, &me->host.scene, 0, NULL, NULL);
	CHECK_ERROR
	error = clEnqueueWriteBuffer(me->queue, me->device.shape_data, CL_TRUE, 0, me->size.shape_data, me->host.shape_data, 0, NULL, NULL);
	CHECK_ERROR
	error = clEnqueueWriteBuffer(me->queue, me->device.shapes, CL_TRUE, 0, me->size.shapes, me->host.shapes, 0, NULL, NULL);
	CHECK_ERROR
	error = clEnqueueWriteBuffer(me->queue, me->device.lights, CL_TRUE, 0, me->size.lights, me->host.lights, 0, NULL, NULL);
	CHECK_ERROR
	error = clEnqueueWriteBuffer(me->queue, me->device.reflection_depth, CL_TRUE, 0, me->size.reflection_depth, &me->host.reflection_depth, 0, NULL, NULL);
	CHECK_ERROR
	error = clEnqueueWriteBuffer(me->queue, me->device.refraction_depth, CL_TRUE, 0, me->size.refraction_depth, &me->host.refraction_depth, 0, NULL, NULL);
	CHECK_ERROR
	error = clEnqueueWriteBuffer(me->queue, me->device.win_width, CL_TRUE, 0, me->size.win_width, &me->host.win_width, 0, NULL, NULL);
	CHECK_ERROR
	error = clEnqueueWriteBuffer(me->queue, me->device.win_height, CL_TRUE, 0, me->size.win_height, &me->host.win_height, 0, NULL, NULL);
	CHECK_ERROR
	error = clEnqueueNDRangeKernel(me->queue, me->kernel, 1, NULL, &me->total_size, NULL, 0, NULL, NULL);
	CHECK_ERROR
	error = clEnqueueReadBuffer(me->queue, me->device.image, CL_TRUE, 0, me->size.image, me->host.image, 0, NULL, NULL);
	CHECK_ERROR
}