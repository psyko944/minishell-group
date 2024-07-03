/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:56:59 by arlarzil          #+#    #+#             */
/*   Updated: 2024/07/03 02:52:42 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	init(t_global *mini_s, char **envp)
{
	mini_s->env = get_env(mini_s, envp);
	mini_s->shlvl = 1;
	status_env(&mini_s->env, 0);
	mini_s->history_fd = get_history(mini_s);
	mini_s->pipe = false;
}
