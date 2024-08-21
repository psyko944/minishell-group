/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:56:59 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/21 21:46:54 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	init(t_global *mini_s, char **envp)
{
	ft_bzero(mini_s, sizeof(t_global));
	mini_s->env = get_env(mini_s, envp);
	mini_s->shlvl = 1;
	pwd_env(mini_s, 1);
	get_shlvl(mini_s);
	status_env(&mini_s->env, 0);
	mini_s->history_fd = get_history(mini_s);
	mini_s->pipe = false;
	mini_s->parenthese_in = -1;
	mini_s->parenthese_out = -1;
	mini_s->count_pipe = 0;
	mini_s->pid = 0;
	mini_s->old_stdin = -2;
	mini_s->prompt = get_prompt(mini_s->env);
	mini_s->old_stdin = dup(STDIN_FILENO);
	mini_s->old_stdout = dup(STDOUT_FILENO);
	g_exit_status = 0;
	prompt_sig();
}
