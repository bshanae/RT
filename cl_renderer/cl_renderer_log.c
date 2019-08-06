#include "cl_renderer.h"

void				cl_renderer_log(t_cl_renderer *renderer)
{
	char			*log;
	u_long			log_length;
	int 			fd;

	clGetProgramBuildInfo(renderer->program.program, renderer->device_id,
		CL_PROGRAM_BUILD_LOG, 0, NULL, &log_length);
	log = ft_strnew(log_length);
	clGetProgramBuildInfo(renderer->program.program, renderer->device_id,
		CL_PROGRAM_BUILD_LOG, log_length + 1, log, NULL);
	ft_printf("cl compilation log (%d): \n%s\n", renderer->program.error, log);
	free(log);
	fd = open("./cl_build", O_TRUNC | O_WRONLY);
	ft_printf("%fd_out%s\n", fd, renderer->program.buffer);
	close(fd);
	exit(1);
}