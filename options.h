#ifndef OPTIONS_H
# define OPTIONS_H

# define WINDOW_WIDTH			720
# define WINDOW_HEIGHT			480

# define FOCUS_EFFECT			0
# define PIXEL_JITTERING		1

# define QUIT_AFTER_SAMPLING	0
# define RENDER_PROGRESS		2

# define SAMPLES				128
# define PATH_DEPTH				16
# define RUSSIAN_DEPTH			8
# define LIGHT_SAMPLING			1
# define SRGB					1

# define UPLOAD_INTERVAL		1

# define INTERSECTION_MIN		0.00001f
# define INTERSECTION_MAX		INFINITY

# define BACKGROUND				(t_vector3){.4, .4, .4}

# define SHAPE_DATA_CAPACITY	48

# define SHAPE_ID_SPHERE		0
# define SHAPE_ID_PLANE			1

# define SCENE_SHAPES_CAPACITY	64
# define SCENE_LIGHTS_CAPACITY	8

# define MESH_RESIZE			.35
# define MESH_SHIFT				(t_vector3){0., 2., 8.}
# define MESH_ROTATE_X			1.
# define MESH_ROTATE_Y			0.5

#endif
