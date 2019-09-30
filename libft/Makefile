# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bshanae <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/14 13:33:33 by bshanae           #+#    #+#              #
#    Updated: 2019/05/14 16:05:38 by bshanae          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

LIST_DIR = ./list/
LIST_SRC = $(call SRC_GEN,$(LIST_DIR))
LIST_OBJ = $(call OBJ_GEN,$(LIST_DIR))
LIST_INCL = ./includes/libft_list.h

BTREE_DIR = ./btree/
BTREE_SRC = $(call SRC_GEN,$(BTREE_DIR))
BTREE_OBJ = $(call OBJ_GEN,$(BTREE_DIR))
BTREE_INCL = ./includes/libft_btree.h

GNL_DIR = ./gnl/
GNL_SRC = $(call SRC_GEN,$(GNL_DIR))
GNL_OBJ = $(call OBJ_GEN,$(GNL_DIR))
GNL_INCL = ./includes/libft_gnl.h

VECTOR_DIR = ./vector/
VECTOR_SRC = $(call SRC_GEN,$(VECTOR_DIR))
VECTOR_OBJ = $(call OBJ_GEN,$(VECTOR_DIR))
VECTOR_INCL = ./includes/libft_vector.h

FT_PRINTF_DIR = ./ft_printf/
FT_PRINTF_OBJ = ./ft_printf/objects/*.o
FT_PRINTF_INCL = ./includes/libft_ft_printf.h

DANCING_LINK_DIR = ./dancing_link/
DANCING_LINK_SRC = $(call SRC_GEN,$(DANCING_LINK_DIR))
DANCING_LINK_OBJ = $(call OBJ_GEN,$(DANCING_LINK_DIR))
DANCING_LINK_INCL = ./includes/libft_dancing_link.h

QUEUE_DIR = ./queue/
QUEUE_SRC = $(call SRC_GEN,$(QUEUE_DIR))
QUEUE_OBJ = $(call OBJ_GEN,$(QUEUE_DIR))
QUEUE_INCL = ./includes/libft_queue.h

NAME = libft.a

LIB_SRC =					\
	$(STD_SRC)				\
	$(LIST_SRC)				\
	$(BTREE_SRC)			\
	$(GNL_SRC)				\
	$(VECTOR_SRC)			\
	$(FT_PRINTF_SRC)		\
	$(DANCING_LINK_SRC)		\
	$(QUEUE_SRC)

LIB_OBJ =					\
	$(STD_OBJ)				\
	$(LIST_OBJ)				\
	$(BTREE_OBJ)			\
	$(GNL_OBJ)				\
	$(VECTOR_OBJ)			\
	$(FT_PRINTF_OBJ)		\
	$(DANCING_LINK_OBJ)		\
	$(QUEUE_OBJ)

LIB_INCL =					\
	$(STD_INCL)				\
	$(LIST_INCL)			\
	$(BTREE_INCL)			\
	$(GNL_INCL)				\
	$(VECTOR_INCL)			\
	$(FT_PRINTF_INCL)		\
	$(DANCING_LINK_INCL)	\
	$(QUEUE_INCL)

all : $(NAME)

$(NAME) : $(LIB_OBJ) $(LIB_INCL)
	@echo ">>> creating library <<<"
	@ar rc $(NAME) $(LIB_OBJ)
	@ranlib $(NAME)

$(STD_OBJ) : $(STD_SRC)
	@echo ">>> compiling standart functions <<<"
	@make -C $(STD_DIR)

$(LIST_OBJ) : $(LIST_SRC)
	@echo ">>> compiling list functions <<<"
	@make -C $(LIST_DIR)

$(BTREE_OBJ) : $(BTREE_SRC)
	@echo ">>> compiling binary tree functions <<<"
	@make -C $(BTREE_DIR)

$(GNL_OBJ) : $(GNL_SRC)
	@echo ">>> compiling gnl <<<"
	@make -C $(GNL_DIR)

$(VECTOR_OBJ) : $(VECTOR_SRC)
	@echo ">>> compiling vector <<<"
	@make -C $(VECTOR_DIR)

$(FT_PRINTF_OBJ) :
	@echo ">>> compiling ft_printf <<<"
	@make -C $(FT_PRINTF_DIR)

$(DANCING_LINK_OBJ) : $(DANCING_LINK_SRC)
	@echo ">>> compiling dancing link <<<"
	@make -C $(DANCING_LINK_DIR)

$(QUEUE_OBJ) : $(QUEUE_SRC)
	@echo ">>> compiling queue <<<"
	@make -C $(QUEUE_DIR)

clean : 
	@echo ">>> deleting standart functions objects <<<"
	@make clean -C $(STD_DIR)
	@echo ">>> deleting list objects <<<"
	@make clean -C $(LIST_DIR)
	@echo ">>> deleting btree objects <<<"
	@make clean -C $(BTREE_DIR)
	@echo ">>> deleting gnl objects <<<"
	@make clean -C $(GNL_DIR)
	@echo ">>> deleting vector objects <<<"
	@make clean -C $(VECTOR_DIR)
	@echo ">>> deleting ft_printf objects <<<"
	@make clean -C $(FT_PRINTF_DIR)
	@echo ">>> deleting dancing link objects <<<"
	@make clean -C $(DANCING_LINK_DIR)
	@echo ">>> deleting queue objects <<<"
	@make clean -C $(QUEUE_DIR)


fclean : clean
	rm -rf $(NAME)

re : fclean $(NAME)

.PHONY : all clean fclean re
