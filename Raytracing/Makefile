NAME = miniRT
CFLAGS = -Iinclude -ldl -lglfw -pthread -lm -g
PATH_MLX = -L./MLX42 -lmlx42 -O3
MLX = MLX42/build/libmlx42.a
CLEAN_DIRS = libft vector_stuff Matrix_stuff Intersections Transformation world_building parsing
OBJECTS = libft/ft_toupper.o \
       libft/ft_tolower.o \
       libft/ft_substr.o \
       libft/ft_strtrim.o \
       libft/ft_strrchr.o \
       libft/ft_strnstr.o \
       libft/ft_strncmp.o \
       libft/ft_strmapi.o \
       libft/ft_strlen.o \
       libft/ft_strlcpy.o \
       libft/ft_strlcat.o \
       libft/ft_strjoin.o \
       libft/ft_striteri.o \
       libft/ft_strdup.o \
       libft/ft_strchr.o \
       libft/ft_split.o \
       libft/ft_putstr_fd.o \
       libft/ft_putnbr_fd.o \
       libft/ft_putendl_fd.o \
       libft/ft_putchar_fd.o \
       libft/ft_memset.o \
       libft/ft_memmove.o \
       libft/ft_memcpy.o \
       libft/ft_memcmp.o \
       libft/ft_memchr.o \
       libft/ft_lstsize_bonus.o \
       libft/ft_lstnew_bonus.o \
       libft/ft_lstmap_bonus.o \
       libft/ft_lstlast_bonus.o \
       libft/ft_lstiter_bonus.o \
       libft/ft_lstdelone_bonus.o \
       libft/ft_lstclear_bonus.o \
       libft/ft_lstadd_front_bonus.o \
       libft/ft_lstadd_back_bonus.o \
       libft/ft_itoa.o \
       libft/ft_isprint.o \
       libft/ft_isdigit.o \
       libft/ft_isascii.o \
       libft/ft_isalpha.o \
       libft/ft_isalnum.o \
       libft/ft_calloc.o \
       libft/ft_bzero.o \
       libft/ft_atoi.o \

GC = main.o garbageCollector.o vector_stuff/vector_vector_operations.o vector_stuff/vector_scalar_operations.o vector_stuff/vector_operations.o Matrix_stuff/matrix_conversion.o \
Matrix_stuff/matrix_conversion2.o Matrix_stuff/matrix_operations.o Matrix_stuff/assign_matrix.o Matrix_stuff/submatrix.o Matrix_stuff/transformation.o Intersections/Intersection_order.o Intersections/create_and_safe.o \
Intersections/identify_hits.o Intersections/cylinder_intersect.o Intersections/save_intersections.o Transformation/transformation.o default_values.o color_transform.o reflection.o initialisation.o world_building/base_world.o\
world_building/intersect_world.o world_building/throw_shade.o world_building/view_world.o parsing/parsing.o parsing/parsing_atof.o parsing/budget_get_next_line.o parsing/parse_cam_light.o parsing/parse_shapes.o parsing/parsing_tools.o\
parsing/check_lineparsing.o checker.o Matrix_stuff/transformation2.o world_building/normal_calculations.o parsing/shape_helpers.o parsing/cam_light_helpers.o Intersections/cone_intersect.o world_building/shade_helpers.o \
world_building/bump_map.o

OBJ = $(OBJECTS:.o=.c)
MLX_DIR = MLX42

all: $(MLX_DIR) miniRT

$(MLX_DIR):
	git clone https://github.com/codam-coding-college/MLX42.git
	cd $(MLX_DIR) && cmake -B build -S . && cmake --build build 
# miniRT: ${GC} $(MLX) ${OBJECTS}
# 	gcc ${GC} $(OBJECTS) $(MLX) -o $@ -ldl -lglfw -pthread -lm -lX11 -lXext
miniRT: ${GC} $(MLX) ${OBJECTS}
	gcc ${GC} $(OBJECTS) $(MLX) -o $@ -ldl -lglfw -pthread -lm

main.o: main.c
	gcc -c ${CFLAGS} $< -o $@

%.o: %.c
	gcc -c $(CFLAGS) -o $@ $^

${OBJECTS}:	${OBJ}
	make -C ./libft
	make bonus -C ./libft

clean:
	for dir in $(CLEAN_DIRS); do rm -f $$dir/*.o; done
	rm -f *.o
	rm -rf $(MLX_DIR)

fclean:
	make clean
	make -C ./libft fclean
	rm -f ${OBJECTS} ${NAME}
	rm -rf MLX42

re: fclean all

.PHONY: all clean fclean re