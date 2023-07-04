# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/26 18:58:37 by mkarakul          #+#    #+#              #
#    Updated: 2023/06/18 21:15:23 by mkarakul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=		srcs/minishell.c srcs/command_line.c srcs/error_msg.c \
				srcs/execute.c srcs/execve.c srcs/ft_exit.c srcs/ft_free.c \
				srcs/ft_sig_handler.c srcs/builtin/builtin.c \
				srcs/builtin/ft_echo.c srcs/builtin/ft_cd.c \
				srcs/dollars/ft_dollars_line.c srcs/dollars/ft_find_env.c \
				srcs/dollars/quot_parse.c srcs/env/addenv.c \
				srcs/env/delenv.c srcs/env/env_counter.c srcs/env/env_utils.c \
				srcs/env/export.c srcs/env/unset.c srcs/env/upenv.c \
				srcs/heredoc/exec_heredoc.c srcs/pipe/exec_pipe.c srcs/pipe/ft_pipe.c \
				srcs/pipe/initialize_fork.c srcs/redir/exec_redir.c \
				srcs/utils/ft_strcmp.c \
				parse/list_function.c parse/parse.c parse/quot_cleaner.c parse/split_line.c \
				parse/split_pipe_dollar.c parse/split_redirection.c parse/split_space.c \
				parse/split_utils.c lexer/identify.c

LIBFT		=		libft/libft.a

OBJS		=		$(SRCS:.c=.o)

NAME		=		minishell

CC			=		gcc -g

CFLAGS		=		-Wall -Werror -Wextra

RM			=		rm -rf

all:		$(NAME) 


$(NAME):		$(OBJS) $(LIBFT)
				$(CC) $(OBJS) $(CFLAGS) $(LIBFT) -lreadline -o $(NAME)

clean:
				@$(RM) $(OBJS)
				@make clean -C ./libft
$(LIBFT):
			@make -C ./libft
			@make bonus -C ./libft

fclean:
				@$(RM) $(OBJS) $(NAME)
				@make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re