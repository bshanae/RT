/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_ft_printf.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 13:31:10 by bshanae           #+#    #+#             */
/*   Updated: 2019/06/30 11:09:53 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_FT_PRINTF_H
# define LIBFT_FT_PRINTF_H

# include <stdarg.h>

# include "libft_standart.h"
# include "libft_vector.h"

/*
********************************************************************************
**							UTILS
********************************************************************************
*/

int							is_digit
	(const char *c);

void						print_bits
	(unsigned long long value, u_int len, int endl);

double						safe_atof
	(const char *str);

char						get_digit
	(int i, int is_upper);

void						fast_char_out
	(int fd, char c, int len);

/*
********************************************************************************
**							LONG
********************************************************************************
*/

typedef struct				s_long
{
	t_vector				vector;
	int						length;
}							t_long;

t_long						long_create(u_int init_value);

void						long_destroy(t_long *me);

char						*long_at(t_long *me, int index);

void						long_push_back(t_long *me, u_char value);

void						long_print(t_long *me);

void						long_add(t_long *me, u_int n);

void						long_add_long(t_long *me, t_long *other);

void						long_multiply(t_long *me, u_int n);

/*
********************************************************************************
**							FTP_BUFFER_DEFINITION
********************************************************************************
*/

typedef struct				s_ftp_buffer
{
	const char				*extern_begin;
	const char				*extern_end;
	char					*begin;
	char					*end;
	char					*iter;
	int						chars_read;
	int						fd;
}							t_ftp_buffer;

# define FTP_BUFF_SIZE		32000

/*
********************************************************************************
**							FTP_BUFFER_MAIN
********************************************************************************
*/

int							buffer_init
	(t_ftp_buffer *me, const char *extern_begin);

void						buffer_reset
	(t_ftp_buffer *me, const char *extern_begin);

/*
********************************************************************************
**							FTP_BUFFER_FUNCTIONS
********************************************************************************
*/

void						buffer_out
	(t_ftp_buffer *me);

void						buffer_extern_in
	(t_ftp_buffer *me);

void						buffer_custom_in_char
	(t_ftp_buffer *me, char c, int len);

void						buffer_custom_in_str
	(t_ftp_buffer *me, char *str);

/*
********************************************************************************
**							FTP_BUFFER_FUNCTIONS
********************************************************************************
*/

void						buffer_out
	(t_ftp_buffer *me);

void						buffer_extern_in
	(t_ftp_buffer *me);

void						buffer_custom_in_char
	(t_ftp_buffer *me, char c, int len);

void						buffer_custom_in_str
	(t_ftp_buffer *me, char *str);

/*
********************************************************************************
**							FTP_CONTROL_DEFINITION
********************************************************************************
*/

# define FTP_ERR_ALLOC		-1
# define FTP_ERR_FORMAT		-2
# define FTP_ERR_INTERNAL	-3

# define FTP_STR_NUM_SIZE	30

# define FTP_RED			"\x1B[31m"
# define FTP_GREEN			"\x1B[32m"
# define FTP_YELLOW			"\x1B[33m"
# define FTP_BLUE			"\x1B[34m"
# define FTP_MAGENTA		"\x1B[35m"
# define FTP_CYAN			"\x1B[36m"
# define FTP_PURPLE			"\033[35m"
# define FTP_BOLD			"\033[1m"
# define FTP_UNDERLINE		"\033[4m"
# define FTP_RESET			"\x1B[0m"

typedef enum				e_ftp_size
{
	ftp_size_undef,
	ftp_size_hh,
	ftp_size_h,
	ftp_size_default,
	ftp_size_l,
	ftp_size_ll,
	ftp_size_L
}							t_ftp_size;

typedef enum				e_ftp_type
{
	ftp_type_undef,
	ftp_type_d,
	ftp_type_i,
	ftp_type_b,
	ftp_type_u,
	ftp_type_o,
	ftp_type_x,
	ftp_type_X,
	ftp_type_p,
	ftp_type_f,
	ftp_type_c,
	ftp_type_s,
	ftp_type_other
}							t_ftp_type;

typedef struct				s_ftp_flags
{
	int						minus;
	int						plus;
	int						space;
	int						zero;
	int						hash;
}							t_ftp_flags;

typedef struct				s_ftp_data
{
	unsigned long long		whole;
	int						whole_sign;
	char					whole_str[FTP_STR_NUM_SIZE];
	long double				real;
}							t_ftp_data;

typedef struct				s_ftp_format
{
	t_ftp_flags				flags;
	int						width;
	int						precision;
	t_ftp_size				size;
	t_ftp_type				type;
	t_ftp_data				data;
}							t_ftp_format;

typedef struct				s_ftp_color
{
	char					str[10];
	int						is_const;
}							t_ftp_color;

typedef struct				s_ftp_control
{
	t_ftp_buffer			buffer;
	va_list					*arg_ptr;
	t_ftp_format			format;
	t_ftp_color				color;
}							t_ftp_control;

/*
********************************************************************************
**							FTP_CONTROL_FUNCTIONS
********************************************************************************
*/

