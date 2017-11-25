NAME = fdf
PATH_SRC = ./
PATH_OBJ = ./
PATH_INC = ./libft

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

HEAD = fdf.h

SRC = main.c init_map.c core.c control.c draw_line.c\

OBJ = $(patsubst %.c,%.o,$(addprefix $(PATH_SRC), $(SRC)))

$(NAME) : fdf.h
	make -C libft/
	$(CC) $(CFLAGS) -I $(PATH_INC) -c $(SRC)
	$(CC) -o $(NAME) $(OBJ) -lm -L libft/ -lft ./minilibx/libmlx.a -framework OpenGL -framework AppKit

all: $(NAME)

clean:
	make -C libft/ clean
	$(RM) $(OBJ) *.gch

fclean: clean
	make -C libft/ fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean all re
