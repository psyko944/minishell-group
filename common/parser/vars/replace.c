/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:18:22 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/07 15:12:43 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <vars.h>
#include <stdlib.h>

extern int	g_exit_status;

static char	*isolate_var(char *s)
{
	int	i;

	++s;
	i = 0;
	if (*s == '{')
	{
		while (s[i] != '}')
			i += 1;
		s[i] = 0;
		++s;
	}
	return (s);
}

static char	*get_var(char *s, t_env_var *env)
{
	char	*name;
	char	*cont;

	if (*s != '$')
		return (s);
	name = isolate_var(s);
	if (*name == '?')
		return (ft_itoa(g_exit_status));
	while (env)
	{
		if (ft_strcmp(name, env->key) == 0)
			break ;
		env = env->next;
	}
	if (!env)
		cont = "";
	else
		cont = env->content;
	return (free(s), ft_strdup(cont));
}

char	*replace_vars(char *s, t_env_var *env)
{
	char	**temp;
	int		i;

	i = 0;
	temp = cut_vars(s);
	if (!temp)
		return (NULL);
	while (temp[i])
	{
		temp[i] = get_var(temp[i], env);
		i += 1;
	}
	return (concat_tab(temp));
}
