/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:57:15 by mekherbo          #+#    #+#             */
/*   Updated: 2024/08/21 21:56:53 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	parse_unset(char **tab)
{
	if (tab[1][0] == '-' && tab[1][1])
	{
		ft_putstr_fd("bash: unset: ", 2);
		ft_putstr_fd(&tab[1][0], 2);
		ft_putstr_fd(": invalid option\n", 2);
		ft_putstr_fd("unset: usage: unset [-f] [-v] [-n] [name ...]\n", 2);
		g_exit_status = 2;
		return (false);
	}
	return (true);
}

void	remove_env(t_env_var **envp, char *key)
{
	t_env_var	*tmp;

	if (!envp || !*envp)
		return ;
	tmp = *envp;
	if (!ft_strncmp(tmp->key, key, ft_strlen(tmp->key)))
	{
		*envp = tmp->next;
		free(tmp->key);
		free(tmp->content);
		free(tmp);
		remove_env(envp, key);
	}
	else
	{
		tmp = *envp;
		remove_env(&tmp->next, key);
	}
}

char	**new_matrix(t_env_var *env)
{
	char		**new_matrix;
	char		*tmp;
	t_env_var	*env_tmp;

	new_matrix = calloc(sizeof(char *), 2);
	if (!new_matrix)
		return (NULL);
	env_tmp = env;
	while (env_tmp)
	{
		if (!ft_strncmp(env_tmp->key, "PATH", 4))
		{
			tmp = ft_strjoin(env_tmp->key, "=");
			new_matrix[0] = ft_strjoin2(tmp, env_tmp->content);
		}
		env_tmp = env_tmp->next;
	}
	return (new_matrix);
}

void	ft_unset(t_global *mini_s, char **tab)
{
	int	i;

	i = 1;
	g_exit_status = 0;
	if (!tab[i])
		return ;
	else if (!ft_strncmp(tab[i], "?", 1))
		return ;
	if (!parse_unset(tab))
		return ;
	remove_env(&mini_s->env, tab[i]);
	free_matrix(mini_s->envp);
	mini_s->envp = new_matrix(mini_s->env);
}
