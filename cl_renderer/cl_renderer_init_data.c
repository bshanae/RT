#include "cl_renderer.h"

void 				cl_renderer_init_data(t_cl_renderer *renderer)
{
	renderer->data_host.camera =
		camera_new(&renderer->image->width, &renderer->image->height);
	renderer->data_host.scene = scene_new();
	renderer->data_host.image = renderer->image->color_buffer;
	renderer->data_size.camera = sizeof(t_camera);
	renderer->data_size.scene = sizeof(t_scene);
	renderer->data_size.image =
		sizeof(int) * renderer->image->width * renderer->image->height;
	renderer->data_device.camera = clCreateBuffer(renderer->context,
		CL_MEM_READ_ONLY, renderer->data_size.camera, NULL, &renderer->error);
	ASSERT(renderer->error == 0)
	renderer->data_device.scene = clCreateBuffer(renderer->context,
		CL_MEM_READ_ONLY, renderer->data_size.scene, NULL, &renderer->error);
	ASSERT(renderer->error == 0)
	renderer->data_device.image = clCreateBuffer(renderer->context,
		CL_MEM_WRITE_ONLY, renderer->data_size.image, NULL, &renderer->error);
	ASSERT(renderer->error == 0)

}