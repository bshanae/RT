/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   json_defaults.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbosmer <sbosmer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 19:20:24 by sbosmer           #+#    #+#             */
/*   Updated: 2019/10/08 19:20:27 by sbosmer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JSON_DEFAULTS_H
# define JSON_DEFAULTS_H

# include "json_parse.h"

# define GLOBAL_MATERIAL MATERIAL_WHITE
# define GLOBAL_POSITION (t_vector3){0., 0., 0.}
# define GLOBAL_TEXTURE "Planet"

# define SETTINGS_USE_RM 0
# define SETTINGS_USE_DOUBLE 0
# define SETTINGS_STEP_PART 1.
# define SETTINGS_STEP_LIMIT 100
# define SETTINGS_ILLUMINATION 1
# define SETTINGS_PT_DEPTH 1
# define SETTINGS_PT_SAMPLE_LIMIT 25
# define SETTINGS_ILLUMINATION_ 0

# define AMBIENT_NAME ""
# define AMBIENT_MATERIAL GLOBAL_MATERIAL
# define AMBIENT_TEXTURE GLOBAL_TEXTURE

# define POINT_NAME ""
# define POINT_MATERIAL MATERIAL_LIGHT
# define POINT_TEXTURE GLOBAL_TEXTURE
# define POINT_POSITION GLOBAL_POSITION

# define DIRECT_NAME ""
# define DIRECT_MATERIAL MATERIAL_LIGHT
# define DIRECT_TEXTURE GLOBAL_TEXTURE
# define DIRECT_DIRECTION (t_vector3){0., -1., 0.}

# define SPHERE_NAME ""
# define SPHERE_MATERIAL GLOBAL_MATERIAL
# define SPHERE_TEXTURE GLOBAL_TEXTURE
# define SPHERE_POSITION GLOBAL_POSITION
# define SPHERE_RADIUS (RT_F)1.

# define PLANE_NAME ""
# define PLANE_MATERIAL GLOBAL_MATERIAL
# define PLANE_TEXTURE GLOBAL_TEXTURE
# define PLANE_POSITION GLOBAL_POSITION
# define PLANE_NORMAL (t_vector3){0., 1., 0.}
# define PLANE_LIMITING 0

# define CONE_NAME ""
# define CONE_MATERIAL GLOBAL_MATERIAL
# define CONE_TEXTURE GLOBAL_TEXTURE
# define CONE_TOP (t_vector3){0., 1., 0.}
# define CONE_BOTTOM (t_vector3){0., 0., 0.}
# define CONE_RADIUS 1.

# define CYLINDER_NAME ""
# define CYLINDER_MATERIAL GLOBAL_MATERIAL
# define CYLINDER_TEXTURE GLOBAL_TEXTURE
# define CYLINDER_TOP (t_vector3){0., 1., 0.}
# define CYLINDER_BOTTOM (t_vector3){0., 0., 0.}
# define CYLINDER_RADIUS 1.

# define BOX_NAME ""
# define BOX_MATERIAL GLOBAL_MATERIAL
# define BOX_TEXTURE GLOBAL_TEXTURE
# define BOX_POSITION GLOBAL_POSITION
# define BOX_SIZE (t_vector3){1., 1., 1.}

# define PARABOLOID_NAME ""
# define PARABOLOID_MATERIAL GLOBAL_MATERIAL
# define PARABOLOID_TEXTURE GLOBAL_TEXTURE
# define PARABOLOID_EXTREMUM (t_vector3){0., 0., 0.}
# define PARABOLOID_AXIS (t_vector3){0., 1., 0.}
# define PARABOLOID_RADIUS 1.

# define MOEBIUS_NAME ""
# define MOEBIUS_MATERIAL GLOBAL_MATERIAL
# define MOEBIUS_TEXTURE GLOBAL_TEXTURE
# define MOEBIUS_POSITION GLOBAL_POSITION
# define MOEBIUS_RADIUS 1.f
# define MOEBIUS_HALFWIDTH .5f

# define TORUS_NAME ""
# define TORUS_MATERIAL GLOBAL_MATERIAL
# define TORUS_TEXTURE GLOBAL_TEXTURE
# define TORUS_POSITION GLOBAL_POSITION
# define TORUS_RADIUS 1.f
# define TORUS_WIDTH .5f

# define MANDELBULB_NAME ""
# define MANDELBULB_MATERIAL GLOBAL_MATERIAL
# define MANDELBULB_TEXTURE GLOBAL_TEXTURE
# define MANDELBULB_POSITION GLOBAL_POSITION
# define MANDELBULB_ITERATIONS 50
# define MANDELBULB_POWER (RT_F)8.

# define JULIA_NAME ""
# define JULIA_MATERIAL GLOBAL_MATERIAL
# define JULIA_TEXTURE GLOBAL_TEXTURE
# define JULIA_POSITION GLOBAL_POSITION
# define JULIA_ITERATIONS 50
# define JULIA_VALUE (t_vector3){.1, .3, .5, .5}

# define CSG_NAME ""
# define CSG_MATERIAL GLOBAL_MATERIAL
# define CSG_TEXTURE GLOBAL_TEXTURE
# define CSG_POSITIVE 0
# define CSG_NEGATIVE 1

# define EXPLOSION_NAME ""
# define EXPLOSION_MATERIAL GLOBAL_MATERIAL
# define EXPLOSION_TEXTURE GLOBAL_TEXTURE
# define EXPLOSION_POSITION GLOBAL_POSITION
# define EXPLOSION_RADIUS 1.f
# define EXPLOSION_NOISE_AMPLITUDE 0.7f

# define PCUBE_NAME ""
# define PCUBE_MATERIAL GLOBAL_MATERIAL
# define PCUBE_TEXTURE GLOBAL_TEXTURE
# define PCUBE_POSITION GLOBAL_POSITION
# define PCUBE_ITERATIONS 3
#endif
