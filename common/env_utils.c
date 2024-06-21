/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:14:22 by mekherbo          #+#    #+#             */
/*   Updated: 2024/06/21 21:42:15 by mekherbo         ###   ########.fr       */
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
