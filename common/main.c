/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:00:21 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/04 08:56:17 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ast/ast.h"

#include <ast.h>
#include <minishell.h>
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

char	*replace_vars(char *s, t_env_var *env);
int	get_files(char **command, t_command *storage);
char	*remove_quotes(char *s);

static int    ph_exec_node(t_ast *node, t_global *env)
{
    t_command    command;
    int            i;

    node->content = (char **)replace_vars(node->content, env->env);
	if (!node->content)
		return (-1 /* Error code ?*/);
    command.tab = cut_command(node->content, get_sub_tok_count(node->content));
	free(node->content);
    node->content = command.tab;
	node->type = COMMAND;
    command.in = 0;
    command.out = 0;
    command.tab = node->content;
    command.tab = fill_wild_tab(command.tab, ".");
	free(node->content);
    printf("We're running: ");
    if (get_files(command.tab, &command) == 0)
        return (printf("caca\n"), 0);
    i = 0;
    node->content = command.tab;
    while (command.tab[i])
    {
		command.tab[i] = remove_quotes(command.tab[i]);
        printf("[%s] ", command.tab[i]);
        i += 1;
    }
    printf("with fds %d %d\n", command.in, command.out);
    cmd_runtime(&command, env);
    return (0);
}

 static int exec_pipe(t_ast *tree, int *exit_cmd, t_global *mini_s)
{
		fprintf(stderr,"cmd = %s\tcmd2 = %s\n\n\n\n\n\n\n", (char *)tree->l->content ,(char *)tree->r->content);
		mini_s->pipe = true;
		ph_exec_tree(tree->l, exit_cmd, mini_s);
		mini_s->pipe = false;
		ph_exec_tree(tree->r, exit_cmd, mini_s);
		return (0);
}

int	ph_exec_tree(t_ast *tree, int *exit_cmd, t_global *env)
{
	// int	status;
	if (!tree)
		return (0);
	while (1)
	{
		if (tree->type == TEXT)
		{
			//fprintf(stderr, "dada\n");
			return (ph_exec_node(tree, env));
		}
		else if (tree->type == PARENTHESIS)
			ph_exec_tree(tree->content, exit_cmd, env);
		else if (tree->type == N_AND)
		{
			ph_exec_tree(tree->l, exit_cmd, env);
			return (ph_exec_tree(tree->r, exit_cmd, env));
		}
		else if (tree->type == N_PIPE)
			return (exec_pipe(tree, exit_cmd, env));
		else if (tree->type == N_OR)
		{
			ph_exec_tree(tree->l, exit_cmd, env);
			if (ft_atoi(env->env->content) != 0)
				ph_exec_tree(tree->r, exit_cmd, env);
			return (0);
		}	
	}
}

static int	handle_command(char *command, int *exit_cmd, t_global *env)
{
	t_ast	*ast_tree;

	ast_tree = NULL;
	if (!command)
		*exit_cmd = 0;
	else
	{
		ast_tree = build_ast(tokenize(command));
		if (!ast_tree)
			__builtin_printf("Parse error\n");
		//printf("l = %s r = %s\n", (char *)ast_tree->l->content, (char *)ast_tree->r->content);
		ph_exec_tree(ast_tree, exit_cmd, env);
		//fprintf(stderr, "cmd = %s\t%s\n", command, (char *)ast_tree->r->content);
		//free_ast(ast_tree);
		free(command);
	}
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	char		*command;
	int			exit_cmd;
	t_global	env;

	(void)ac;
	(void)av;
	(void)command;
	exit_cmd = 1;
	init(&env, envp);
	while (exit_cmd)
	{
		command = readline(env.prompt);
		free(env.prompt);
		if (command)
			handle_command(ft_strdup(command), &exit_cmd, &env);
		else
			ft_exit(&env, (char *[2]){"exit", NULL});
		add_history(command);
		ft_append_history(command, env.history_fd);
		env.prompt = get_prompt(env.env);
		get_shlvl(&env);
	}
	rl_clear_history();
	exit_cmd = ft_atoi(env.env->content);
	free_env(&env);
	free(env.prompt);
	close(env.history_fd);
	return (exit_cmd);
}
