/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:32:51 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/23 00:27:21 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H

# include <minishell.h>

// typedef enum e_token_type {
// 	TEXT,
// 	SEPARATOR,
// 	PARENTHESIS,
// 	N_PIPE,
// 	N_AND,
// 	N_OR,
// 	COMMAND
// }	t_token_type;	

// typedef struct s_token {
// 	t_token_type	type;
// 	void			*content;
// 	struct s_token	*prev;
// 	struct s_token	*next;
// }	t_token;

t_token		*get_parenthesis(const char **s_ptr, t_global *glo);
t_token		*get_word(const char **s);
t_token		*new_token(t_token_type type, void *content, t_global *glo);
char		**cut_command(const char *s, int len);
int			skip_quote(const char *s);

t_token		*tokenize(const char *s, t_global *glo);
t_token		*free_tokens(t_token *t);

void		print_parse_err(const char *tok);
int			command_sep(const char *s);
void		add_spaces(char *s);

#endif
