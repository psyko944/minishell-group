/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:56:35 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/21 22:20:56 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdio.h>
#include <readline/readline.h>
#include <signal.h>
#include <termios.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int	g_exit_status;

void	shell_handler(int sig)
{
	if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
	else if (sig == SIGINT)
	{
		g_exit_status = 130;
		write(1, "\n", 2);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	command_handler(int sig)
{
	if (sig == SIGQUIT)
	{
		g_exit_status = 131;
		printf("Quit (core dumped)\n");
	}
	else if (sig == SIGINT)
	{
		g_exit_status = 130;
	}
}

void	def_sig(void)
{
	signal(SIGINT, command_handler);
	signal(SIGQUIT, command_handler);
}

void	prompt_sig(void)
{
	signal(SIGINT, shell_handler);
	signal(SIGQUIT, shell_handler);
}
