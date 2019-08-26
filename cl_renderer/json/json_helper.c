#define JSMN_HEADER
#include "jsmn.h"
#include "json_parse.h"

t_material	decide_material(char *mat_name)
{
	if (ft_strequ(mat_name, "light"))
		return (MATERIAL_LIGHT);
	else if (ft_strequ(mat_name, "none"))
		return (MATERIAL_NONE);
	else if (ft_strequ(mat_name, "red"))
		return (MATERIAL_RED);
	else if (ft_strequ(mat_name, "green"))
		return (MATERIAL_GREEN);
	// else if (ft_strequ(mat_name, "blue"))
	// 	return (MATERIAL_BLUE);
	// else if (ft_strequ(mat_name, "magenta"))
	// 	return (MATERIAL_MAGENTA);
	// else if (ft_strequ(mat_name, "cyan"))
	// 	return (MATERIAL_CYAN);
	// else if (ft_strequ(mat_name, "yellow"))
	// 	return (MATERIAL_YELLOW);
	else
		return (MATERIAL_WHITE);
}

char	*get_raw(char *json, jsmntok_t token)
{
	char		*res;
	const int	len = token.end - token.start + 1;

	res = malloc(sizeof(char) * (len + 1));
	strlcpy(res, json + token.start, len);
	res[len] = 0;
	return (res);
}

jsmntok_t	*next_item(jsmntok_t *tokens)
{
	int		qt;

	qt = tokens->size;
	while (qt)
	{
		tokens++;
		qt += tokens->size;
		qt--;
	}
	return (++tokens);
}

jsmntok_t	*find_by_string(char *json, jsmntok_t *object, char *target)
{
	const int	len = object->size;
	int			qt;
	char		*s;

	object++;
	qt = 0;
	while (qt < len)
	{
		if (object->type == JSMN_STRING && object->size == 1)
		{
			s = get_raw(json, object[0]);
			if (ft_strequ(s, target))
			{
				return (object + 1);
			}
			free(s);
		}
		object = next_item(object);
		qt++;
	}
	return (NULL);
}

char	*get_string_in_object(char *json, jsmntok_t *object, char *target)
{
	jsmntok_t	*pos;

	pos = find_by_string(json, object, target);
	if (!pos)
		return (NULL);
	if (pos->type == JSMN_STRING && pos->size == 0)
		return (get_raw(json, *pos));
	return (NULL);
}

float	*get_float_in_object(char *json, jsmntok_t *object, char *target)
{
	jsmntok_t	*pos;
	float		res;
	float		*out_f;
	// char		*temp;	

	pos = find_by_string(json, object, target);
	if (!pos)
		return (NULL);
	if (pos->type == JSMN_PRIMITIVE)
	{
		//! Check if primitives are actually numbers!
		res = atof(json + pos->start);
		out_f = malloc(sizeof(float));
		if (!out_f)
			return (NULL);
		*out_f = res;
		return (out_f);
	}
	return (NULL);
}

t_vector3	*get_vector_in_object(char *json, jsmntok_t *object, char *target)
{
	jsmntok_t	*pos;
	t_vector3	res;
	t_vector3	*out_v;
	// char		*temp;	

	pos = find_by_string(json, object, target);
	if (!pos)
		return (NULL);
	if (pos->type == JSMN_ARRAY && pos->size == 3)
	{
		if (pos[1].type == JSMN_PRIMITIVE && pos[2].type == JSMN_PRIMITIVE && pos[3].type == JSMN_PRIMITIVE)
		{
			//! Check if primitives are actually numbers!
			res.x = atof(json + pos[1].start);
			res.y = atof(json + pos[2].start);
			res.z = atof(json + pos[3].start);
			out_v = malloc(sizeof(t_vector3));
			if (!out_v)
				return (NULL);
			*out_v = res;
			return (out_v);
		}
	}
	return (NULL);
}
