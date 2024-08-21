/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 05:26:25 by mekherbo          #+#    #+#             */
/*   Updated: 2024/08/21 19:29:12 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <termios.h>

int	wait_status(t_global *mini_s)
{
	int	nl;
	int	ret;

	free((nl = 0, ret = -2, NULL));
	while (1)
	{
		ret = waitpid(-1, &mini_s->wait_status, 0);
		if (ret == -1)
			break ;
		// if (WIFSIGNALED(mini_s->wait_status) && WTERMSIG(mini_s->wait_status)
		// 	+ 128 == 128 + SIGINT && !nl && ++nl)
		// 	ft_putstr_fd("^C", 2);
		if (ret != mini_s->pid)
			continue ;
		if (WIFEXITED(mini_s->wait_status))
			mini_s->code = WEXITSTATUS(mini_s->wait_status);
		else
			mini_s->code = 128 + WTERMSIG(mini_s->wait_status);
		g_exit_status = mini_s->code;
	}
	prompt_sig();
	return (g_exit_status);
}
