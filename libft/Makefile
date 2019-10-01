SRC_LIST_TEMPL = sources_list.txt
SRC_FILES_GEN = $(shell cat $(addprefix $(1), $(SRC_LIST_TEMPL)))

SRC_DIR_GEN = $(addprefix $1, sources/)
SRC_DIR_ADD = $(addprefix $(call SRC_DIR_GEN,$1), $2)
SRC_GEN = $(call SRC_DIR_ADD,$1,$(call SRC_FILES_GEN,$1))

OBJ_DIR_GEN = $(addprefix $1, objects/)
OBJ_DIR_ADD = $(addprefix $(call OBJ_DIR_GEN,$1), $2)
OBJ_GEN_PRE = $(call OBJ_DIR_ADD,$1,$(call SRC_FILES_GEN,$1))
OBJ_GEN = $(patsubst %.c,%.o,$(call OBJ_GEN_PRE,$1))

STD_DIR = ./standart/
STD_SRC = $(addprefix "./standart/sources_*/",$(call SRC_FILES_GEN,$(STD_DIR)))
STD_OBJ = $(call OBJ_GEN,$(STD_DIR))
STD_INCL = ./includes/libft_standart.h

NAME = libft.a

LIB_SRC = $(STD_SRC)

LIB_OBJ = $(STD_OBJ)

LIB_INCL = $(STD_INCL)

all : $(NAME)

$(NAME) : $(LIB_OBJ) $(LIB_INCL)
	@echo ">>> creating library <<<"
	@ar rc $(NAME) $(LIB_OBJ)
	@ranlib $(NAME)

$(STD_OBJ) : $(STD_SRC)
	@echo ">>> compiling standart functions <<<"
	@make -C $(STD_DIR)

clean : 
	@echo ">>> deleting standart functions objects <<<"
	@make clean -C $(STD_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
