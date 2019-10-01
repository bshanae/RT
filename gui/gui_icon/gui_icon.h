/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_icon.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:35:35 by bshanae           #+#    #+#             */
/*   Updated: 2019/10/01 18:35:36 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUI_ICON_H
# define GUI_ICON_H

# include "rt_parameters.h"
# include "rt_sources_gui.h"

# include "libft_standart.h"

# include <gtk/gtk.h>

typedef struct		s_pair_i
{
	int				first;
	int				second;
}					t_pair_i;

void				gui_icon_load
					(GtkBuilder *builder, CHAR_REF image_name,
					CHAR_REF path_to_file, t_pair_i size);
void				gui_icon_load_all(GtkBuilder *builder);

#endif
