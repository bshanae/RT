#ifndef CONSOLE_H
# define CONSOLE_H

# include "libft_vector.h"

# include "mlx_keys.h"

# include "mlx.h"

# define WHITE			0xFFFFFF
# define CHAR_WIDTH		8
# define CHAR_HEIGHT	30
# define PREFIX_INDENT	2 * CHAR_WIDTH
# define STRING_INDENT	4 * CHAR_WIDTH

typedef struct			s_console_string
{
	char 				*data;
	int 				index;
	int 				empty;
}						t_console_string;

typedef struct			s_console_history
{
	t_vector			data;
	u_long 				index;
	t_console_string	*string;
}						t_console_history;

typedef enum			e_console_code
{
	none,
	reflect_on,
	reflect_off,
	reflect_value,
	refract_on,
	refract_off,
	refract_value,
	diffuse_on,
	diffuse_off,
	specular_on,
	specular_off,
	shadows_on,
	shadows_off,
	tshadows_on,
	tshadows_off,
	parallel_on,
	parallel_off,
	reset
}						t_console_code;

typedef struct 			s_console
{
	void				*mlx_ptr;
	void				*win_ptr;
	int 				*img_ptr;
	int					*img_data;
	int 				win_width;
	int 				win_height;
	t_console_history	history;
	int					is_on;
	int 				shift;
	int 				error;
	char 				prefix[3];
	t_console_code		code;
	int 				value;
	struct
	{
		char 			assumption[64];
		int 			assumption_index;
		int 			conflict;
	}					helper;
}						t_console;

t_console				*console_new(void *mlx_ptr, void *win_ptr, void *img_ptr, int *img_data, int width, int height);

void					console_delete(t_console **me);

void					console_launch(t_console *me);

int						console_get(t_console *me, int key);

void					console_unget(t_console *me);

void					console_help(t_console *me);

int						console_perform(t_console *me);

char					console_translate(t_console *me, int key);

int						console_reflect_helper(t_console *me);

int						console_reflect_command(t_console *me);

int						console_refract_helper(t_console *me);

int						console_refract_command(t_console *me);

int						console_specular_helper(t_console *me);

int						console_specular_command(t_console *me);

int						console_diffuse_helper(t_console *me);

int						console_diffuse_command(t_console *me);

int						console_shadows_helper(t_console *me);

int						console_shadows_command(t_console *me);

int						console_tshadows_helper(t_console *me);

int						console_tshadows_command(t_console *me);

int						console_reset_helper(t_console *me);

int						console_parallel_helper(t_console *me);

int						console_parallel_command(t_console *me);

int						console_reset_command(t_console *me);

#endif
