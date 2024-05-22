/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:28:15 by arlarzil          #+#    #+#             */
/*   Updated: 2024/05/22 15:58:59 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "../tokenize/tokenize.h"

typedef struct s_ast {
	t_token_type	type;
	void			*content;
	struct s_ast	*l;
	struct s_ast	*r;
}	t_ast;

t_ast	*ast(t_token *tokens);
t_ast	*free_ast(t_ast *ast);
#endif
