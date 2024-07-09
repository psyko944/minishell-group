/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 01:13:54 by mekherbo          #+#    #+#             */
/*   Updated: 2024/06/25 21:07:33 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	check_dir(char *path)
{
	if (path == NULL || ft_strlen(path) == 0)
		return (-1);
	if (chdir(path) != 0)
	{
		perror("chdir");
		return (-1);
	}
	return (0);
}

static char	*get_home(t_env_var *env)
{
	char		*home;
	t_env_var	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp("HOME", tmp->key, 4))
			home = ft_strdup(tmp->content);
		tmp = tmp->next;
	}
	return (home);
}

char	*get_pwd(void)
{
	char	*pwd;

	pwd = ft_calloc(4096, sizeof(char));
	if (!pwd)
		return (perror("minishell"), NULL);
	getcwd(pwd, 4096);
	return (pwd);
}

void	ft_cd(t_global *mini_s, char **tab)
{
	char	*path;

	if (!tab[1])
	{
		path = get_home(mini_s->env);
		if (!path)
			return ;
	}
	else if (tab[1] && !tab[2])
		path = tab[1];
	else
		return ;
	if (!ft_strncmp(path, "-", 1))
	{
		printf("%s", get_pwd());
		return ;
	}
	if (check_dir(path))
	{
		printf("error changement de path\n");
		return ;
	}
}
