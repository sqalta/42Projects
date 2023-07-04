/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkarakul <mkarakul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 17:46:02 by mkarakul          #+#    #+#             */
/*   Updated: 2023/06/18 21:18:51 by mkarakul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

enum e_character {
	WORD,
	INPUT_RDR,
	OUTPUT_RDR,
	DOUBLE_OUTPUT_RDR,
	DOUBLE_INPUT_RDR,
	PIPE,
	DOLLAR
};

enum e_loc_quot {
	none,
	head_end,
	midle
};

typedef struct s_type_counter{
	int	dollar;
	int	rdr;
	int	heredoc;
	int	word;
	int	pipe;
}					t_type_counter;

typedef struct s_arg {
	struct s_arg		*next;
	char				*arg;
	enum e_character	type;
}					t_arg;

void	print_list(t_arg *lst);
int		is_redirection(char *s);
int		is_quotation(char *s);
int		is_pipe(char *s);
void	split_by_space(char *s, t_arg **line);
int		check_quotation(char *s);
void	p_lstadd_back(t_arg **lst, t_arg *new);
void	p_lstadd_front(t_arg **lst, t_arg *new);
int		p_lstsize(t_arg *lst);
t_arg	*p_lstnew(int type, char *s);
t_arg	*p_lstlast(t_arg *lst);
void	split_by_redirection(t_arg **prompt);
void	split_by_pipe(t_arg **prompt);
int		handle_character(t_arg **prompt, int (*checker)(char *));
int		identify_token(t_arg	**prompt);
void	quot_cleaner(t_arg	**prompt);
int		type_quotation(char s);
char	*trim_quot(char *s);
int		contains_quot(char *s);
void	split_line(char *s, t_arg *line);
void	split_line2(int st, int len, char *s, t_arg *line);
int		check_quotation2(char *s);
#endif