NAME = 	Cub3D
SRCS = 	cub3d.c
OBJS = 	$(SRCS:.c=.o)
FLAGS =	-Wall -Werror -Wextra -lm -lbsd -lX11 -lXext -g

all:		$(NAME)

$(NAME):	$(OBJS) _libft
			gcc -o $(NAME) $(OBJS) $(shell find mlx/ -name "*.a") $(shell find libft/ -name "*.a") $(FLAGS)

_libft:
			@make -C libft

clean:
			@rm -f $(OBJS)
			@make clean -C libft	

fclean:		clean
			@rm -f $(NAME)
			@make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re
