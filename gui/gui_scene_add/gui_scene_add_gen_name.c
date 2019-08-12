#include "gui_scene_add.h"

char				*gui_scene_add_gen_name(t_gui_scene_add *add)
{
	char 			*result;
	char			*temp;

	result = malloc(32);
	ft_strcpy(result, "new_object_");
	temp = ft_itoa(add->free_name_id);
	ft_strcat(result, temp);
	free(temp);
	return (result);
}