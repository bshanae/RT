#include "rp.h"

int					rp_key_press(int key, t_rp *rp)
{
	if (key == KEY_ESC)
		rp_exit(rp);
	return (0);
}

int					rp_exit(t_rp *rp)
{
	rp_delete(&rp);
	exit(0);
}
