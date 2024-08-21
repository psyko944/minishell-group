/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:56:35 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/21 15:53:49 by arlarzil         ###   ########.fr       */
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
		rl_replace_line("", 0);
		write(1, "\r\n", 2);
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
		printf("\n");
	}
}

void	setup_handler(int sig, void (*handler)(int))
{
	struct sigaction	sa;

	sa.sa_handler = handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(sig, &sa, NULL))
		perror("sigaction");
}

void	init_signals(void)
{
	struct termios	oldt;

	tcgetattr(STDIN_FILENO, &oldt);
	oldt.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	setup_handler(SIGINT, shell_handler);
	setup_handler(SIGQUIT, shell_handler);
}
