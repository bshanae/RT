# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshanae <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 20:52:08 by bshanae           #+#    #+#              #
#    Updated: 2019/05/23 14:52:54 by bshanae          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =																\
	./sources/ft_printf.c											\
	./sources/ftp_buffer/ftp_buffer_functions.c						\
	./sources/ftp_buffer/ftp_buffer_main.c							\
	./sources/ftp_control/ftp_control_definition.c					\
	./sources/ftp_control/ftp_control_functions.c					\
	./sources/ftp_control/ftp_control_functions_style.c				\
	./sources/ftp_format_data/ftp_format_data.c						\
	./sources/ftp_format_data/ftp_format_data_default.c				\
	./sources/ftp_format_data/ftp_format_data_long.c				\
	./sources/ftp_format_data/ftp_format_data_short.c				\
	./sources/ftp_format_in/ftp_format_additional.c					\
	./sources/ftp_format_in/ftp_format_in.c							\
	./sources/ftp_format_in/ftp_format_in_flags.c					\
	./sources/ftp_format_in/ftp_format_in_precision.c				\
	./sources/ftp_format_in/ftp_format_in_size.c					\
	./sources/ftp_format_in/ftp_format_in_type.c					\
	./sources/ftp_format_in/ftp_format_in_width.c					\
	./sources/ftp_format_out/ftp_format_out.c						\
	./sources/ftp_format_out/ftp_format_out_char.c					\
	./sources/ftp_format_out/ftp_format_out_ptr.c					\
	./sources/ftp_format_out/ftp_format_out_str.c					\
	./sources/ftp_format_out_real/format_out_real_exceptions.c		\
	./sources/ftp_format_out_real/ftp_format_out_real.c				\
	./sources/ftp_format_out_real/ftp_format_out_real_convert.c		\
	./sources/ftp_format_out_real/ftp_format_out_real_init.c		\
	./sources/ftp_format_out_real/ftp_format_out_real_out.c			\
	./sources/ftp_format_out_real/ftp_format_out_real_round.c		\
	./sources/ftp_format_out_whole/ftp_format_out_whole.c			\
	./sources/ftp_format_out_whole/ftp_format_out_whole_init.c		\
	./sources/ftp_format_out_whole/ftp_format_out_whole_out.c		\
	./sources/ftp_format_out_whole/ftp_format_out_whole_process.c	\
	./sources/long/long_basic.c										\
	./sources/long/long_functions.c									\
	./sources/utils/utils.c

OBJ_DIR = ./objects/

OBJ_PRE = $(notdir $(SRC:.c=.o))
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_PRE))

INCL_DIR  = ../includes/

INCL = $(addprefix -I, $(INCL_DIR))

COMP = gcc -Wall -Wextra -Werror -c

define move_file
	mv $(1) $(addprefix $(OBJ_DIR), $(1))
	echo "moving$(1) to $(addprefix $(OBJ_DIR), $(1))"
endef

all : $(OBJ)

$(OBJ) : 	
	mkdir -p $(OBJ_DIR)
	@$(COMP) $(INCL) $(SRC)
	@$(foreach obj,$(OBJ_PRE),$(call move_file, $(obj));)

clean :
	rm -rf $(OBJ_DIR)

re : clean $(NAME)

.PHONY : all clean re
