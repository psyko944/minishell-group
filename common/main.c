/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:00:21 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/23 03:31:57 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ast/ast.h"

#include <ast.h>
#include <minishell.h>
#include <libft.h>
#include <termios.h>
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

	if (set_node(node, env, &command) == -1)
		return (-1);
	if (!command.tab)
		return ((node->content = NULL), 1);
	free(node->content);
	node->content = command.tab;
	if (!get_files(command.tab, &command, env))
		return (0);
	i = 0;
	while (command.tab[i])
	{
		command.tab[i] = remove_quotes(command.tab[i]);
		i += 1;
	}
	launch_cmd(&command, env);
	return (0);
}

static int	exec_pipe(t_ast *tree, int *exit_cmd, t_global *mini_s)
{
	mini_s->exit_pipe = true;
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
		if (!tree->r)
			env->par_flag = true;
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

static int	handle_command(char *command, int *exit_cmd,
	t_global *env, struct termios *term)
{
	t_ast			*ast_tree;

	ast_tree = NULL;
	if (!command)
		*exit_cmd = 0;
	else
	{
		ast_tree = build_ast(tokenize(command, env));
		if (!ast_tree)
			return (env->hflag = true, free(command), 0);
		env->hflag = false;
		def_sig();
		tcgetattr(0, term);
		env->ast = ast_tree;
		env->cmd = command;
		ph_exec_tree(ast_tree, exit_cmd, env);
		free_ast(ast_tree);
		free(command);
		env->cmd = NULL;
		env->ast = NULL;
		env->exit_pipe = false;
	}
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	char			*command;
	int				exit_cmd;
	t_global		env;
	struct termios	term;

	free(((void)ac, (void)av, (void)command, exit_cmd = 1, NULL));
	init(&env, envp);
	while (exit_cmd)
	{
		command = readline(env.prompt);
		free(env.prompt);
		if (command)
			handle_command(ft_strdup(command), &exit_cmd, &env, &term);
		else
			ft_exit(&env, (char *[2]){"exit", NULL});
		if (env.hflag == false)
			(add_history(command), ft_append_history(command, env.history_fd),
				fribille((void**)env.fribi));
		env.prompt = get_prompt(env.env);
		g_exit_status = wait_status(&env);
		(get_shlvl(&env), status_env(&env.env, g_exit_status), free(command));
	}
	rl_clear_history();
	exit_cmd = ft_atoi(env.env->content);
	return (free_env(&env), free(env.prompt), close(env.history_fd), exit_cmd);
}
