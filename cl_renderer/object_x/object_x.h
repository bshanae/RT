#ifndef OBJECT_DATA_H
# define OBJECT_DATA_H

# include "rt_cl_include.h"
# include "rt_float.h"

typedef struct		s_object_sphere
{
    RT_F4_API		position;
    RT_F			radius;
}					t_object_sphere;

typedef struct		s_object_plane
{
    RT_F4_API		position;
    RT_F4_API		normal;
}					t_object_plane;

typedef struct 		s_object_cone
{
    RT_F4_API		top;
    RT_F4_API		bottom;
    RT_F4_API		axis;
    RT_F 			radius;
    RT_F          	tangent;
}					t_object_cone;

typedef struct 		s_object_cylinder
{
    RT_F4_API		top;
    RT_F4_API		bottom;
    RT_F4_API		axis;
    RT_F 			radius;
}					t_object_cylinder;

#endif
