#ifndef CL_COMPILATION_H
# define CL_COMPILATION_H

# define CL_SILENCE_DEPRECATION
# pragma OPENCL EXTENSION cl_khr_fp64 : enable

# define CL_FLAGS					"-I ./ -I ./cl_parameters"

# define CL_MAIN_FUNCTION			"cl_main"

# define CL_SOURCE_FOLDER			"./cl_renderer/sources/"

# define CL_SOURCE_VECTOR			"cl_vector"
# define CL_SOURCE_RAY				"cl_ray"
# define CL_SOURCE_CAMERA			"cl_camera"
# define CL_SOURCE_INTERSECTION		"cl_intersection"
# define CL_SOURCE_LIGHT			"cl_light"
# define CL_SOURCE_OBJECT_DEF		"cl_object_definition"
# define CL_SOURCE_OBJECT_SPHERE	"cl_object_sphere"
# define CL_SOURCE_OBJECT_PLANE		"cl_object_plane"
# define CL_SOURCE_OBJECT_INTER		"cl_object_intersect"
# define CL_SOURCE_SCENE			"cl_scene"
# define CL_SOURCE_COLOR			"cl_color"
# define CL_SOURCE_MAIN				"cl_main"

#endif
