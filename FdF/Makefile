all: fdf
CFLAGS = -g -framework OpenGL  -framework Cocoa -mmacosx-version-min=14.3  -lglfw
PATH_MLX = -L/MLX -lmlx42 -O3
MLX = MLX42/build/libmlx42.a

$(MLX):
	@git clone https://github.com/codam-coding-college/MLX42.git
	@cd MLX42 && cmake -B build && cmake --build build -j4
LIBFT = libft/ft_toupper.o libft/ft_tolower.o libft/ft_substr.o libft/ft_strtrim.o \
       libft/ft_strrchr.o libft/ft_strnstr.o libft/ft_strncmp.o libft/ft_strmapi.o \
       libft/ft_strlen.o libft/ft_strlcpy.o libft/ft_strlcat.o libft/ft_strjoin.o \
       libft/ft_striteri.o libft/ft_strdup.o libft/ft_strchr.o libft/ft_split.o \
       libft/ft_putstr_fd.o libft/ft_putnbr_fd.o libft/ft_putendl_fd.o \
       libft/ft_putchar_fd.o libft/ft_memset.o libft/ft_memmove.o libft/ft_memcpy.o \
       libft/ft_memcmp.o libft/ft_memchr.o libft/ft_lstsize_bonus.o libft/ft_lstnew_bonus.o \
       libft/ft_lstmap_bonus.o libft/ft_lstlast_bonus.o libft/ft_lstiter_bonus.o \
       libft/ft_lstdelone_bonus.o libft/ft_lstclear_bonus.o libft/ft_lstadd_front_bonus.o \
       libft/ft_lstadd_back_bonus.o libft/ft_itoa.o libft/ft_isprint.o libft/ft_isdigit.o \
       libft/ft_isascii.o libft/ft_isalpha.o libft/ft_isalnum.o libft/ft_calloc.o \
       libft/ft_bzero.o libft/ft_atoi.o 
LFT = $(LIBFT.o=.c)
PROJECTFILES = main.c test_and_free_map.c read_map.c visualize_points_and_grid.c matrix_operations.c utils.c utils2.c

fdf: ${PROJECTFILES} ${LIBFT} $(MLX)
	gcc ${PROJECTFILES} ${LIBFT} ${CFLAGS} $(MLX) -o fdf -O3 -Iinclude -L./libft

${LIBFT}:${LFT}
	make -C ./libft
	make -C ./libft bonus

clean:
	rm -rf ./fdf

fclean:
	rm -rf ./fdf
	make -C ./libft fclean

re:
	make fclean
	make -C ./libft fclean
	make all

