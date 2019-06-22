#include "console.h"

int					console_tshadows_helper(t_console *me)
{
	if (!ft_strncmp(me->history.string->data, "tshadows", ft_strlen(me->history.string->data)))
	{
		ft_strcpy(me->helper.assumption, "tshadows ");
		me->helper.assumption_index = 9;
	}
	else
		return (0);
	return (1);
}

int					console_tshadows_command(t_console *me)
{
	if (ft_strncmp(me->history.string->data, "tshadows", 8))
		return (0);
	else if (!ft_strncmp(me->history.string->data + 9, "on", 2))
		me->code = tshadows_on;
	else if (!ft_strncmp(me->history.string->data + 9, "off", 3))
		me->code = tshadows_off;
	else
		return (0);
	return (1);
}