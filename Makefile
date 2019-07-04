NAME = RTv1

LIBFT_DIRECTORY = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a
GCC_LIBFT =                                         \
    -L ./libft                                      \
    -l ft

INCLUDES =                                          \
    $(LIBFT_DIRECTORY)includes/                     \
	./includes

SOURCE_CL =										    \
	./sources/open_cl/program.cl

SOURCES =                                           \
    ./sources/camera/camera.c						\
    ./sources/light/light.c                         \
    ./sources/main.c                                \
    ./sources/open_cl/open_cl.c                     \
    ./sources/open_cl/open_cl_alloc_device_data.c   \
    ./sources/open_cl/open_cl_create_context.c      \
    ./sources/open_cl/open_cl_create_device.c       \
    ./sources/open_cl/open_cl_create_kernel.c       \
    ./sources/open_cl/open_cl_create_program.c      \
    ./sources/open_cl/open_cl_create_queue.c        \
    ./sources/open_cl/open_cl_error.c               \
    ./sources/open_cl/open_cl_set_arguments.c       \
    ./sources/rt/rt.c                               \
    ./sources/rt/rt_clone.c                         \
    ./sources/rt/rt_control.c                       \
    ./sources/rt/rt_mlx.c                           \
    ./sources/scene/scene.c                         \
    ./sources/scene/scene_a.c                       \
    ./sources/scene/scene_b.c                       \
    ./sources/scene/scene_c.c                       \
    ./sources/scene/scene_d.c                       \
    ./sources/scene/scene_e.c                       \
    ./sources/scene/scene_f.c                       \
    ./sources/shape/shape.c                         \
    ./sources/shape/shape_aabb.c                    \
    ./sources/shape/shape_cone.c                    \
    ./sources/shape/shape_cylinder.c                \
    ./sources/shape/shape_plane.c                   \
    ./sources/shape/shape_sphere.c                  \
    ./sources/vector3/vector3.c                     \
    ./sources/vector3/vector3_add_sub.c             \
    ./sources/vector3/vector3_mul.c                 \
    ./sources/vector3/vector3_rotate.c

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

$(OBJECTS) : $(SOURCES) $(SOURCE_CL)
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
