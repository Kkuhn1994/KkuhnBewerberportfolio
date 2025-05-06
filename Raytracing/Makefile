NAME = miniRT
BONUS = miniRT_bonus
CFLAGS = -Wall -Wextra -Werror -Iinclude -pthread -g
PATH_MLX = -L./MLX42 -lmlx42 -O3
MLX = MLX42/build/libmlx42.a
CLEAN_DIRS = libft vector_stuff Matrix_stuff Intersections Transformation world_building parsing

GC = main.o garbageCollector.o vector_stuff/vector_vector_operations.o vector_stuff/vector_scalar_operations.o vector_stuff/vector_operations.o Matrix_stuff/matrix_conversion.o \
Matrix_stuff/matrix_conversion2.o Matrix_stuff/matrix_operations.o Matrix_stuff/assign_matrix.o Matrix_stuff/submatrix.o Matrix_stuff/transformation.o Intersections/Intersection_order.o Intersections/create_and_safe.o \
Intersections/identify_hits.o Intersections/cylinder_intersect.o Intersections/save_intersections.o Transformation/transformation.o default_values.o color_transform.o reflection.o initialisation.o world_building/base_world.o\
world_building/intersect_world.o world_building/throw_shade.o world_building/view_world.o parsing/parsing.o parsing/parsing_atof.o parsing/budget_get_next_line.o parsing/parse_cam_light.o parsing/sphere_plane.o parsing/parsing_tools.o\
parsing/check_lineparsing.o checker.o Matrix_stuff/transformation2.o world_building/normal_calculations.o parsing/shape_helpers.o parsing/cam_light_helpers.o Intersections/cone_intersect.o world_building/shade_helpers.o \
world_building/bump_map.o parsing/parse_cylinder.o parsing/space_reduction.o rt_realloc.o parsing/parse_cone.o parsing/rotation_matrix.o world_building/bump_helpers.o world_building/normal_bumping.o world_building/cone_normal.o world_building/color_at.o

GC_BONUS = main.o garbageCollector.o vector_stuff/vector_vector_operations.o vector_stuff/vector_scalar_operations.o vector_stuff/vector_operations.o Matrix_stuff/matrix_conversion.o \
Matrix_stuff/matrix_conversion2.o Matrix_stuff/matrix_operations.o Matrix_stuff/assign_matrix.o Matrix_stuff/submatrix.o Matrix_stuff/transformation.o Intersections/Intersection_order.o Intersections/create_and_safe.o \
Intersections/identify_hits.o Intersections/cylinder_intersect.o Intersections/save_intersections.o Transformation/transformation.o default_values.o color_transform.o reflection_bonus.o initialisation.o world_building/base_world.o\
world_building/intersect_world.o world_building/throw_shade.o world_building/view_world.o parsing/parsing_bonus.o parsing/parsing_atof.o parsing/budget_get_next_line.o parsing/parse_cam_light_bonus.o parsing/sphere_plane.o parsing/parsing_tools.o\
parsing/check_lineparsing_bonus.o checker.o Matrix_stuff/transformation2.o world_building/normal_calculations.o parsing/shape_helpers_bonus.o parsing/cam_light_helpers.o Intersections/cone_intersect.o world_building/shade_helpers.o \
world_building/bump_map.o parsing/parse_cylinder.o parsing/space_reduction.o rt_realloc.o parsing/parse_cone.o parsing/rotation_matrix.o world_building/bump_helpers.o world_building/normal_bumping.o world_building/cone_normal.o world_building/color_at.o

OBJ = $(GC:.o=.c)
BONUS_OBJ = $(GC_BONUS:.o=.c)
MLX_DIR = MLX42

all: $(MLX_DIR) libft/libft.a $(NAME)

$(MLX_DIR):
	git clone https://github.com/codam-coding-college/MLX42.git
	cd $(MLX_DIR) && cmake -B build -S . && cmake --build build 

%.o: %.c
	gcc -c $(CFLAGS) -o $@ $^

libft/libft.a:
	make -C ./libft

$(NAME): $(MLX) libft/libft.a ${GC}
	gcc ${GC} $(MLX) libft/libft.a -o $@ -ldl -lglfw -pthread -lm

$(BONUS): $(MLX) libft/libft.a ${GC_BONUS}
	gcc ${GC_BONUS} $(MLX) libft/libft.a -o $(BONUS) -ldl -lglfw -pthread -lm

bonus: $(BONUS)

clean:
	for dir in $(CLEAN_DIRS); do rm -f $$dir/*.o; done
	rm -f *.o
	rm -rf $(MLX_DIR)
	make -C ./libft clean

fclean:
	make clean
	make -C ./libft fclean
	rm -f ${NAME}
	rm -f ${NAME}_bonus
	rm -rf MLX42

re: fclean all

.PHONY: all clean fclean re bonus