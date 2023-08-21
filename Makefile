NAME = cub3d

LIB = libft.a

FILES = main \
		window_manager \
		hooks \
		init \
		ft_exit \
		tmp_utils

SRC = $(foreach f, $(FILES), srcs/$(f).c)
OBJ = $(SRC:.c=.o)

FS = -fsanitize=address -g

CFLAGS = -Iheaders -Wextra -Wall -IMLX42/include

GFLAGS = -Iheaders $(LIB) -Werror -Wextra -Wall MLX42/build/libmlx42.a -IMLX42/include -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/" -lm

all: $(NAME)
r: re
	./$(NAME)

$(NAME): $(LIB) $(OBJ)
	@printf "> \x1b[32mAll objects compiled\x1b[0m\n"
	@gcc -o $(NAME) $(OBJ) $(GFLAGS)
	@printf "> \x1b[32m$(NAME) compiled\x1b[0m\n"

.c.o:
	@gcc $(CFLAGS) -o $@ -c $<

$(LIB):
	@make -C libft
	@cp libft/libft.a ./

clean:
	@make -C libft clean
	@printf ">  \x1b[31mAll libft objects cleaned\x1b[0m\n"
	@rm -rf $(OBJ)
	@rm -rf miniJoker.dSYM
	@printf "> \x1b[31mAll objects cleaned\x1b[0m\n"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME) $(LIB)
	@printf "> \x1b[31m$(NAME) cleaned\x1b[0m\n"

re: fclean all

.PHONY: all bonus clean fclean re