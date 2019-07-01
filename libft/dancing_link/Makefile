NAME = dancing_link

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
