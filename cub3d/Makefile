NAME        := cub3d
CC        := gcc
FLAGS    := -Wall -Wextra -Werror -g
SRCS        :=      libft/ft_atoi.c \
                          libft/ft_bzero.c \
                          libft/ft_calloc.c \
                          libft/ft_isalnum.c \
                          libft/ft_isalpha.c \
                          libft/ft_isascii.c \
                          libft/ft_isdigit.c \
                          libft/ft_isprint.c \
                          libft/ft_itoa.c \
                          libft/ft_lstadd_back.c \
                          libft/ft_lstadd_front.c \
                          libft/ft_lstclear.c \
                          libft/ft_lstdelone.c \
                          libft/ft_lstiter.c \
                          libft/ft_lstlast.c \
                          libft/ft_lstnew.c \
                          libft/ft_lstsize.c \
                          libft/ft_memchr.c \
                          libft/ft_memcmp.c \
                          libft/ft_memcpy.c \
                          libft/ft_memmove.c \
                          libft/ft_memset.c \
                          libft/ft_putchar_fd.c \
                          libft/ft_putendl_fd.c \
                          libft/ft_putnbr_fd.c \
                          libft/ft_putstr_fd.c \
                          libft/ft_split.c \
                          libft/ft_strchr.c \
                          libft/ft_strdup.c \
                          libft/ft_striteri.c \
                          libft/ft_strjoin.c \
                          libft/ft_strlcat.c \
                          libft/ft_strlcpy.c \
                          libft/ft_strlen.c \
                          libft/ft_strmapi.c \
                          libft/ft_strncmp.c \
                          libft/ft_strnstr.c \
                          libft/ft_strrchr.c \
                          libft/ft_strtrim.c \
                          libft/ft_substr.c \
                          libft/ft_tolower.c \
                          libft/ft_toupper.c \
                          main.c \
                          map_control/file_check.c \
                          map_control/invalid_control.c \
                          map_control/map_check.c \
                          map_control/map_closed_check.c \
                          map_control/map_size.c \
                          map_control/map_space_control.c \
                          map_control/map_value_control.c \
                          map_control/rgb_check.c \
                          player_utils.c \
                          raycasting.c \
                          utils/check_map_name.c \
                          utils/closed_game.c \
                          utils/double_str_copy.c \
                          utils/fill_map.c \
                          utils/free.c \
                          utils/get_map.c \
                          utils/rgb_convert.c \
                          cub3d_key.c \
                          cub3d_move.c \
                          draw_background.c \
                          get_line/get_line.c \
                          get_line/get_line_utils.c \


OBJS        := $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

RM		    := rm -f
UNAME		:=	$(shell uname)

$(NAME): ${OBJS}
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			$(CC) $(CFLAGS) -g3 -Ofast -o $(NAME) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit		

all:		${NAME}
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1

fclean:		clean
			@ ${RM} ${NAME}
			@ rm libmlx.a

re:			fclean all
.PHONY:		all clean fclean re