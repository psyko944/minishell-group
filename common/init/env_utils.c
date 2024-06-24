/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:14:22 by mekherbo          #+#    #+#             */
/*   Updated: 2024/06/24 02:03:28 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	addfront_env(t_env_var **env, t_env_var *new)
{
	if (!new || !env)
		return ;
	if (*env)
		new->next = *env;
	*env = new;
}

void	concat_env(t_env_var **env, char *value)
{
	t_env_var *tmp;
	char	*key;
	char	*concat;

	key = get_key(value);
	concat = get_value(value);
	tmp = *env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, key, ft_strlen(tmp->key)))
			tmp->content = ft_strjoin2(tmp->content, concat);
		tmp = tmp->next;
	}
	free(concat);
}
void	status_env(t_env_var **env, int status)
{
	char	*str_status;
	char	*tmp;

	str_status = ft_itoa(status);
	if (!str_status)
		return ;
	tmp = ft_strjoin("?=", str_status);
	free(str_status);
	if (!tmp)
		return ;
	addfront_env(env, first_node(tmp));
	free(tmp);
}

void	replace_env(t_env_var *env, char *value)
{
	t_env_var *tmp;
	char		*key;
	char		*content;

	tmp = env;
	key = get_key(value);
	content = get_value(value);
	if (!content)
		return ;
	while (tmp)
	{
		if (!ft_strncmp(tmp->key, value, ft_strlen(tmp->key)))
		{
			free(tmp->content);
			tmp->content = content;
		}
		tmp = tmp->next;
	}
	free(key);
}

void	print_env(t_env_var *lst)
{
	t_env_var	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->content != NULL && tmp->key && ft_strncmp(tmp->key, "?", 1))
			printf("%s=%s\n", tmp->key, tmp->content);
		tmp = tmp->next;
	}
}
