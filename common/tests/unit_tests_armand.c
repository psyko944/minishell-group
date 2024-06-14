/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests_armand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:54:42 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/14 18:07:33 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ast.h>
#include <stdio.h>

void	print_tokens(t_token *tokens, int ind);
void	print_ast(t_ast *ast, int ind);
void	test_var_inter(char *src, t_env_var *env, char *expected);

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
	if (ast_tree)
	{
		print_ast(ast_tree, 0);
		free_ast(ast_tree);
	}
	else
		printf("AST is empty\n");
	t_env_var	*env = get_env(envp);
	test_var_inter("$PATH", env, "/home/arlarzil/bin:/home/arlarzil/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
	test_var_inter("$PATH$USER", env, "/home/arlarzil/bin:/home/arlarzil/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/binarlarzil");
	test_var_inter("${PATH}", env, "/home/arlarzil/bin:/home/arlarzil/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin");
	test_var_inter("$NOMATCH", env, "");
	test_var_inter("le${NOMATCH}hein", env, "lehein");
	test_var_inter("'${NOMATCH}'", env, "${NOMATCH}");
	test_var_inter("\"${NOMATCH}\"", env, "");
	test_var_inter("\"'${NOMATCH}'\"", env, "'${NOMATCH}'");
}
