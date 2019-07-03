#include "rp.h"

int					rp_key_press(int key, t_rp *rp)
{
	if (key == KEY_ESC)
		rp_exit(rp);
	else if (key == KEY_ENTER)
		rp_render(rp);
	return (0);
}

int					rp_exit(t_rp *rp)
{
	rp_delete(&rp);
	exit(0);
}
