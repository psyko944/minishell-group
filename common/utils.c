/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:12:48 by mekherbo          #+#    #+#             */
/*   Updated: 2024/06/24 02:02:33 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdlib.h>

int	search_in_env(t_env_var *env, char *key)
{
	t_env_var *tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen(tmp->key)))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	free_env(t_global *mini_s)
{
	t_env_var	*tmp;

	if (mini_s->envp)
		free_matrix(mini_s->envp);
	if (!mini_s->env)
		return ;
	tmp = mini_s->env;
	while (tmp)
	{
		free(tmp->key);
		free(tmp->content);
		tmp = (mini_s->env)->next;
		free(mini_s->env);
		mini_s->env = tmp;
	}
	mini_s->env = NULL;
}

void	err_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
}
