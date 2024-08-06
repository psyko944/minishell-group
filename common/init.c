/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:56:59 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/06 11:26:58 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

extern int	g_exit_status;

void	init(t_global *mini_s, char **envp)
{
	ft_bzero(mini_s, sizeof(t_global));
	mini_s->env = get_env(mini_s, envp);
	mini_s->shlvl = 1;
	status_env(&mini_s->env, 0);
	mini_s->history_fd = get_history(mini_s);
	mini_s->pipe = false;
	mini_s->count_pipe = 0;
	mini_s->pid = 0;
	mini_s->old_stdin = -2;
	mini_s->prompt = get_prompt(mini_s->env);
	mini_s->old_stdin = dup(STDIN_FILENO);
	mini_s->old_stdout = dup(STDOUT_FILENO);
	g_exit_status = 5;
	init_signals();
	//printf("%d", g_exit_status);
}
