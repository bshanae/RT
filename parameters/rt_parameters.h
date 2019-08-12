#ifndef RT_PARAMETERS_H
# define RT_PARAMETERS_H

# define GUI_SOURCE					"./gui/build/build.glade"
# define GUI_GET					gtk_builder_get_object

# define GUI_DEFAULT_WIDTH			480
# define GUI_DEFAULT_HEIGHT			480

# define OBJECT_DATA_CAPACITY		32

# define SCENE_OBJECTS_CAPACITY		16

# define CL_PATH_DEPTH				1
# define CL_SAMPLES					2
# define CL_RUSSIAN_DEPTH			10
# define CL_SRGB					0
# define CL_LIGHT_PB				1
# define CL_LIGHT_EXPLICIT			1

#ifdef RT_FLOAT
#  define INTERSECTION_MIN			0.0001
#endif

#ifdef RT_DOUBLE
#  define INTERSECTION_MIN			0.000001
#endif

# define INTERSECTION_MAX			INFINITY

#endif
