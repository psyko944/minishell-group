/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:04:49 by mekherbo          #+#    #+#             */
/*   Updated: 2024/08/23 01:40:00 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	free_caca(t_global *env, t_command *cmd)
{
	(ft_putstr_fd("bash: ", 2), ft_putstr_fd(cmd->tab[0], 2));
	ft_putstr_fd(": Permission denied\n", 2);
	(free_env(env), freesbie(env->ast), free(env->cmd),
		tempfree(env->fribi));
}

static void	exec_cmd(t_command *cmd, t_global *env)
{
	char	*path;

	path = get_cmd(cmd->tab[0], env->envp, env);
	if (!path)
	{
		if (!access(cmd->tab[0], F_OK) && !ft_strncmp(cmd->tab[0], "./", 2))
		{
			free_caca(env, cmd);
			exit(COMMAND_NOT_EXECUTABLE);
		}
		ft_putstr_fd("bash: ", STDERR_FILENO);
		if (cmd->tab[0])
			ft_putstr_fd(cmd->tab[0], STDERR_FILENO);
		ft_putstr_fd(": command not found\n", STDERR_FILENO);
		(free_env(env), freesbie(env->ast), free(env->cmd),
			tempfree(env->fribi));
		exit(COMMAND_NOT_FOUND);
	}
	else
	{
		if (execve(path, cmd->tab, env->envp) == -1)
			(perror(path), exit(EXIT_FAILURE));
	}
}

static void	child_process(t_command *cmd, t_global *glob)
{
	if (cmd->in)
		(dup2(cmd->in, STDIN_FILENO), close(cmd->in));
	if (glob->pipe)
	{
		dup2(glob->fd[1], STDOUT_FILENO);
		close(glob->fd[0]);
		close(glob->fd[1]);
	}
	if (cmd->out)
		(dup2(cmd->out, STDOUT_FILENO), close(cmd->out));
	close(glob->old_stdin);
	close(glob->old_stdout);
	if (glob->history_fd != -1)
		close(glob->history_fd);
	if (parse_builtins(glob, cmd))
	{
		free_env(glob);
		(tempfree(glob->fribi), freesbie(glob->ast));
		free(glob->cmd);
		exit(g_exit_status);
	}
	exec_cmd(cmd, glob);
}

static void	parent_process(t_command *cmd, t_global *env)
{
	if (env->pipe)
	{
		dup2(env->fd[0], STDIN_FILENO);
		close(env->fd[1]);
		close(env->fd[0]);
	}
	else
	{
		dup2(env->old_stdin, STDIN_FILENO);
		dup2(env->old_stdout, STDOUT_FILENO);
	}
	if (cmd->in > 0)
		close(cmd->in);
	if (cmd->out > 0)
		close(cmd->out);
}

bool	cmd_runtime(t_command *cmd, t_global *env)
{
	if (!env->pipe && !env->exit_pipe)
	{
		if (cmd->in)
			(dup2(cmd->in, STDIN_FILENO), close(cmd->in));
		if (cmd->out)
			(dup2(cmd->out, STDOUT_FILENO), close(cmd->out));
		if (parse_builtins(env, cmd))
		{
			dup2(env->old_stdin, STDIN_FILENO);
			return (dup2(env->old_stdout, STDOUT_FILENO), true);
		}
	}
	if (env->pipe && pipe(env->fd) == -1)
		return (perror("pipe"), false);
	env->pid = fork();
	if (env->pid == -1)
		return (perror("fork"), false);
	else if (env->pid == 0)
		child_process(cmd, env);
	else
		parent_process(cmd, env);
	return (true);
}
