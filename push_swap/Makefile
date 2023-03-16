NAME = push_swap
NAME_CHECK = checker
FLAGS = -Wall -Wextra -Werror -g
LIBFT = ./Libft/libft.a
PRINTF_SRC = ./printf/*.c
GNL_SRC = ./gnl/*.c
SRC = ./src/*.c 
CHECKER_SRC = ./src_checkers/*.c
CC = gcc


all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
		$(CC) $(FLAGS) $(SRC) $(LIBFT) $(PRINTF_SRC) $(GNL_SRC) -o $(NAME)

bonus: $(NAME_CHECK)
$(NAME_CHECK): $(CHECKER_SRC) $(LIBFT)
		$(CC) $(FLAGS) $(CHECKER_SRC) $(PRINTF_SRC) $(LIBFT) $(GNL_SRC) -o $(NAME_CHECK)

$(LIBFT):
	make -C ./Libft
	make bonus -C ./Libft

$(PRINTF_SRC):
	make -C ./printf

clean:

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_CHECK)
	rm -rf $(NAME_CHECK)
	make fclean -C ./libft

re: fclean all

git:
	git add .
	git status
	git commit -m "not_finished"
	git push

.PHONY: clean fclean re