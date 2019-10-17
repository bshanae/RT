/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_parse.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 20:51:37 by sbosmer           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_PARSE_H
# define JSON_PARSE_H

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

typedef struct	s_parse_object
{
	RT_F4_API	*val_v1;
	RT_F4_API	*val_v2;
	char		*val_s1;
	char		*val_s2;
	char		*val_s3;
	char		*val_s4;
	char		*val_s5;
	RT_F		*val_f1;
	RT_F		*val_f2;
	int			*val_i1;
	int			*val_i2;
	int			*val_i3;
	RT_F4_API	v1;
	RT_F4_API	v2;
	RT_F		f1;
	RT_F		f2;
	int			i1;
	int			i2;
	int			i3;
	char		*name;
	t_material	material;
	char		*texture;
}				t_obj;

void			json_load(void *data, const char *path);
char			*read_file(const char *path);
int				ft_strequ(char const *s1, char const *s2);
jsmntok_t		*next_item(jsmntok_t *tokens);
jsmntok_t		*find_by_string(char *json, jsmntok_t *object, char *target);
char			token_is_number(char *json, jsmntok_t *token);
void			work_object_1(void *data, char *json,
				jsmntok_t *tokens, char *type);
char			*get_raw(char *json, jsmntok_t token);
char			*get_string_in_object(char *json, jsmntok_t *object,
					char *target);
RT_F4_API		*get_vector_in_object(char *json, jsmntok_t *object,
					char *target);
RT_F			*get_float_in_object(char *json, jsmntok_t *object,
					char *target);
int				*get_int_in_object(char *json, jsmntok_t *object, char *target);
int				*get_bool_in_object(char *json, jsmntok_t *object,
					char *target);
t_material		decide_material(char *mat_name);
void			parse_camera(void *data, char *json, jsmntok_t *tokens);
void			parse_sphere(void *data, char *json, jsmntok_t *tokens);
void			parse_plane(void *data, char *json, jsmntok_t *tokens);
void			parse_cone(void *data, char *json, jsmntok_t *tokens);
void			parse_cylinder(void *data, char *json, jsmntok_t *tokens);
void			parse_box(void *data, char *json, jsmntok_t *tokens);
void			parse_paraboloid(void *data, char *json, jsmntok_t *tokens);
void			parse_moebius(void *data, char *json, jsmntok_t *tokens);
void			parse_torus(void *data, char *json, jsmntok_t *tokens);
void			parse_mandelbulb(void *data, char *json, jsmntok_t *tokens);
void			parse_julia(void *data, char *json, jsmntok_t *tokens);
void			parse_ambient(void *data, char *json, jsmntok_t *tokens);
void			parse_point(void *data, char *json, jsmntok_t *tokens);
void			parse_direct(void *data, char *json, jsmntok_t *tokens);
void			parse_explosion(void *data, char *json, jsmntok_t *tokens);
void			parse_perfcube(void *data, char *json, jsmntok_t *tokens);
void			parse_settings(void *data, char *json, jsmntok_t *tokens);
void			parse_csg(void *data, char *json, jsmntok_t *tokens);
void			free_box(t_obj *box);
void			parse_limited(void *data, char *json, jsmntok_t *tokens);
void			parse_hack_0(t_obj *box, void *data,
					char *json, jsmntok_t *tokens);
void			parse_hack_1(t_obj *box, void *data,
					char *json, jsmntok_t *tokens);

#endif
