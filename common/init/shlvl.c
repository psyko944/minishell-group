/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shlvl.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:11:55 by mekherbo          #+#    #+#             */
/*   Updated: 2024/06/20 19:08:14 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	replace_shlvl(t_env_var *env, int shlvl)
{
	t_env_var	*tmp;
	int			n;
	char		*tmp_s;

	n = 0;
	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, "SHLVL", 5))
		{
			free(tmp->content);
			tmp->content = ft_itoa(shlvl);
			n = 1;
		}
		tmp = tmp->next;
	}
	if (!n)
	{
		tmp_s = ft_itoa(shlvl);
		addback_env(&env, first_node(ft_strjoin("SHLVL=", tmp_s)));
		free(tmp);
	}
}

void	get_shlvl(t_global *mini_s)
{
	if (getenv("SHLVL"))
		mini_s->shlvl = ft_atoi(getenv("SHLVL"));
	if (mini_s->shlvl)
		replace_shlvl(mini_s->env, mini_s->shlvl);
}
