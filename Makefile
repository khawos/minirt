CFLAGS = -Wall -Werror -Wextra

NAME = miniRT

CC = cc

SRC = main.c init.c vec3_utils.c vec3_utils2.c draw.c

OBJS = $(SRC:.c=.o)

MLX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -O3


all : $(NAME)

$(NAME) : $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -lm $(MLX) -o $(NAME)

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all
