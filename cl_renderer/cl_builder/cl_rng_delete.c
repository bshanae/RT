#include "cl_builder.h"

void				cl_rng_state_delete(u_long **rng_state)
{
	free(*rng_state);
	*rng_state = NULL;
}
