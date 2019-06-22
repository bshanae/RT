#include "console.h"

int					console_reflect_helper(t_console *me)
{
	if (!ft_strncmp(me->history.string->data, "reflect", ft_strlen(me->history.string->data)))
	{
		ft_strcpy(me->helper.assumption, "reflect ");
		me->helper.assumption_index = 8;
	}
	else
		return (0);
	return (1);
}

int					console_reflect_command(t_console *me)
{
	if (ft_strncmp(me->history.string->data, "reflect", 7))
		return (0);
	else if (!ft_strncmp(me->history.string->data + 8, "on", 2))
		me->code = reflect_on;
	else if (!ft_strncmp(me->history.string->data + 8, "off", 3))
		me->code = reflect_off;
	else if (is_dec(me->history.string->data + 8))
	{
		me->code = reflect_value;
		me->value = ft_atoi(me->history.string->data + 8);
	}
	else
		return (0);
	return (1);
}