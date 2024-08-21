/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:56:35 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/21 20:28:41 by arlarzil         ###   ########.fr       */
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
		// printf("\n");
	}
}

void	def_sig(void)
{
	// struct sigaction	sa;

	puts("Setting up command sig\n");
	//sigemptyset(&sa.sa_mask);
	// sa.sa_handler = command_handler;
	if (signal(SIGINT, command_handler))
		perror("sigation");
	else if (signal(SIGQUIT, command_handler))
		perror("sigaction");
	// puts("OUMPS OUMPS");
}

void	prompt_sig(void)
{
	struct sigaction	sa;

	puts("Setting up prompt sig\n");
	// sigemptyset(&sa.sa_mask);
	sa.sa_handler = shell_handler;
	if (sigaction(SIGINT, &sa, NULL))
		perror("sigaction");
	else if (sigaction(SIGQUIT, &sa, NULL))
		perror("sigaction");
	// puts("TOUSS TOUSS");
}

void	here_sig(void)
{
	// struct sigaction	sa;

	// // puts("Setting up heredoc sig\n");
	// // sigemptyset(&sa.sa_mask);
	// sa.sa_handler = SIG_IGN;
	// if (sigaction(SIGINT, &sa, NULL))
	// 	perror("sigaction");
	// else if (sigaction(SIGQUIT, &sa, NULL))
	// 	perror("sigaction");
	// // puts("COUS COUS");
}
