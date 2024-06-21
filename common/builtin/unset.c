/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:57:15 by mekherbo          #+#    #+#             */
/*   Updated: 2024/06/21 19:30:33 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	remove_env(t_env_var **envp, char *key)
{
	t_env_var	*tmp;

	if (!envp || !*envp)
		return ;
	tmp = *envp;
	if (!ft_strncmp(tmp->key, key, ft_strlen(tmp->key)))
	{
		*envp = tmp->next;
		free(tmp);
		remove_env(envp, key);
	}
	else
	{
		tmp = *envp;
		remove_env(&tmp->next, key);
	}
}

void	ft_unset(t_global *mini_s, char **tab)
{
	int	i;

	i = 1;
	if (!tab[i])
	{
		printf("pas d'arguments\n");
		return ;
	}
	else if (!ft_strncmp(tab[i], "?", 1))
		;
	remove_env(&mini_s->env, tab[i]);
}
