#ifndef JSON_PARSE
# define JSON_PARSE

# define JSMN_HEADER

# include "libft_ft_printf.h"
# include "error_framework.h"
# include "jsmn.h"

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>

# include "material.h"
# include "material_list.h"

typedef struct	s_vector3
{
	float		x;
	float		y;
	float		z;
	float       w;
}				t_vector3;

typedef struct	s_parse_object
{
	t_vector3	*val_v1;
	t_vector3	*val_v2;
	char		*val_s1;
	char		*val_s2;
	char		*val_s3;
	float		*val_f1;
	float		*val_f2;
	int			*val_i1;
	int			*val_i2;
	t_vector3	v1;
	t_vector3	v2;
	float		f1;
	float		f2;
	int			i1;
	int			i2;
	int			i3;
	char		*name;
	t_material	material;
	char		*texture;
}				t_obj;

void		load_scene(void *data, const char *path);

char		*read_file(const char *path);
int			ft_strequ(char const *s1, char const *s2);

jsmntok_t	*next_item(jsmntok_t *tokens);
char		*get_string_in_object(char *json, jsmntok_t *object, char *target);
t_vector3	*get_vector_in_object(char *json, jsmntok_t *object, char *target);
float		*get_float_in_object(char *json, jsmntok_t *object, char *target);
int			*get_int_in_object(char *json, jsmntok_t *object, char *target);
int			*get_bool_in_object(char *json, jsmntok_t *object, char *target);
int			*get_int_in_onject(char *json, jsmntok_t *object, char *target);
t_material	decide_material(char *mat_name);

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
void		parse_settings(void *data, char *json, jsmntok_t *tokens);

#endif