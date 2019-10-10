/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_types.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:23:38 by sbosmer           #+#    #+#             */
/*   Updated: 2019/10/08 20:53:09 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "json_parse.h"

char		*get_string_in_object(char *json, jsmntok_t *object, char *target)
{
	jsmntok_t	*pos;

	pos = find_by_string(json, object, target);
	if (!pos)
		return (NULL);
	if (pos->type == JSMN_STRING && pos->size == 0)
		return (get_raw(json, *pos));
	return (NULL);
}

int			*get_bool_in_object(char *json, jsmntok_t *object, char *target)
{
	jsmntok_t	*pos;
	int			*res;

	pos = find_by_string(json, object, target);
	if (!pos)
		return (NULL);
	if (pos->type == JSMN_PRIMITIVE && pos->size == 0)
	{
		if (json[pos->start] != 't' && json[pos->start] != 'f')
			return (NULL);
		res = rt_malloc(sizeof(int));
		if (!res)
			return (NULL);
		*res = (json[pos->start] == 't' ? 1 : 0);
		return (res);
	}
	return (NULL);
}

float		*get_float_in_object(char *json, jsmntok_t *object, char *target)
{
	jsmntok_t	*pos;
	float		res;
	float		*out_f;

	pos = find_by_string(json, object, target);
	if (!pos)
		return (NULL);
	if (token_is_number(json, pos))
	{
		res = atof(json + pos->start);
		out_f = rt_malloc(sizeof(float));
		if (!out_f)
			return (NULL);
		*out_f = res;
		return (out_f);
	}
	return (NULL);
}

int			*get_int_in_object(char *json, jsmntok_t *object, char *target)
{
	int		*res;
	float	*val;

	val = get_float_in_object(json, object, target);
	res = rt_malloc(sizeof(int));
	if (!val || !res)
		return (NULL);
	*res = (int)*val;
	free(val);
	return (res);
}

t_vector3	*get_vector_in_object(char *json, jsmntok_t *object, char *target)
{
	jsmntok_t	*pos;
	t_vector3	res;
	t_vector3	*out_v;

	pos = find_by_string(json, object, target);
	if (!pos)
		return (NULL);
	if (pos->type == JSMN_ARRAY && pos->size == 3)
	{
		if (token_is_number(json, pos + 1) && token_is_number(json, pos + 2)
			&& token_is_number(json, pos + 3))
		{
			res.x = atof(json + pos[1].start);
			res.y = atof(json + pos[2].start);
			res.z = atof(json + pos[3].start);
			out_v = rt_malloc(sizeof(t_vector3));
			if (!out_v)
				return (NULL);
			*out_v = res;
			return (out_v);
		}
	}
	return (NULL);
}
