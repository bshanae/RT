NAME = RTv1

LIBFT_DIRECTORY = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a
GCC_LIBFT =                                     \
    -L ./libft                                  \
    -l ft

INCLUDES =                                      \
    $(LIBFT_DIRECTORY)includes/                 \
    ./                                          \
    ./camera                                    \
    ./color                                     \
    ./intersection                              \
    ./light                                     \
    ./main.c                                    \
    ./material                                  \
    ./mlx                                       \
    ./objects                                   \
    ./open_cl                                   \
    ./parameters.h                              \
    ./ray                                       \
    ./rt                                        \
    ./scene                                     \
    ./shape                                     \
    ./vector3

SOURCES =                                       \
    ./camera/camera.c                           \
    ./light/light.c                             \
    ./main.c                                    \
    ./open_cl/open_cl.c                         \
    ./open_cl/open_cl_alloc_device_data.c       \
    ./open_cl/open_cl_create_context.c          \
    ./open_cl/open_cl_create_device.c           \
    ./open_cl/open_cl_create_kernel.c           \
    ./open_cl/open_cl_create_program.c          \
    ./open_cl/open_cl_create_queue.c            \
    ./open_cl/open_cl_error.c                   \
    ./open_cl/open_cl_set_arguments.c           \
    ./rt/rt.c                                   \
    ./rt/rt_clone.c                             \
    ./rt/rt_control.c                           \
    ./rt/rt_mlx.c                               \
    ./scene/scene.c                             \
    ./scene/scene_a.c                           \
    ./scene/scene_b.c                           \
    ./scene/scene_c.c                           \
    ./scene/scene_d.c                           \
    ./scene/scene_e.c                           \
    ./shape/shape.c                             \
    ./shape/shape_aabb.c                        \
    ./shape/shape_cone.c                        \
    ./shape/shape_cylinder.c                    \
    ./shape/shape_plane.c                       \
    ./shape/shape_sphere.c                      \
    ./vector3/vector3.c                         \
    ./vector3/vector3_add_sub.c                 \
    ./vector3/vector3_mul.c                     \
    ./vector3/vector3_rotate.c

OBJECTS_DIRECTORY = ./objects/
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY),$(notdir $(SOURCES:.c=.o)))

COMPILE_OBJECT = gcc $(addprefix -I, $(INCLUDES)) $(1) -c

MOVE_TO_OBJECTS_DIRECTORY = mv $(notdir $(1:.c=.o)) $(addprefix $(OBJECTS_DIRECTORY),$(notdir $(1:.c=.o)))

GCC_FRAMEWORKS =								\
	-I /usr/local/include/					    \
	-L /usr/local/lib/						    \
	-l mlx									    \
	-framework OpenGL                           \
	-framework AppKit                           \
	-framework OpenCL

COMPILE_BINARY = gcc $(GCC_FRAMEWORKS) $(GCC_LIBFT) $(addprefix -I, $(INCLUDES)) $(OBJECTS) -o $(NAME)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJECTS_DIRECTORY) $(OBJECTS)
	$(COMPILE_BINARY)

$(LIBFT) :
	make -C $(LIBFT_DIRECTORY)

$(OBJECTS_DIRECTORY) :
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS) : $(SOURCES)
	$(foreach SOURCE,$(SOURCES), $(call COMPILE_OBJECT, $(SOURCE)); $(call MOVE_TO_OBJECTS_DIRECTORY, $(SOURCE));)

clean :
	rm -rf $(OBJECTS_DIRECTORY)
	make clean -C ./libft/

fclean :
	@rm -rf $(OBJECTS_DIRECTORY)
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIRECTORY)

re : fclean all

ref :
	@rm -rf $(OBJECTS_DIRECTORY)
	@rm -rf $(NAME)
	@$(MAKE) all

.PHONY : all clean fclean re ref
