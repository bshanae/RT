#include "console.h"

int					console_specular_helper(t_console *me)
{
	if (!ft_strncmp(me->history.string->data, "specular", ft_strlen(me->history.string->data)))
	{
		ft_strcpy(me->helper.assumption, "specular ");
		me->helper.assumption_index = 9;
	}
	else
		return (0);
	return (1);
}

int					console_specular_command(t_console *me)
{
	if (ft_strncmp(me->history.string->data, "specular", 8))
		return (0);
	else if (!ft_strncmp(me->history.string->data + 9, "on", 2))
		me->code = specular_on;
	else if (!ft_strncmp(me->history.string->data + 9, "off", 3))
		me->code = specular_off;
	else
		return (0);
	return (1);
}