/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:57:15 by mekherbo          #+#    #+#             */
/*   Updated: 2024/07/24 08:11:18 by mekherbo         ###   ########.fr       */
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
		ft_putstr_fd("pas d'arguments\n", 2);
		return ;
	}
	else if (!ft_strncmp(tab[i], "?", 1))
		;
	if (!parse_unset(tab))
		exit(EXIT_FAILURE);
	remove_env(&mini_s->env, tab[i]);
}
