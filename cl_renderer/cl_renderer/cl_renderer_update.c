#include "cl_renderer.h"

void				cl_renderer_update
					(t_cl_renderer *renderer, t_cl_update update)
{
	if (update == rt_update_camera)
		renderer->error = clEnqueueWriteBuffer(
			renderer->queue, renderer->data_device.camera,
			CL_TRUE, 0, renderer->data_size.camera,
			renderer->data_host.camera, 0, NULL, NULL);
	else if (update == rt_update_scene)
		renderer->error = clEnqueueWriteBuffer(
			renderer->queue, renderer->data_device.scene,
			CL_TRUE, 0, renderer->data_size.scene,
			renderer->data_host.scene, 0, NULL, NULL);
	else if (update == rt_update_settings)
		renderer->error = clEnqueueWriteBuffer(
				renderer->queue, renderer->data_device.settings,
				CL_TRUE, 0, renderer->data_size.settings,
				&renderer->data_host.settings, 0, NULL, NULL);
	ASSERT(renderer->error == 0)
	renderer->flags.update_camera *= update == rt_update_camera ? 0 : 1;
	renderer->flags.update_scene *= update == rt_update_scene ? 0 : 1;
	renderer->flags.update_settings *= update == rt_update_settings ? 0 : 1;
}
