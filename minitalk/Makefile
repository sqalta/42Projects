SRC_CLIENT = client.o ft_atoi.o
SRC_SERVER = server.o

CC = gcc
RM = rm -f
CFLAG = -Wall -Wextra -Werror
printf = ./ft_printf/libftprintf.a

OBJCLIENT = $(SRC_CLIENT:.c=.o)
OBJSERVER = $(SRC_SERVER:.c=.o)
NAME = minitalk.a

all: $(NAME)

$(NAME): server client $(OBJCLIENT) $(OBJSERVER)

server: $(OBJSERVER)
	make -C ./ft_printf
	$(CC) $(CFLAG) $(printf) -o server $(OBJSERVER)

client: $(OBJCLIENT)
	make -C ./ft_printf
	$(CC) $(CFLAG) $(printf) -o client $(SRC_CLIENT)

clean:
	make fclean -C ./ft_printf
	$(RM) $(OBJSERVER) $(OBJCLIENT)

fclean: clean
	make fclean -C ./ft_printf
	$(RM) server
	$(RM) client

re: fclean $(NAME)

.PHONY: all clean fclean re


