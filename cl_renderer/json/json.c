#include "cl_renderer.h"
#include "json.h"
#include "json_parse.h"

void	renderer_load(t_cl_renderer *r, char *path)
{
	bzero(r->data.scene, sizeof(t_scene));
	load_scene(r, path);
}