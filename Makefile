NAME		= miniRT
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iinclude
MLXFLAGS	= -Lminilibx-linux -lmlx -lXext -lX11 -lm

SRCDIR		= src
OBJDIR		= obj

SRC_FILES	= main.c draw.c vec3_utils.c vec3_utils2.c init.c
SRC			= $(addprefix $(SRCDIR)/, $(SRC_FILES))
OBJ			= $(addprefix $(OBJDIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(MLXFLAGS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
