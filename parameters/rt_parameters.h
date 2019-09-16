#ifndef RT_PARAMETERS_H
# define RT_PARAMETERS_H

# include "rt_control.h"


typedef enum						e_rt_movement
{
	rt_movement_left,
	rt_movement_right,
	rt_movement_up,
	rt_movement_down,
	rt_movement_forward,
	rt_movement_backward
}									t_rt_movement;

typedef enum						e_rt_bool
{
	rt_false,
	rt_true
}									t_rt_bool;

typedef enum						e_rt_tracing_mod
{
	rt_tracing_mod_rt,
	rt_tracing_mod_rm
}									t_rt_tracing_mod;

# define RT_GUI_GET					(void *)gtk_builder_get_object

# define RT_GUI_WIDTH				480
# define RT_GUI_HEIGHT				480

# define RT_GUI_QUEUE_CEILING		10
# define RT_GUI_QUEUE_PASS			5
# define RT_GUI_QUEUE_FREQUENCY		50
# define RT_GUI_QUEUE_WAIT_LIMIT	2000.

# define RT_CL_PROGRAM_INIT			128
# define RT_CL_ARGS_CAPACITY		16

# define RT_CL_OBJECT_DATA_SIZE		64
# define RT_CL_OBJECT_NAME_SIZE		32
# define RT_CL_SCENE_CAPACITY		32

# define RT_CL_ANTIALIASING			1
# define RT_CL_CARTOON_EFFECT   	0
# define RT_CL_FILTER_SEPIA        	0
# define RT_CL_FILTER_STEREO       	0
# define RT_CL_FOCUS				0
# define RT_CL_APERTURE_SIZE		(RT_F)5.
# define RT_CL_FOCAL_LENGTH			(RT_F)40.

# define RT_OBJECT_MOVE_VALUE		(RT_F)1.

# define RT_CAMERA_MOVE_VALUE		(RT_F)1.
# define RT_CAMERA_ROTATE_VALUE		(RT_F)0.025

# define RT_ROOM					0

# define RT_CL_LIGHT_BASIC			0
# define RT_CL_LIGHT_BASIC_BLINN	(RT_F)20.

# define RT_CL_LIGHT_AREA			1
# define RT_LIGHT_AREA_MULTIPLIER	(RT_F)3.
# define RT_LIGHT_AREA_FLOOR		(RT_F).12
# define RT_LIGHT_AREA_CEILING		(RT_F).95

# define RT_CL_ILLUMINATION			1
# define RT_CL_ILLUMINATION_VALUE	(RT_F)1.5
# define RT_CL_ILLUMINATION_POWER	(RT_F)2.

# define RT_CL_DEPTH				1
# define RT_CL_SAMPLES				25

# define RT_CL_MOTION_BLUR			0
# define RT_CL_MOTION_BLUR_ALPHA	(RT_F)0.7
# define RT_CL_SAMPLE_ARRAY_LENGTH	5

# define RT_CL_TRACING_MOD			rt_tracing_mod_rt

# define RT_CL_RM_STEP_LIMIT		128
# define RT_CL_STEP_PART			(RT_F)1.
# define RT_CL_RM_MAX_DISTANCE		200

# define TEXTURE_MAX_NUMBER			16
# define TEXTURE_MAX_WIDTH			1024
# define TEXTURE_MAX_HEIGHT			1024
# define TEXTURE_MAX_SIZE			TEXTURE_MAX_WIDTH * TEXTURE_MAX_HEIGHT
# define TEXTURE_DATA_SIZE			TEXTURE_MAX_SIZE * TEXTURE_MAX_NUMBER

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
