/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:36:30 by mekherbo          #+#    #+#             */
/*   Updated: 2024/08/13 15:21:14 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ph_exec_par(t_ast *node, t_global *env)
{
	t_command	command;

	node->content = (char **)replace_vars(node->content, env->env);
	if (!node->content)
		return (-1);
	command.tab = cut_command(node->content, get_sub_tok_count(node->content));
	if (!command.tab)
		return ((node->content = NULL), 1);
	free(node->content);
	node->content = command.tab;
	node->type = COMMAND;
	command.in = 0;
	command.out = 0;
	command.tab = node->content;
	command.tab = fill_wild_tab(command.tab, ".");
	free(node->content);
	node->content = command.tab;
	if (!get_files(command.tab, &command, env))
		return (0);
	env->parenthese_in = command.in;
	env->parenthese_out = command.out;
	return (0);
}

int exec_and_cmd(t_ast *tree, int *exit_cmd, t_global *mini_s)
{
    ph_exec_tree(tree->l, exit_cmd, mini_s);
    g_exit_status = wait_status(mini_s);
    if (g_exit_status == 0)
        return (ph_exec_tree(tree->r, exit_cmd, mini_s));
    else if (g_exit_status != 0 && (tree->r->type == N_OR))
        return (ph_exec_tree(tree->r->r, exit_cmd, mini_s));
    return (1);
}

int exec_or_cmd(t_ast *tree, int *exit_cmd, t_global *mini_s)
{
    ph_exec_tree(tree->l, exit_cmd, mini_s);
    g_exit_status = wait_status(mini_s);
    if (g_exit_status != 0)
        return (ph_exec_tree(tree->r->r, exit_cmd, mini_s));
    else if (g_exit_status == 0 && (tree->r->type == N_AND))
        return (ph_exec_tree(tree->r->r, exit_cmd, mini_s));
    return (1);
}