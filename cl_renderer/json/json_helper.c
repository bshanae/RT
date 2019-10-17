/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:23:41 by sbosmer           #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define JSMN_HEADER
#include "jsmn.h"
#include "json_parse.h"

char		*get_raw(char *json, jsmntok_t token)
{
	char		*res;
	const int	len = token.end - token.start;

	res = rt_malloc(sizeof(char) * (len + 1));
	ft_strncpy(res, json + token.start, len);
	res[len] = 0;
	return (res);
}

char		token_is_number(char *json, jsmntok_t *token)
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

void		free_box(t_obj *box)
{
	(box->val_v1 ? free(box->val_v1) : 1);
	(box->val_v2 ? free(box->val_v2) : 1);
	(box->val_s1 ? free(box->val_s1) : 1);
	(box->val_s2 ? free(box->val_s2) : 1);
	(box->val_s3 ? free(box->val_s3) : 1);
	(box->val_s4 ? free(box->val_s4) : 1);
	(box->val_s5 ? free(box->val_s5) : 1);
	(box->val_f1 ? free(box->val_f1) : 1);
	(box->val_f2 ? free(box->val_f2) : 1);
	(box->val_i1 ? free(box->val_i1) : 1);
	(box->val_i2 ? free(box->val_i2) : 1);
	(box->val_i3 ? free(box->val_i3) : 1);
	(box->name ? free(box->name) : 1);
	(box->texture ? free(box->texture) : 1);
	ft_bzero(box, sizeof(t_obj));
}
