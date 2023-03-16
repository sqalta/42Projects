SRCS	= ft_pointer.c \
			ft_printf.c \
			ft_putchar_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_putunint.c \
			ft_x.c
OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror


all :  ${NAME}

$(NAME) : ${OBJS}
	ar rc $(NAME) $(OBJS)

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all