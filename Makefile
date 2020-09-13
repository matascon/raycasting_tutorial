NAME = 	Cub3D
SRCS = 	cub3d.c
OBJS = 	$(SRCS:.c=.o)
FLAGS =	-Wall -Werror -Wextra -lm -lbsd -lX11 -lXext -g

all:		$(NAME)

$(NAME):	$(OBJS) _libs
			gcc -o $(NAME) $(OBJS) $(shell find minilibx_linux/ -name "*.a") $(shell find libft/ -name "*.a") $(FLAGS)

_libs:
			@make -C libft
			@make -C minilibx_linux

clean:
			@rm -f $(OBJS)
			@make clean -C libft
			#@make clean -C minilinx_linux

fclean:		clean
			@rm -f $(NAME)
			@make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re
