/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_parser_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 15:43:48 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/02 15:43:48 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gui_parser.h"

void				gui_parser_delete(t_gui_parser **parser)
{
	free(*parser);
	*parser = NULL;
}
