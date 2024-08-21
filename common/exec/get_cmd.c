/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:27:25 by mekherbo          #+#    #+#             */
/*   Updated: 2024/08/21 22:25:08 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	**get_paths(char **envp)
{
	char	**paths;
	char	*path;
	char	*tmp;
	int		i;

	i = -1;
	while (envp[++i])
	{
		path = ft_strnstr(envp[i], "PATH=", 5);
		if (path)
		{
			path = path + 5;
			break ;
		}
	}
	paths = ft_split(path, ':');
	i = -1;
	while (paths && paths[++i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free(tmp);
	}
	return (paths);
}

static char	*get_cmd_path(char **paths, char *cmd)
{
	int		i;
	char	*cmd_path;

	i = -1;
	while (paths[++i])
	{
		cmd_path = ft_strjoin(paths[i], cmd);
		if (!cmd_path)
		{
			free_matrix(paths);
			exit(EXIT_FAILURE);
		}
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (NULL);
}

static bool	check_dir(char *cmd)
{
	if (opendir(cmd))
	{
		if (!ft_strncmp(cmd, "./", 2) || !ft_strncmp(cmd, "/", 1))
		{
			(ft_putstr_fd("bash: ", 2), ft_putstr_fd(cmd, 2));
			ft_putstr_fd(": Is a directory\n", 2);
			exit(COMMAND_ISDIRECTORY);
		}
		return (false);
	}
	return (true);
}

char	*get_cmd(char *cmd, char **envp)
{
	char	**paths;
	char	*cmd_path;

	if (cmd[0] == '\0')
		return (NULL);
	if (!check_dir(cmd))
		return (NULL);
	if (access(cmd, F_OK | X_OK) == 0)
		return (ft_strdup(cmd));
	if (!envp || !envp[0])
		return (NULL);
	paths = get_paths(envp);
	if (!paths)
		return (NULL);
	cmd_path = get_cmd_path(paths, cmd);
	if (!cmd_path)
	{
		return (free_matrix(paths), NULL);
	}
	free_matrix(paths);
	return (cmd_path);
}
