#include "console.h"

int					console_parallel_helper(t_console *me)
{
	if (!ft_strncmp(me->history.string->data, "parallel", ft_strlen(me->history.string->data)))
	{
		ft_strcpy(me->helper.assumption, "parallel ");
		me->helper.assumption_index = 9;
	}
	else
		return (0);
	return (1);
}

int					console_parallel_command(t_console *me)
{
	if (ft_strncmp(me->history.string->data, "parallel", 8))
		return (0);
	else if (!ft_strncmp(me->history.string->data + 9, "on", 2))
		me->code = parallel_on;
	else if (!ft_strncmp(me->history.string->data + 9, "off", 3))
		me->code = parallel_off;
	else
		return (0);
	return (1);
}