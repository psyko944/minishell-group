/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:00:21 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/10 20:28:32 by mekherbo         ###   ########.fr       */
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
int		get_files(char **command, t_command *storage, t_global *mini_s);
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
    if (get_files(command.tab, &command, env) == 0)
        return (printf("caca\n"), 0);
    i = 0;
	// fprintf(stderr, "entry node\n");
    node->content = command.tab;
    while (command.tab[i])
    {
		command.tab[i] = remove_quotes(command.tab[i]);
        printf("[%s] ", command.tab[i]);
        i += 1;
    }
    printf("with fds %d %d\n", command.in, command.out);
	if (command.tab[0])
    	cmd_runtime(&command, env);
    return (0);
}

 static int exec_pipe(t_ast *tree, int *exit_cmd, t_global *mini_s)
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
			ph_exec_tree(tree->content, exit_cmd, env);
			g_exit_status = wait_status(env);
			if (tree->r && tree->r->content)
				return(ph_exec_tree(tree->r, exit_cmd, env));
			return (1);
		}
		else if (tree->type == N_AND)
		{
			ph_exec_tree(tree->l, exit_cmd, env);
			fprintf(stderr,"\n\ncmd_and = %s\tcmd2 = %s\n\n", (char *)tree->l->content ,(char *)tree->r->content);
			g_exit_status = wait_status(env);
			// fprintf(stderr, "exit_status = %d\n", g_exit_status);
			if (g_exit_status == 0)
				return (ph_exec_tree(tree->r, exit_cmd, env));
			else if (g_exit_status != 0 && (tree->r->type == N_OR))
				return (ph_exec_tree(tree->r->r, exit_cmd, env));
			return (1);
		}
		else if (tree->type == N_PIPE)
			return (exec_pipe(tree, exit_cmd, env));
		else if (tree->type == N_OR)
		{
			// fprintf(stderr,"type_in_and = %d\tcmd_or = %s\tcmd2 = %s\ttype_next_node = %d\n\n",(int)tree->type ,(char *)tree->l->content ,(char *)tree->l->r->content, (int)tree->r->type);
			ph_exec_tree(tree->l, exit_cmd, env);
			g_exit_status = wait_status(env);
			 if (g_exit_status != 0)
				return (ph_exec_tree(tree->r->r, exit_cmd, env));
			 else if (g_exit_status == 0 && (tree->r->type == N_AND))
				return (ph_exec_tree(tree->r->r, exit_cmd, env));
			return (1);
		}	
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
		ast_tree = build_ast(tokenize(command));
		print_ast(ast_tree, 0);
		if (!ast_tree)
			ft_putstr_fd("bash: syntax error\n", 2);
		//printf("l = %s r = %s\n", (char *)ast_tree->l->content, (char *)ast_tree->r->content);
		ph_exec_tree(ast_tree, exit_cmd, env);
		//fprintf(stderr, "cmd = %s\t%s\n", command, (char *)ast_tree->r->content);
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
		g_exit_status = wait_status(&env);
		status_env(&env.env, g_exit_status);
	}
	rl_clear_history();
	exit_cmd = ft_atoi(env.env->content);
	free_env(&env);
	free(env.prompt);
	close(env.history_fd);
	return (exit_cmd);
}
