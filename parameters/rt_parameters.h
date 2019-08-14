#ifndef RT_PARAMETERS_H
# define RT_PARAMETERS_H

# define RT_GUI_SOURCE				"./gui/build/build.glade"
# define RT_GUI_GET					gtk_builder_get_object

# define RT_GUI_DEFAULT_WIDTH		480
# define RT_GUI_DEFAULT_HEIGHT		480

# define RT_OBJECT_DATA_CAPACITY	32

# define RT_SCENE_OBJECTS_CAPACITY	16

# define RT_CL_PATH_DEPTH			8
# define RT_CL_SAMPLES				2
# define RT_CL_RUSSIAN_DEPTH		4
# define RT_CL_SRGB					1
# define RT_CL_LIGHT_PB				1
# define RT_CL_LIGHT_EXPLICIT		1
# define RT_CL_COSINE				1

#ifdef RT_FLOAT
#  define INTERSECTION_MIN			0.0001
#endif

#ifdef RT_DOUBLE
#  define INTERSECTION_MIN			0.000001
#endif

# define RT_INTERSECTION_MAX		INFINITY

#endif
