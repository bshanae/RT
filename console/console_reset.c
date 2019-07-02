#include "console.h"

int					console_reset_helper(t_console *me)
{
	if (!ft_strncmp(me->history.string->data, "reset", ft_strlen(me->history.string->data)))
	{
		ft_strcpy(me->helper.assumption, "reset");
		me->helper.assumption_index = 5;
	}
	else
		return (0);
	return (1);
}

int					console_reset_command(t_console *me)
{
	if (!ft_strncmp(me->history.string->data, "reset", 7))
		me->code = reset;
	else
		return (0);
	return (1);
}