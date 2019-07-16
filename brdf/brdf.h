#ifndef BRDF_H
# define BRDF_H

# include "options.h"

# include "intersection.h"

float 				brdf(const t_intersection *intersection, const t_vector3 *sample);

#endif
