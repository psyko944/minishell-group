/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:56:59 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/22 13:38:08 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <termios.h>
#include <unistd.h>

static void	deactivate_signal_echo(void)
{
	struct termios	term;

	tcgetattr(0, &term);
	term.c_lflag &= ~ECHOCTL;
	tcsetattr(0, 0, &term);
}

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
	deactivate_signal_echo();
}