int							ftp_control_init
	(t_ftp_control *me, const char *extern_begin, va_list *arg_ptr);

void						ftp_control_format_reset
	(t_ftp_control *me);

int							ftp_control_format_run
	(t_ftp_control *me);

void						ftp_control_style
	(t_ftp_control *me);

void						ftp_control_style_clean
	(t_ftp_control *me);

/*
********************************************************************************
**							FTP_FORMAT_DATA
********************************************************************************
*/

void						ftp_format_data
	(t_ftp_control *ctrl);

void						ftp_format_data_abs
	(long long value, t_ftp_control *ctrl);

int							ftp_format_data_in_default
	(t_ftp_control *ctrl);

int							ftp_format_data_in_short
	(t_ftp_control *ctrl);

int							ftp_format_data_in_s_short
	(t_ftp_control *ctrl);

int							ftp_format_data_in_long
	(t_ftp_control *ctrl);

int							ftp_format_data_in_l_long
	(t_ftp_control *ctrl);

int							ftp_format_data_in_l_double
	(t_ftp_control *ctrl);

/*
********************************************************************************
**							FTP_FORMAT_IN
********************************************************************************
*/

void						ftp_format_in(t_ftp_control *ctrl);

int							ftp_format_in_flags_like(const char *c);

void						ftp_format_in_flags(t_ftp_control *ctrl);

int							ftp_format_in_width_like(const char *c);

void						ftp_format_in_width(t_ftp_control *ctrl);

int							ftp_format_in_precision_like(const char *c);

void						ftp_format_in_precision(t_ftp_control *ctrl);

int							ftp_format_in_size_like(const char *c);

void						ftp_format_in_size(t_ftp_control *ctrl);

int							ftp_format_in_type_like(const char *c);

void						ftp_format_in_type(t_ftp_control *ctrl);

void						ftp_format_in_type_add(t_ftp_control *ctrl);

int							ftp_format_in_additional(t_ftp_control *ctrl);

/*
********************************************************************************
**							FTP_WHITESPACES
********************************************************************************
*/

typedef struct				s_ftp_whitespaces
{
	int						prec_num;
	int						wid_num;
	char					wid_type;
}							t_ftp_whitespaces;

/*
********************************************************************************
**							FTP_FORMAT_OUT_WHOLE
********************************************************************************
*/

typedef struct				s_whole_params
{
	unsigned long long		copy;
	int						base;
	int						is_upper;
	char					spec_char[3];
	int						spec_len;
	int						num_len;
}							t_ftp_whole_params;

void						ftp_format_out_whole
	(t_ftp_control *ctrl);

void						ftp_format_out_whole_init
	(t_ftp_whole_params *whole, t_ftp_control *ctrl);

void						ftp_format_out_whole_process
	(t_ftp_control *ctrl, t_ftp_whole_params *whole);

void						ftp_format_out_whole_out
	(t_ftp_whole_params *whole, t_ftp_control *ctrl);

/*
********************************************************************************
**							FTP_FORMAT_OUT_REAL
********************************************************************************
*/

typedef enum				e_round_type
{
	round_down,
	round_up,
	round_to_even
}							t_round_type;

typedef struct				s_real_memory
{
	u_long					mantissa : 64;
	u_int					exponent : 15;
	u_int					sign : 1;
}							t_real_memory;

typedef union				u_real_represent
{
	long double				real;
	t_real_memory			memory;
}							t_real_represent;

typedef struct				s_real_exception
{
	int						is_present;
	char					data[5];
	int						length;
}							t_real_exception;

typedef struct				s_real_long
{
	t_long					data;
	int						length;
}							t_real_long;

typedef struct				s_real_sign
{
	char					data[2];
	int						length;
}							t_real_sign;

typedef struct				s_params_real
{
	t_real_represent		represent;
	int						extract_exponent;
	t_real_sign				sign;
	int						force_point;
	t_real_long				whole;
	t_real_long				fract;
	t_real_exception		exception;
}							t_real_params;

int							ftp_format_out_real
	(t_ftp_control *ctrl);

int							ftp_format_out_real_init
	(t_real_params *real, t_ftp_control *ctrl, t_ftp_whitespaces *ws);

void						ftp_format_out_real_exceptions
	(t_real_params *real);

void						ftp_format_out_real_convert
	(t_real_params *real);

int							ftp_format_out_real_out
	(t_ftp_buffer *buff, t_real_params *real, int fract_limit);

void						ftp_format_out_real_round
	(t_real_params *real, int fract_limit);

/*
********************************************************************************
**							FTP_FORMAT_OUT
********************************************************************************
*/

int							ftp_format_out(t_ftp_control *ctrl);

void						ftp_format_out_char(t_ftp_control *ctrl);

void						ftp_format_out_str(t_ftp_control *ctrl);

void						ftp_format_out_ptr(t_ftp_control *ctrl);

/*
********************************************************************************
**							FT
********************************************************************************
*/

int							ft_printf(const char *format, ...);

#endif
