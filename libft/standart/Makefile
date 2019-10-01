# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshanae <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 21:32:19 by bshanae           #+#    #+#              #
#    Updated: 2019/05/13 21:36:14 by bshanae          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = standart

FUNC_INFO = ${info [Libft] : $1}

SRC_LIST = ./sources_list.txt

FILES = $(shell cat $(SRC_LIST))

SRC_DIR = ./sources_*/
OBJ_DIR = ./objects/

SRC = $(addprefix $(SRC_DIR), $(FILES))
OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

INCL = -I ../includes/

COMP = @gcc -Wall -Wextra -Werror $(INCL)

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJ)

$(OBJ_DIR) :
	${call FUNC_INFO,Creating folder for objects}
	@mkdir $(OBJ_DIR)

$(DEP_DIR) :
	${call FUNC_INFO,Creating folder for dependencies}
	@mkdir $(DEP_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(DEP_DIR)%.d
	${call FUNC_INFO,Building C object $@}

clean :
	${call FUNC_INFO,Deleting objects}
	@rm -rf $(OBJ_DIR)

re : clean $(NAME)

.PHONY : clean re

