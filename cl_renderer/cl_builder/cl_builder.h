#ifndef CL_BUILDER_H
# define CL_BUILDER_H

# include "rt_control.h"
# include "rt_cl_include.h"
# include "rt_cl_compilation.h"

# include "assert.h"
# include "cl_program.h"
# include "cl_arg_list.h"

# include <stdio.h>

typedef struct			s_cl_builder
{
	cl_device_id 		device_id;
	cl_context 			context;
	cl_kernel 			kernel;
	cl_command_queue 	queue;
	int 				error;
	t_cl_program		*program;
}						t_cl_builder;

t_cl_builder			*cl_builder_new(void);
void					cl_builder_delete(t_cl_builder **builder);

void					cl_builder_init_device(t_cl_builder *builder);
void					cl_builder_create_context(t_cl_builder *builder);

void					cl_builder_create_program_a(t_cl_builder *builder);
void					cl_builder_create_program_b(t_cl_builder *builder);
void					cl_builder_create_kernel(t_cl_builder *builder);
void					cl_builder_create_queue(t_cl_builder *builder);

void					cl_builder_set_args
						(t_cl_builder *builder, t_cl_arg_list *list);

void 					cl_builder_log(t_cl_builder *builder);


#endif
