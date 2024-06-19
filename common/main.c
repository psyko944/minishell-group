/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:00:21 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/19 17:13:30 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ast/ast.h"

#include <ast.h>
// #include <builtins.h>
#include <minishell.h>
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

char	*replace_vars(char *s, t_env_var *env);
int	get_files(char **command, t_command *storage);

static void	ph_execve_and_co(char **tab)
{
	while (*tab)
	{
		printf("%s\n", *tab);
		free(tab);
		++tab;
	}
}

static int	ph_exec_node(t_ast *node, t_env_var *env)
{
	t_command	command;
	int			i;
	int			s;

	i = 0;
	command.in = 0;
	command.out = 0;
	command.tab = node->content;
	printf("We're running: ");
	while (command.tab[i])
	{
		command.tab[i] = replace_vars(command.tab[i], env);
		// get_matches(command.tab, ".");
		i += 1;
	}
	i = 0;
	s = get_files(command.tab, &command);
	if (s == 0)
		return (printf("caca\n"), 0);
	while (command.tab[i])
	{
		printf("[%s] ", command.tab[i]);
		i += 1;
	}
	printf("with fds %d %d\n", command.in, command.out);
	return (0);
}

static int	culnode(void)
{
	printf("coucou\n");
	return (1);
}

static int	ph_exec_tree(t_ast *tree, int *exit_cmd, t_env_var *env)
{
	int	status;

	while (1)
	{
		if (tree->type == TEXT)
		{
			return (ph_exec_node(tree, env));
		}
		else if (tree->type == PARENTHESIS)
			status = ph_exec_tree(tree->content, exit_cmd, env);
		else
			culnode();
	}
}

static int	handle_command(char *command, int *exit_cmd, t_global *env)
{
	t_ast	*ast_tree;

	if (!command)
		*exit_cmd = 0;
	else
	{
		ast_tree = build_ast(tokenize(command));
		ph_exec_tree(ast_tree, exit_cmd, env);
		free_ast(ast_tree);
		free(command);
	}
	if (!ast_tree)
		__builtin_printf("PAAARSE\n");
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	char		*command;
	int			exit_cmd;
	t_global	env;
	int			status;

	env.env = get_env(&env, envp);
	exit_cmd = 1;
	status = 0;
	while (exit_cmd)
	{
		command = readline("$> ");
		if (command)
			handle_command(ft_strdup(command), &exit_cmd, &env);
		else
			break ;
		add_history(command);
	}
	rl_clear_history();
	exit_cmd = ft_atoi(env.env->content);
	// free_env(env);
	return (exit_cmd);
}
