#include "console.h"


t_vector					vector_create(size_t element_size)
{
	t_vector				vector;

	vector.storage = NULL;
	vector.element_size = 0;
	vector.capacity = 0;
	vector.length = 0;
	vector.storage = malloc(element_size * VECTOR_ALLOC_INIT);
	if (!vector.storage)
		return (vector);
	vector.element_size = element_size;
	vector.capacity = VECTOR_ALLOC_INIT;
	return (vector);
}


t_console			*console_new(void *mlx_ptr, void *win_ptr, void *img_ptr, int *img_data, int width, int height)
{
	t_console		*new;

	if (!(new = (t_console *)malloc(sizeof(t_console))))
		exit(21);
	new->history.data = vector_create(sizeof(t_console_string *));
	if (!new->history.data.capacity)
		exit(21);
	new->history.index = -1;
	new->history.string = NULL;
	new->mlx_ptr = mlx_ptr;
	new->win_ptr = win_ptr;
	new->img_ptr = img_ptr;
	new->img_data = img_data;
	new->win_width = width;
	new->win_height = height;
	new->is_on = 0;
	new->shift = 0;
	new->error = 0;
	ft_strncpy(new->prefix, ": \0", 3);
	return (new);
}

void				console_delete(t_console **me)
{
	u_long 			i;
	t_console_string	*string;

	i = 0;
	while (i < (*me)->history.data.length)
	{
		string = *(t_console_string **)vector_at(&(*me)->history.data, i);
		free(string->data);
		free(string);
		i++;
	}
	vector_destroy(&(*me)->history.data);
	free(*me);
	*me = NULL;
}

void				console_line(t_console *me)
{
	int 			x;
	int 			y;

	y = me->win_width * (me->win_height - 40);
	x = 0;
	while (x < me->win_width)
		me->img_data[y + x++] = WHITE;
}

void 				console_put_image(t_console *me)
{
	mlx_put_image_to_window(me->mlx_ptr, me->win_ptr, me->img_ptr, 0, 0);
}

void				console_display(t_console *me)
{
	console_put_image(me);
	mlx_string_put(me->mlx_ptr, me->win_ptr, PREFIX_INDENT, me->win_height - 30, WHITE, me->prefix);
	if (me->history.string)
		mlx_string_put(me->mlx_ptr, me->win_ptr, STRING_INDENT, me->win_height - 30, WHITE, me->history.string->data);
}

void				console_error(t_console *me, char *message)
{
	me->error = 1;
	ft_bzero(me->history.string->data, 64);
	ft_strcpy(me->history.string->data, message);
	console_display(me);
	ft_bzero(me->history.string->data, 64);
	me->history.string->index = 0;
}

t_console_string	*console_string_new()
{
	t_console_string *new;

	if (!(new = (t_console_string *)malloc(sizeof(t_console_string))))
		exit(21);
	if (!(new->data = (char *)malloc(64)))
		exit(21);
	ft_bzero(new->data, 64);
	new->index = 0;
	new->empty = 1;
	return (new);
}

void				console_load_string(t_console *me)
{
	me->history.string = *(t_console_string **)vector_at(&me->history.data, me->history.index);
}

void				console_launch(t_console *me)
{
	t_console_string *new_string;

	me->is_on = 1;
	console_line(me);
	if (!me->history.string || !me->history.string->empty)
	{
		new_string = console_string_new();
		vector_push_back(&me->history.data, &new_string);
		me->history.index++;
		console_load_string(me);
		console_display(me);
	}
	me->code = none;
	me->value = 0;
}

int					console_key_command(t_console *me, int key)
{
	if (me->error)
	{
		me->error = 0;
		console_display(me);
	}
	else if (key == KEY_ESC)
		me->is_on = 0;
	else if (key == KEY_DEL)
		console_unget(me);
	else if (key == KEY_ENTER)
		console_perform(me);
	else if (key == KEY_TAB)
		console_help(me);
	else if (key == KEY_UP_1 || key == KEY_UP_2)
	{
		if (me->history.index > 0)
		{
			me->history.index--;
			console_load_string(me);
			console_display(me);
		}
	}
	else if (key == KEY_DOWN_1 || key == KEY_DOWN_2)
	{
		if (me->history.index != me->history.data.length)
		{
			me->history.index++;
			console_load_string(me);
			console_display(me);
		}
	}
	else
		return (0);
	return (1);
}

int					console_get(t_console *me, int key)
{
	if (console_key_command(me, key))
		return (me->code != none);
	if (me->history.string->index != 64)
	{
		me->history.string->data[me->history.string->index++] = console_translate(me, key);
		console_display(me);
		me->history.string->empty = 0;
	}
	return (0);
}

void				console_unget(t_console *me)
{
	if (me->history.string->index != -1)
	{
		me->history.string->data[--me->history.string->index] = '\0';
		console_display(me);
	}
	else
		me->history.string->empty = 1;
}

void				console_help(t_console *me)
{
	me->helper.conflict = 0;
	me->helper.conflict += console_reflect_helper(me);
	me->helper.conflict += console_refract_helper(me);
	me->helper.conflict += console_diffuse_helper(me);
	me->helper.conflict += console_specular_helper(me);
	me->helper.conflict += console_shadows_helper(me);
	me->helper.conflict += console_tshadows_helper(me);
	me->helper.conflict += console_reset_helper(me);
	me->helper.conflict += console_parallel_helper(me);
	if (me->helper.conflict != 1)
		return ;
	ft_strcpy(me->history.string->data, me->helper.assumption);
	me->history.string->index = me->helper.assumption_index;
	console_display(me);
}

int					console_perform(t_console *me)
{
	if (console_reflect_command(me));
	else if (console_refract_command(me));
	else if (console_diffuse_command(me));
	else if (console_specular_command(me));
	else if (console_shadows_command(me));
	else if (console_tshadows_command(me));
	else if (console_reset_command((me)));
	else if (console_parallel_command(me));
	else
	{
		console_error(me, "unknown command");
		return (0);
	}
	me->is_on = 0;
	return (1);
}