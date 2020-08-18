SRCS	=		ft_memset.c			\
				ft_bzero.c 			\
				ft_memcpy.c 		\
				ft_memccpy.c 		\
				ft_memmove.c 		\
				ft_memchr.c 		\
				ft_memcmp.c 		\
				ft_strlen.c 		\
				ft_strlcpy.c 		\
				ft_strlcat.c 		\
				ft_strchr.c 		\
				ft_strrchr.c 		\
				ft_strnstr.c 		\
				ft_strncmp.c 		\
				ft_atoi.c 			\
				ft_isalpha.c 		\
				ft_isdigit.c 		\
				ft_isalnum.c 		\
				ft_isascii.c 		\
				ft_isprint.c 		\
				ft_tolower.c 		\
				ft_toupper.c 		\
				ft_calloc.c			\
				ft_strdup.c 		\
				ft_substr.c 		\
				ft_strjoin.c		\
				ft_strtrim.c		\
				ft_split.c			\
				ft_itoa.c			\
				ft_strmapi.c		\
				ft_putchar_fd.c		\
				ft_putstr_fd.c		\
				ft_putendl_fd.c		\
				ft_putnbr_fd.c		\
				ft_strsjoin.c		\
				ft_strsdup.c		\
				ft_str_upper.c		\
				ft_gnl.c
BONUS_SRCS =	ft_lstnew.c			\
				ft_lstadd_front.c	\
				ft_lstsize.c		\
				ft_lstlast.c		\
				ft_lstadd_back.c	\
				ft_lstdelone.c		\
				ft_lstclear.c		\
				ft_lstiter.c		\
				ft_lstmap.c
LIBS			= libft.h
OBJS			= $(SRCS:.c=.o)
BONUS_OBJS		= $(BONUS_SRCS:.c=.o)
NAME			= libft.a
AR				= ar rcs
RANLIB			= ranlib
GCC				= gcc
CFLAGS			= -Wall -Werror -Wextra
RM				= rm -f

.c.o:
			$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
			$(RANLIB) $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

bonus:		$(OBJS) $(BONUS_OBJS)
			$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)
			$(RANLIB) $(NAME)

Norme:
			norminette -R CheckForbiddenSourceHeader $(SRCS) $(BONUS_SRCS) $(LIBS)

.PHONY:		all clean fclean re bonus Norme