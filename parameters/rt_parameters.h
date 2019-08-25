#ifndef RT_PARAMETERS_H
# define RT_PARAMETERS_H

# define RT_GUI_BUILD				"./gui/source/build.glade"
# define RT_GUI_THEME				"./gui/source/theme_breeze/gtk-3.20/gtk.css"
# define RT_GUI_GET					gtk_builder_get_object

# define RT_GUI_WIDTH				480
# define RT_GUI_HEIGHT				480

# define RT_CL_PROGRAM_INIT			128
# define RT_CL_ARGS_CAPACITY		16
# define RT_CL_OBJECT_CAPACITY		128
# define RT_CL_SCENE_CAPACITY		32

# define RT_CL_PATH_DEPTH			10
# define RT_CL_SAMPLES				10
# define RT_CL_RUSSIAN_DEPTH		5
# define RT_CL_SRGB					1
# define RT_CL_LIGHT_PB				1
# define RT_CL_LIGHT_EXPLICIT		1

# define RT_CL_CARTOON_EFFECT		0
# define RT_CL_FILTER_SEPIA			0
# define RT_CL_FILTER_STEREOSCOPY	0

# define RT_CL_RM_MOD				0
# define RT_CL_RM_STEP_LIMIT		512
# define RT_CL_STEP_PART			1.
# define RT_CL_RM_MAX_DISTANCE		200

# define RT_CL_ANTIALIASING			1
# define RT_CL_FOCUS				0
# define RT_CL_APERTURE_SIZE		5.
# define RT_CL_FOCAL_LENGTH			40.

#ifdef RT_FLOAT
#  define RT_EPSILON				0.0001f
#  define RT_CL_RM_NORMAL_EPSILON	0.0001f
#endif

#ifdef RT_DOUBLE
#  define RT_EPSILON				0.000001
#  define RT_CL_RM_NORMAL_EPSILON	0.000001
#endif

# define RT_INFINITY		INFINITY

#endif
