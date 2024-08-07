/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:12:48 by mekherbo          #+#    #+#             */
/*   Updated: 2024/08/07 20:59:59 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdlib.h>

int	search_in_env(t_env_var *env, char *key)
{
	t_env_var	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen(key) + 1))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

char	*get_value_search(t_env_var *env, char *key)
{
	t_env_var	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen(tmp->key)))
		{
			if (tmp->content)
				return (ft_strdup(tmp->content));
		}
		tmp = tmp->next;
	}
	return (NULL);
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
