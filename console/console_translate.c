#include "console.h"

char			console_translate(t_console *me, int key)
{
	if (key == KEY_SPACE)
		return (' ');
	if (key == KEY_A)
		return ('a' - (me->shift ? 32 : 0));
	if (key == KEY_S)
		return ('s' - (me->shift ? 32 : 0));
	if (key == KEY_D)
		return ('d' - (me->shift ? 32 : 0));
	if (key == KEY_F)
		return ('f' - (me->shift ? 32 : 0));
	if (key == KEY_H)
		return ('h' - (me->shift ? 32 : 0));
	if (key == KEY_G)
		return ('g' - (me->shift ? 32 : 0));
	if (key == KEY_Z)
		return ('z' - (me->shift ? 32 : 0));
	if (key == KEY_X)
		return ('x' - (me->shift ? 32 : 0));
	if (key == KEY_C)
		return ('c' - (me->shift ? 32 : 0));
	if (key == KEY_V)
		return ('v' - (me->shift ? 32 : 0));
	if (key == KEY_B)
		return ('b' - (me->shift ? 32 : 0));
	if (key == KEY_Q)
		return ('q' - (me->shift ? 32 : 0));
	if (key == KEY_W)
		return ('w' - (me->shift ? 32 : 0));
	if (key == KEY_E)
		return ('e' - (me->shift ? 32 : 0));
	if (key == KEY_R)
		return ('r' - (me->shift ? 32 : 0));
	if (key == KEY_Y)
		return ('y' - (me->shift ? 32 : 0));
	if (key == KEY_T)
		return ('t' - (me->shift ? 32 : 0));
	if (key == KEY_O)
		return ('o' - (me->shift ? 32 : 0));
	if (key == KEY_U)
		return ('u' - (me->shift ? 32 : 0));
	if (key == KEY_I)
		return ('i' - (me->shift ? 32 : 0));
	if (key == KEY_P)
		return ('p' - (me->shift ? 32 : 0));
	if (key == KEY_L)
		return ('l' - (me->shift ? 32 : 0));
	if (key == KEY_J)
		return ('j' - (me->shift ? 32 : 0));
	if (key == KEY_K)
		return ('k' - (me->shift ? 32 : 0));
	if (key == KEY_M)
		return ('m' - (me->shift ? 32 : 0));
	if (key == KEY_N)
		return ('n' - (me->shift ? 32 : 0));
	if (key == KEY_0)
		return (me->shift ? ')' : '0');
	if (key == KEY_1)
		return ('1');
	if (key == KEY_2)
		return ('2');
	if (key == KEY_3)
		return ('3');
	if (key == KEY_4)
		return ('4');
	if (key == KEY_5)
		return ('5');
	if (key == KEY_6)
		return ('6');
	if (key == KEY_7)
		return ('7');
	if (key == KEY_8)
		return ('8');
	if (key == KEY_9)
		return (me->shift ? '(' : '9');
	if (key == KEY_TILDA && me->shift)
		return '~';
	return ('*');
}