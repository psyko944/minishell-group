/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:43:08 by mekherbo          #+#    #+#             */
/*   Updated: 2024/06/25 19:30:57 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	print_pwd(t_global *mini_s, char **tab)
{
	char	*pwd;

	(void)mini_s;
	pwd = get_pwd();
	if (pwd)
	{
		if (!tab[1])
			printf("%s\n", pwd);
		else
			printf("pwd: too many arguments");
		free(pwd);
		return ;
	}
}

static void	replace_pwd(t_global *mini_s, char *pwd)
{
	t_env_var	*tmp;
	int			n;

	n = 0;
	tmp = mini_s->env;
	while (tmp)
	{
		if (!ft_strncmp("PWD", tmp->key, 3))
		{
			free(tmp->content);
			tmp->content = get_value(pwd);
			n = 1;
		}
		tmp = tmp->next;
	}
	if (!n)
		addback_env(&mini_s->env, first_node(pwd));
}

void	pwd_env(t_global *mini_s)
{
	char	*pwd;
	char	*tmp;

	pwd = get_pwd();
	tmp = NULL;
	if (!pwd)
		perror("PWD error");
	else
	{
		tmp = ft_strjoin("PWD=", pwd);
		free(pwd);
	}
	if (!tmp)
		perror("PWD error");
	replace_pwd(mini_s, tmp);
	free(tmp);
}
