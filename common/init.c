/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:56:59 by arlarzil          #+#    #+#             */
/*   Updated: 2024/07/16 18:29:26 by mekherbo         ###   ########.fr       */
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
	mini_s->old_stdin = -2;
	g_exit_status = 5;
	init_signals();
	//printf("%d", g_exit_status);
}
