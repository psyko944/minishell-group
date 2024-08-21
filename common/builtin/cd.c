/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 01:13:54 by mekherbo          #+#    #+#             */
/*   Updated: 2024/08/19 01:25:30 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	check_dir(char *path, t_global *mini_s)
{
	char	*pwd;
	
	pwd = NULL;
	if (path == NULL || ft_strlen(path) == 0)
		return (-1);
	pwd_env(mini_s, 0);
	if (chdir(path) != 0)
	{
		free(path);
		perror("bash: cd");
		return (-1);
	}
	pwd_env(mini_s, 1);
	free(path);
	return (0);
}

static char	*get_home(t_env_var *env)
{
	char		*home;

	home = get_value_search(env, "HOME");
	if (!home)
		g_exit_status = 1;
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

static char	*check_dash(t_env_var *env, char *path)
{
	char	*new_path;

	free(path);
	new_path = get_value_search(env, "OLDPWD");
	if (new_path)
	{
		printf("%s\n", new_path);
		return (new_path);
	}
	else
	{
		g_exit_status = 1;
		ft_putstr_fd("bash: cd: OLDPWD not set\n", 2);
		return (NULL);
	}
}

void	ft_cd(t_global *mini_s, char **tab)
{
	char	*path;

	if (!tab[1])
	{
		path = get_home(mini_s->env);
		if (!path)
		{
			ft_putstr_fd("bash: cd: HOME not set\n", 2);
			return ;
		}
	}
	else if (tab[1] && !tab[2])
		path = ft_strdup(tab[1]);
	else
		return ;
	if (!ft_strncmp(path, "-", 1))
		path = check_dash(mini_s->env, path);
	if (check_dir(path, mini_s))
	{
		g_exit_status = 1;
		return ;
	}
}
