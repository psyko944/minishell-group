/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests_armand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:54:42 by arlarzil          #+#    #+#             */
/*   Updated: 2024/05/23 16:46:52 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parser/ast/ast.h"
#include <stdio.h>

void	print_tokens(t_token *tokens, int ind);
void	print_ast(t_ast *ast, int ind);

void	unit_tests_armand(int ac, char **av, char **envp)
{
	t_token	*tok;
	t_ast	*ast_tree;

	printf("--- Testing: %s ---\n", av[ac - 1]);
	(void)envp;
	printf("-- Tokens --\n");
	tok = tokenize(av[ac - 1]);
	print_tokens(tok, 0);
	printf("-- AST --\n");
	ast_tree = build_ast(tok);
	print_ast(ast_tree, 0);
	free_ast(ast_tree);
}
