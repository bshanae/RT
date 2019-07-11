#ifndef XOR_RANDOM_H
# define XOR_RANDOM_H

# include "time.h"
# include "math.h"

typedef	union 		u_random_seed
{
	unsigned int	i;
	float 			f;
}					t_random_state;

float 				xor_random(void);

#endif
