/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:14:53 by arlarzil          #+#    #+#             */
/*   Updated: 2024/04/16 18:14:55 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast/ast.h"

t_ast_node	*parser(const char *s)
{
	t_lexed_list	*lex;

	lex = mini_lexer(s);
	if (!lex)
		return (0);
	return (create_ast(lex));
}
