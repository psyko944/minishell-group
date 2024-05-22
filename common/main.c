/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:00:21 by arlarzil          #+#    #+#             */
/*   Updated: 2024/05/22 16:46:56 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ast/ast.h"

#include "parser/ast/ast.h"
#include "builitins/builtins.h"
#include "libft/libft.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

static int	handle_command(char *command, int *exit_cmd)
{
	t_ast	*ast_tree;

	// __builtin_printf("%s\n", command);
	ast_tree = ast(tokenize(command));
	free_ast(ast_tree);
	free(command);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	char		*command;
	int			exit_cmd;
	t_env_var	*env;

	// env = get_env(envp);
	// if (!env) // Malloc fail
	// 	return (127);
	exit_cmd = 1;
	while (exit_cmd)
	{
		command = readline("$> ");
		if (!command)
			break ;
		handle_command(command, &exit_cmd);
		add_history(command);
	}
	rl_clear_history();
	exit_cmd = ft_atoi(env->content);
	// free_env(env);
	return (exit_cmd);
}
