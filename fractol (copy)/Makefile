NAME = fractol
SRCS = main.c utils.c mandelbrot.c julia.c hooks.c burningship.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
CC = cc

MLX_DIR = ./minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lm -lX11 -lXext

all: minilibx $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

minilibx:
	@git clone https://github.com/42paris/minilibx-linux.git
	@make -C ./minilibx-linux

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf minilibx-linux

re: fclean all

.PHONY: all clean fclean re minilibx
