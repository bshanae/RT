#ifndef RT_PARAMETERS_H
# define RT_PARAMETERS_H

# include "rt_control.h"

# define RT_GUI_BUILD				"./gui/source/build.glade"
# define RT_GUI_THEME				"./gui/source/theme_aurora/gtk.css"
# define RT_GUI_SCREENSHOTS			"./screenshots"
# define RT_GUI_SCENES				"./scenes"
# define RT_GUI_GET					(void *)gtk_builder_get_object

# define RT_GUI_WIDTH				480
# define RT_GUI_HEIGHT				480

# define RT_GUI_QUEUE_CEILING		10

# define RT_CL_PROGRAM_INIT			128
# define RT_CL_ARGS_CAPACITY		16
# define RT_CL_OBJECT_CAPACITY		64
# define RT_CL_SCENE_CAPACITY		32

# define RT_CL_DEPTH				3
# define RT_CL_SAMPLES				2
# define RT_CL_LIGHT_BASIC			0
# define RT_CL_LIGHT_BASIC_BLINN	(RT_F)20.
# define RT_CL_LIGHT_AREA			1
# define RT_CL_ILLUMINATION			0
# define RT_CL_ILLUMINATION_VALUE	(RT_F)1.5

# ifdef RT_DEGUB_CL_RM
#  define RT_CL_RM_MOD				1
# else
#  define RT_CL_RM_MOD				1
# endif
# define RT_CL_RM_STEP_LIMIT		128
# define RT_CL_STEP_PART			(RT_F)1.
# define RT_CL_RM_MAX_DISTANCE		200

# define RT_CL_ANTIALIASING			1
# define RT_CL_CARTOON_EFFECT   	0
# define RT_CL_FILTER_SEPIA        	0
# define RT_CL_FOCUS				0
# define RT_CL_APERTURE_SIZE		(RT_F)5.
# define RT_CL_FOCAL_LENGTH			(RT_F)40.

#ifdef RT_FLOAT
#  define RT_EPSILON				0.0001f
#  define RT_RM_EPSILON				0.0001f
#  define RT_CL_RM_NORMAL_EPSILON	0.0001f
#endif

#ifdef RT_DOUBLE
#  define RT_EPSILON				0.000001
#  define RT_RM_EPSILON				0.000001
#  define RT_CL_RM_NORMAL_EPSILON	0.000001
#endif

# define RT_INFINITY				INFINITY

#endif
