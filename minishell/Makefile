NAME				= 	minishell

CC					=	cc
FLAGS				=   -Wextra -Wall -Werror 

SRC_DIR				:=	src
SRC_SRC			:=	$(wildcard $(SRC_DIR)/*.c)


LIBFT 				=	tools/libft/libft.a

OBJ 				=	tools/obj
SRC_OBJ				:=	$(patsubst $(SRC_DIR)/%.c,$(OBJ)/%.o,$(SRC_SRC))

all:						$(NAME)

$(LIBFT):
				@cd tools/libft && make -s && make bonus -s

$(NAME):$(LIBFT) $(SRC_OBJ)
				@$(CC) $(CFLAGS) -o $(NAME) $(SRC_OBJ) -L./tools/libft -lft -lreadline

$(OBJ)/%.o:	src/%.c
			@cd tools
			@mkdir -p $(OBJ)
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@rm -rf $(OBJ)/*
			@cd tools/libft && make clean -s


fclean: 			clean
			@rm -rf $(NAME)
			@rm -rf $(OBJ)
			@cd tools/libft && make fclean -s

re:			fclean all

.PHONY:		all clean fclean re
