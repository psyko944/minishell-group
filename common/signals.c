/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:56:35 by arlarzil          #+#    #+#             */
/*   Updated: 2024/07/09 21:38:38 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <signal.h>
#include <termios.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int g_exit_status;

static void	handle_sigquit(int sig)
{
	(void)sig;

    printf("g_exit_status: %d\n", g_exit_status);
	rl_cleanup_after_signal();
	rl_free_line_state();
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	return ;
}

void	sigint_2(int sig)
{
	(void)sig;
	// Interrompt le programme en cours
}

void	handle_sigint(int sig)
{
	(void)sig;

	g_exit_status = 130;	
    rl_replace_line("", 0);
    rl_crlf();
    rl_on_new_line();
    rl_redisplay(); 
}

void	init_signals(void)
{
    struct sigaction sa;
    struct termios oldt;

    tcgetattr(STDIN_FILENO, &oldt);
    oldt.c_lflag &= ~(ECHOCTL);
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_RESTART;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }
	signal(SIGQUIT, handle_sigquit);
	// signal(SIGINT, handle_sigint);
}
