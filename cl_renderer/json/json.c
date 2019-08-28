#include "cl_renderer.h"
#include "json.h"
#include "json_parse.h"

void	renderer_load(t_cl_renderer *r, char *path)
{
	load_scene(r, path);
}