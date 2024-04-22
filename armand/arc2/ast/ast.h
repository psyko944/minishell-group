/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:16:08 by arlarzil          #+#    #+#             */
/*   Updated: 2024/04/16 18:16:08 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "../lexer/lexer.h"

typedef enum e_node_type {
	N_IN_REDIRECT,
	N_HEREDOC,
	N_OUT_REDIRECT,
	N_APPEND,
	N_PIPE,
	N_AND_OPERATOR,
	N_OR_OPERATOR,
	N_ROOT,
	N_EXEC
}	t_node_type;

typedef struct s_ast_node {
	t_node_type			type;
	char				**data;
	struct s_ast_node	*r;
	struct s_ast_node	*l;
}	t_ast_node;

t_ast_node	*create_ast(t_lexed_list *l);

#endif
