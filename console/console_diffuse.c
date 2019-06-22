#include "console.h"

int					console_diffuse_helper(t_console *me)
{
	if (!ft_strncmp(me->history.string->data, "diffuse", ft_strlen(me->history.string->data)))
	{
		ft_strcpy(me->helper.assumption, "diffuse ");
		me->helper.assumption_index = 8;
	}
	else
		return (0);
	return (1);
}

int					console_diffuse_command(t_console *me)
{
	if (ft_strncmp(me->history.string->data, "diffuse", 7))
		return (0);
	else if (!ft_strncmp(me->history.string->data + 8, "on", 2))
		me->code = diffuse_on;
	else if (!ft_strncmp(me->history.string->data + 8, "off", 3))
		me->code = diffuse_off;
	else
		return (0);
	return (1);
}