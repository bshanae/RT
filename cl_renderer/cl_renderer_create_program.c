#include "cl_renderer.h"

static void			open_cl_program_allocate(t_cl_program *program)
{
	program->length = 0;
	program->capacity = 128;
	program->buffer = malloc(program->capacity);
}

static void			open_cl_program_reallocate(t_cl_program *program)
{
	ft_realloc((void **)&program->buffer,
		program->capacity, program->capacity * 2);
	program->capacity *= 2;
}

static void			open_cl_program_read
					(t_cl_program *program, const char *file)
{
	int				fd;
	int 			read_length;

	fd = open(file, O_RDONLY);
	ft_assert(fd != -1, "open_cl : source reading");
	while (1)
	{
		if ((program->length + 64.) / program->capacity > 0.5)
			open_cl_program_reallocate(program);
		if ((read_length = read(fd, program->buffer + program->length, 64)) < 1)
			break ;
		program->length += read_length;
	}
}

static int			open_cl_program_finish
					(t_cl_program *program, cl_context *context)
{
	program->program = clCreateProgramWithSource(*context, 1,
		(const char **)&program->buffer, &program->length, &program->error);
	ft_assert(program->error == 0, "open_cl : program creation");
	program->error =
		clBuildProgram(program->program, 0, NULL, CL_FLAGS, NULL, NULL);
	if (program->error != 0)
		return (program->error);
	free(program->buffer);
	program->buffer = NULL;
	program->capacity = 0;
	program->length = -1;
	return (0);
}

void				cl_renderer_create_program(t_cl_renderer *renderer)
{
	open_cl_program_allocate(&renderer->program);
	open_cl_program_read(&renderer->program, CL_SOURCE_VECTOR3);
	open_cl_program_read(&renderer->program, CL_SOURCE_RAY);
	open_cl_program_read(&renderer->program, CL_SOURCE_CAMERA);
	open_cl_program_read(&renderer->program, CL_SOURCE_LIGHT);
	open_cl_program_read(&renderer->program, CL_SOURCE_OBJECT);
	open_cl_program_read(&renderer->program, CL_SOURCE_SCENE);
	open_cl_program_read(&renderer->program, CL_SOURCE_COLOR);
	open_cl_program_read(&renderer->program, CL_SOURCE_MAIN);
	if (open_cl_program_finish(&renderer->program, &renderer->context))
		cl_renderer_log(renderer);
}
