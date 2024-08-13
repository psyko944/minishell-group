/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:00:21 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/13 16:12:04 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ast/ast.h"

#include <ast.h>
#include <minishell.h>
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

char	*replace_vars(char *s, t_env_var *env);
char	*remove_quotes(char *s);

static int	ph_exec_node(t_ast *node, t_global *env)
{
	t_command	command;
	int			i;

	node->content = (char **)replace_vars(node->content, env->env);
	if (!node->content)
		return (-1);
	command.tab = cut_command(node->content, get_sub_tok_count(node->content));
	free(node->content);
	node->content = command.tab;
	node->type = COMMAND;
	command.in = 0;
	command.out = 0;
	command.tab = node->content;
	command.tab = fill_wild_tab(command.tab, ".");
	if (!command.tab)
		return ((node->content = NULL), 1);
	free(node->content);
	printf("We're running: ");
	node->content = command.tab;
	if (!get_files(command.tab, &command, env))
		return (printf("caca\n"), 0);
	i = 0;
	while (command.tab[i])
	{
		command.tab[i] = remove_quotes(command.tab[i]);
		printf("[%s] ", command.tab[i]);
		i += 1;
	}
	printf("with fds %d %d\n", command.in, command.out);
	if (command.tab[0] && g_exit_status != 135)
		cmd_runtime(&command, env);
	else
	{
		if (g_exit_status == 135)
			g_exit_status = 130;
		if (command.in)
			close(command.in);
		if (command.out)
			close(command.out);
	}
	return (0);
}

static int	exec_pipe(t_ast *tree, int *exit_cmd, t_global *mini_s)
{
	mini_s->pipe = true;
	ph_exec_tree(tree->l, exit_cmd, mini_s);
	mini_s->pipe = false;
	ph_exec_tree(tree->r, exit_cmd, mini_s);
	return (0);
}

int	ph_exec_tree(t_ast *tree, int *exit_cmd, t_global *env)
{
	if (!tree)
		return (0);
	while (1)
	{
		if (tree->type == TEXT)
			return (ph_exec_node(tree, env));
		else if (tree->type == PARENTHESIS)
		{
			if (tree->r && tree->r->type == TEXT)
				ph_exec_par(tree->r, env);
			ph_exec_tree(tree->content, exit_cmd, env);
			return (1);
		}
		else if (tree->type == N_AND)
			return (exec_and_cmd(tree, exit_cmd, env));
		else if (tree->type == N_PIPE)
			return (exec_pipe(tree, exit_cmd, env));
		else if (tree->type == N_OR)
			return (exec_or_cmd(tree, exit_cmd, env));
	}
}

void	print_ast(t_ast *ast, int ind);

static int	handle_command(char *command, int *exit_cmd, t_global *env)
{
	t_ast	*ast_tree;

	ast_tree = NULL;
	if (!command)
		*exit_cmd = 0;
	else
	{
		setup_handler(SIGQUIT, command_handler);
		setup_handler(SIGINT, command_handler);
		ast_tree = build_ast(tokenize(command));
		print_ast(ast_tree, 0);
		if (!ast_tree)
			return (free(command), 0);
		ph_exec_tree(ast_tree, exit_cmd, env);
		free_ast(ast_tree);
		free(command);
	}
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	char		*command;
	int			exit_cmd;
	t_global	env;

	free(((void)ac, (void)av, (void)command, exit_cmd = 1, NULL));
	init(&env, envp);
	while (exit_cmd)
	{
		command = readline(env.prompt);
		free(env.prompt);
		if (command)
			handle_command(ft_strdup(command), &exit_cmd, &env);
		else
			ft_exit(&env, (char *[2]){"exit", NULL});
		(add_history(command), ft_append_history(command, env.history_fd));
		env.prompt = get_prompt(env.env);
		get_shlvl(&env);
		g_exit_status = wait_status(&env);
		setup_handler(SIGQUIT, shell_handler);
		setup_handler(SIGINT, shell_handler);
		status_env(&env.env, g_exit_status);
	}
	rl_clear_history();
	exit_cmd = ft_atoi(env.env->content);
	return (free_env(&env), free(env.prompt), close(env.history_fd), exit_cmd);
}
