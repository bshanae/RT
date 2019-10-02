#ifndef JSON_PARSE
# define JSON_PARSE

# define JSMN_HEADER

# include "jsmn.h"

# include "error_framework.h"
# include "material.h"
# include "material_list.h"

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include "cl_renderer.h"

typedef struct	s_argb
{
	u_char		b;
	u_char		g;
	u_char		r;
	u_char		a;
}				t_argb;

typedef union	u_color
{
	uint		hex;
	t_argb		rgb;
}				t_color2;

typedef struct	s_vector3
{
	float		x;
	float		y;
	float		z;
	float       w;
}				t_vector3;

typedef struct	s_macro_hack
{
	const char	*name;
	t_material	material;
}				t_default;

void		json_load(void *data, const char *path);

char		*read_file(const char *path);
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t len);

jsmntok_t	*next_item(jsmntok_t *tokens);
char		*get_string_in_object(char *json, jsmntok_t *object, char *target);
t_vector3	get_vector_in_object(char *json, jsmntok_t *object, char *target, t_vector3 def);
float		get_float_in_object(char *json, jsmntok_t *object, char *target, float def);
int			get_int_in_object(char *json, jsmntok_t *object, char *target, int def);
int			get_bool_in_object(char *json, jsmntok_t *object, char *target, int def);
t_material	decide_material(char *mat_name);
void		load_shared(void *data, char *json, jsmntok_t *object, t_default def);

void		parse_camera(void *data, char *json, jsmntok_t *tokens);
void		parse_sphere(void *data, char *json, jsmntok_t *tokens);
void		parse_plane(void *data, char *json, jsmntok_t *tokens);
void		parse_cone(void *data, char *json, jsmntok_t *tokens);
void		parse_cylinder(void *data, char *json, jsmntok_t *tokens);
void		parse_box(void *data, char *json, jsmntok_t *tokens);
void		parse_paraboloid(void *data, char *json, jsmntok_t *tokens);
void		parse_moebius(void *data, char *json, jsmntok_t *tokens);
void		parse_torus(void *data, char *json, jsmntok_t *tokens);
void		parse_mandelbulb(void *data, char *json, jsmntok_t *tokens);
void		parse_julia(void *data, char *json, jsmntok_t *tokens);
void		parse_ambient(void *data, char *json, jsmntok_t *tokens);
void		parse_point(void *data, char *json, jsmntok_t *tokens);
void		parse_direct(void *data, char *json, jsmntok_t *tokens);
void		parse_explosion(void *data, char *json, jsmntok_t *tokens);
void		parse_perfcube(void *data, char *json, jsmntok_t *tokens);
void        parse_csg(void *data, char *json, jsmntok_t *tokens);
void		parse_settings(void *data, char *json, jsmntok_t *tokens);

#endif