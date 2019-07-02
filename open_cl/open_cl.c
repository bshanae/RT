/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_cl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 19:11:54 by ashari            #+#    #+#             */
/*   Updated: 2019/07/02 11:17:32 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "open_cl.h"

t_open_cl				*open_cl_new(int *image)
{
	t_open_cl			*new;

	if (!(new = (t_open_cl *)malloc(sizeof(t_open_cl))))
		exit(21);
	open_cl_create_device(new);
	open_cl_create_context(new);
	open_cl_create_program(new);
	open_cl_create_queue(new);
	open_cl_create_kernel(new);
	new->total_size = WINDOW_WIDTH * WINDOW_HEIGHT;
	new->data_host.image = image;
	new->data_size.image = sizeof(int) * WINDOW_WIDTH * WINDOW_HEIGHT;
	new->data_size.scene = sizeof(t_scene);
	open_cl_alloc_device(new);
	open_cl_set_arguments(new);
	return (new);
}

void					open_cl_delete(t_open_cl **me)
{
	clReleaseMemObject((*me)->data_device.image);
	clReleaseMemObject((*me)->data_device.scene);
	clReleaseDevice((*me)->device_id);
	clReleaseContext((*me)->context);
	clReleaseProgram((*me)->program);
	clReleaseKernel((*me)->kernel);
	clReleaseCommandQueue((*me)->queue);
	free(*me);
	*me = NULL;
}

void					open_cl_run(t_open_cl *me, t_scene *scene)
{
	int					error;

	error = clEnqueueWriteBuffer(me->queue, me->data_device.scene, CL_TRUE,
		0, me->data_size.scene, scene, 0, NULL, NULL);
	error_check(__LINE__, __FUNCTION__, error);
	error = clEnqueueNDRangeKernel(me->queue, me->kernel, 1, NULL,
		&me->total_size, NULL, 0, NULL, NULL);
	error_check(__LINE__, __FUNCTION__, error);
	error = clEnqueueReadBuffer(me->queue, me->data_device.image, CL_TRUE,
		0, me->data_size.image, me->data_host.image, 0, NULL, NULL);
	error_check(__LINE__, __FUNCTION__, error);
}
