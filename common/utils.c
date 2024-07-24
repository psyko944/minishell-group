/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:12:48 by mekherbo          #+#    #+#             */
/*   Updated: 2024/07/24 11:04:14 by mekherbo         ###   ########.fr       */
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

char	*get_value_search(t_env_var *env, char *key)
{
	t_env_var *tmp;

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

static void	free_env2(t_env_var **env)
{
	t_env_var *tmp;

	tmp = *env;
	while (tmp)
	{
		//fprintf(stderr, "key=%s\tcontent=%s\n", tmp->key, tmp->content);
		if (tmp->key)
			free(tmp->key);
		if (tmp->content)
			free(tmp->content);
		tmp = (*env)->next;
		free(*env);
		*env = tmp;
	}
	*env = NULL;
}

void	free_env(t_global *mini_s)
{
	if (mini_s->envp)
		free_matrix(mini_s->envp);
	if (!mini_s->env)
		return ;
	free_env2(&mini_s->env);
	// tmp = mini_s->env;
	// while (tmp)
	// {
	// 	fprintf(stderr ,"test env\n");
	// 	free(tmp->key);
	// 	free(tmp->content);
	// 	tmp = (mini_s->env)->next;
	// 	free(mini_s->env);
	// 	mini_s->env = tmp;
	// }
	//mini_s->env = NULL;
}

void	err_msg(char *msg)
{
	ft_putstr_fd(msg, 2);
}
