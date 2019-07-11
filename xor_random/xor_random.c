#include "xor_random.h"

#include <stdlib.h>

float 						xor_random(void)
{
	static t_random_state	state;

	if (!state.i)
		state.i = time(NULL);
	return (drand48());
	state.i ^= state.i << 13u;
	state.i ^= state.i >> 17u;
	state.i ^= state.i << 5u;
	return (fmodf(state.f, 1.));
}
