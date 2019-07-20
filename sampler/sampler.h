#ifndef SAMPLER_H
# define SAMPLER_H

# include "options.h"

# include "vector3.h"

# include <stdlib.h>

t_vector3			sampler_cosine(VECTOR3_REF normal);

t_vector3			sampler_uniform(VECTOR3_REF normal, float *cosine);

t_vector3			sampler_transform(VECTOR3_REF normal, VECTOR3_REF sample);

#endif
