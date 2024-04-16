/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:15:48 by arlarzil          #+#    #+#             */
/*   Updated: 2024/04/16 18:15:48 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

// Content is for text, soft_content is parenthesis content
typedef struct s_lexed_list {
	char				*content;
	struct s_lexed_list	*soft_content;
	struct s_lexed_list	*next;
	struct s_lexed_list	*prev;
}	t_lexed_list;

// Fonctionnement interne du lexer
t_lexed_list	*split_parenthesis(const char *s);
t_lexed_list	*lex_new_node(char *content, t_lexed_list *soft_content);
t_lexed_list	*lex_add_back(t_lexed_list **ls, t_lexed_list *node);
void			lex_insert(t_lexed_list *ls, t_lexed_list *node);
t_lexed_list	*cut_expression(t_lexed_list *l);

// Utilisation du lexer
t_lexed_list	*mini_lexer(const char *s);
t_lexed_list	*free_lexer(t_lexed_list *ls);

#endif
