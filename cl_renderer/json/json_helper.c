#define JSMN_HEADER
#include "jsmn.h"
#include "json_parse.h"

t_material	decide_material(char *mat_name)
{
	if (ft_strequ(mat_name, "light"))
		return (MATERIAL_LIGHT);
	else if (ft_strequ(mat_name, "red"))
		return (MATERIAL_RED);
	else if (ft_strequ(mat_name, "green"))
		return (MATERIAL_GREEN);
	else if (ft_strequ(mat_name, "light basic"))
		return (MATERIAL_LIGHT_BASIC);
	else if (ft_strequ(mat_name, "light ambient"))
		return (MATERIAL_LIGHT_AMBIENT);
	else if (ft_strequ(mat_name, "mirror"))
		return (MATERIAL_MIRROR);
	else if (ft_strequ(mat_name, "glass"))
		return (MATERIAL_GLASS);
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

char	token_is_number(char *json, jsmntok_t *token)
{
	char	sym;

	if (token->type != JSMN_PRIMITIVE)
		return (0);
	sym = json[token->start];
	if ((sym >= '0' && sym <= '9') || sym == '+' || sym == '-')
		return (1);
	return (0);
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
	if (token_is_number(json, pos))
	{
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
		if (token_is_number(json, pos + 1) && token_is_number(json, pos + 2) && token_is_number(json, pos + 3))
		{
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
