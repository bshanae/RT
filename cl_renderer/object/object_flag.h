/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_flag.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 12:54:47 by ashari            #+#    #+#             */
/*   Updated: 2019/10/17 13:59:27 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_FLAG_H
# define OBJECT_FLAG_H

# define RT_OBJECT_MOVE_A			0b00000000000000000000000000000001u
# define RT_OBJECT_MOVE_B			0b00000000000000000000000000000010u
# define RT_OBJECT_MOVE_C			0b00000000000000000000000000000100u

# define RT_OBJECT_RT				0b00000000000000000000000000001000u
# define RT_OBJECT_RM				0b00000000000000000000000000010000u

# define RT_OBJECT_PAIR				0b00000000000000000000000000100000u
# define RT_OBJECT_LIMITABLE		0b00000000000000000000000001000000u
# define RT_OBJECT_LIMITING			0b00000000000000000000000010000000u
# define RT_OBJECT_CSG				0b00000000000000000000000100000000u

# define RT_OBJECT_LIGHT			0b00000000000000000000001000000000u

# define RT_OBJECT_HAS_TEXTURE		0b00000000000000000000010000000000u
# define RT_OBJECT_HAS_NO_MATERIAL	0b00000000000000000000100000000000u

#endif
