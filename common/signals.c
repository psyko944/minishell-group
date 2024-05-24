/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:56:35 by arlarzil          #+#    #+#             */
/*   Updated: 2024/05/23 15:56:39 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>

static void	handle_sigint(int sig)
{
	(void)sig;
}

static void	handle_sigquit(int sig)
{
	(void)sig;
	return ;
}

void	init_signals(void)
{
	signal(SIGQUIT, handle_sigquit);
}
