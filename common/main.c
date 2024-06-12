/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:00:21 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/05 14:05:52 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ast/ast.h"

#include "parser/ast/ast.h"
#include "builitins/builtins.h"
#include "libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

static int	handle_command(char *command, int *exit_cmd, t_env_var *env)
{
	t_ast	*ast_tree;

	if (!command)
		*exit_cmd = 0;
	// __builtin_printf("%s\n", command);
	ast_tree = build_ast(tokenize(command));
	// if (!ast_tree) // changer variable d'env ?
	// 	*
	free_ast(ast_tree);
	free(command);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	char		*command;
	int			exit_cmd;
	t_env_var	*env;

	env = get_env(envp);
	exit_cmd = 1;
	while (exit_cmd)
	{
		command = readline("$> ");
		handle_command(command, &exit_cmd, env);
		add_history(command);
	}
	rl_clear_history();
	exit_cmd = ft_atoi(env->content);
	// free_env(env);
	return (exit_cmd);
}
