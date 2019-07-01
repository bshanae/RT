# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshanae <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/13 19:12:47 by bshanae           #+#    #+#              #
#    Updated: 2019/05/14 13:27:45 by bshanae          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btree

SRC_LIST = ./sources_list.txt

FILES = $(shell cat $(SRC_LIST))

SRC_DIR = ./sources/
OBJ_DIR = ./objects/

SRC = $(addprefix $(SRC_DIR), $(FILES))
OBJ = $(addprefix $(OBJ_DIR), $(FILES:.c=.o))

INCL = -I ../includes/

COMP = gcc -Wall -Wextra -Werror $(INCL)

all : $(NAME) 
	
$(NAME) : $(OBJ_DIR) $(OBJ)

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(COMP) -o $@ -c $<

clean : 
	rm -rf $(OBJ_DIR)

re : clean $(NAME)

.PHONY : clean re
