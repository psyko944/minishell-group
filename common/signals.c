/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:56:35 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/21 19:44:58 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <signal.h>
/*
static void	handle_sigint(int sig)
{
	(void)sig;
}
*/
static void	handle_sigquit(int sig)
{
	(void)sig;

	rl_cleanup_after_signal();
	rl_free_line_state();
	rl_on_new_line();
	rl_replace_line("  ", 0);
	rl_redisplay();
	return ;
}

void	init_signals(void)
{
	signal(SIGQUIT, handle_sigquit);
}
