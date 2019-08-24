#include "gui_scene_add.h"

char				*gui_scene_add_gen_name(t_gui_scene_add *add)
{
	char 			*result;
	char			*temp;

	result = malloc(32);
	ft_strcpy(result, "New Object No. ");
	temp = ft_itoa(add->gen_name_next);
	ft_strcat(result, temp);
	free(temp);
	return (result);
}