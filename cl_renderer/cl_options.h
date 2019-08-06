#ifndef OPEN_CL_OPTIONS_H
# define OPEN_CL_OPTIONS_H

# define CL_SILENCE_DEPRECATION
# pragma OPENCL EXTENSION cl_khr_fp64 : enable


# define CL_FLAGS				"-I ./"

# define CL_MAIN_FUNCTION		"cl_main"

# define CL_SOURCE_VECTOR		"./cl_renderer/sources/cl_vector"
# define CL_SOURCE_RAY			"./cl_renderer/sources/cl_ray"
# define CL_SOURCE_CAMERA		"./cl_renderer/sources/cl_camera"
# define CL_SOURCE_INTERSECTION	"./cl_renderer/sources/cl_intersection"
# define CL_SOURCE_LIGHT		"./cl_renderer/sources/cl_light"
# define CL_SOURCE_OBJECT_DEF	"./cl_renderer/sources/cl_object_definition"
# define CL_SOURCE_OBJECT_LIST	"./cl_renderer/sources/cl_object_list"
# define CL_SOURCE_OBJECT_INTER	"./cl_renderer/sources/cl_object_intersect"
# define CL_SOURCE_SCENE		"./cl_renderer/sources/cl_scene"
# define CL_SOURCE_COLOR		"./cl_renderer/sources/cl_color"
# define CL_SOURCE_MAIN			"./cl_renderer/sources/cl_main"

#endif
