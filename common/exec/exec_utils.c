/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 05:26:25 by mekherbo          #+#    #+#             */
/*   Updated: 2024/08/22 13:51:44 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <termios.h>

int	wait_status(t_global *mini_s)
{
	int	ret;

	ret = -2;
	while (1)
	{
		ret = waitpid(-1, &mini_s->wait_status, 0);
		if (ret == -1)
			break ;
		if (ret != mini_s->pid)
			continue ;
		if (WIFEXITED(mini_s->wait_status))
			mini_s->code = WEXITSTATUS(mini_s->wait_status);
		else
		{
			if (WTERMSIG(mini_s->wait_status) == SIGQUIT)
				ft_putstr_fd("Quit (core dumped)\n", 1);
			else if (WTERMSIG(mini_s->wait_status) == SIGINT)
				ft_putchar_fd('\n', 1);
			mini_s->code = 128 + WTERMSIG(mini_s->wait_status);
		}
		g_exit_status = mini_s->code;
	}
	prompt_sig();
	return (g_exit_status);
}
