/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:04:49 by mekherbo          #+#    #+#             */
/*   Updated: 2024/07/09 21:52:52 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	exec_cmd(t_command *cmd, t_global *env)
{
	char	*path;

	path = get_cmd(cmd->tab[0], env->envp);
	if (!path)
	{
		if (cmd->tab[0])
			ft_putstr_fd(cmd->tab[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		exit(COMMAND_NOT_FOUND);
	}
	else
	{
		if (execve(path, cmd->tab, env->envp) == -1)
		{
			perror(path);
			exit(EXIT_FAILURE);
		}
		exit(EXIT_FAILURE);
	}
}

void	cmd_runtime(t_command *cmd, t_global *env)
{
	pid_t	pid;
	//int		fd[2];

	if (parse_builtins(env, cmd))
		return ;
	if (pipe(env->fd) == -1)
	{
		perror("pipe");
		return ;
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	else if (pid == 0)
	{
		if (cmd->in)
			dup2(cmd->in, STDIN_FILENO);
		close(env->fd[0]);
		if (cmd->out)
			dup2(cmd->out, STDOUT_FILENO);
		if (env->pipe)
		{
			fprintf(stderr, "===error pipe===\n\n\n\n\n");
			dup2(env->fd[1], STDOUT_FILENO);
		}
		close(env->fd[1]);
		exec_cmd(cmd, env);
	}
	else
	{
		if (env->pipe)
		{
			fprintf(stderr, "\n\n\n\npipe is true\n\n\n\n");
			dup2(env->fd[0], STDIN_FILENO);
		}
		env->pipe = false;
		close(env->fd[0]);
		close(env->fd[1]);
		wait(NULL);
	}
}
