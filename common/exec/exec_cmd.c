/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:04:49 by mekherbo          #+#    #+#             */
/*   Updated: 2024/08/07 12:52:38 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	exec_cmd(t_command *cmd, t_global *env)
{
	char	*path;

	path = get_cmd(cmd->tab[0], env->envp);
	if (!path)
	{
		if (!access(cmd->tab[0], F_OK) && !ft_strncmp(cmd->tab[0], "./", 2))
		{
			(ft_putstr_fd("bash: ", 2), ft_putstr_fd(cmd->tab[0], 2));
			ft_putstr_fd(": Permission denied\n", 2);
			exit(COMMAND_NOT_EXECUTABLE);
		}
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
	}
}

static void child_process(t_command *cmd, t_global *env)
{
	if (cmd->in)
			dup2(cmd->in, STDIN_FILENO);
		if (env->pipe)
		{
			dup2(env->fd[1], STDOUT_FILENO);
			close(env->fd[0]);
			close(env->fd[1]);
		}
		if (cmd->out)
			dup2(cmd->out, STDOUT_FILENO);
		if (env->pipe)
		{
			if (parse_builtins(env, cmd))
				exit(0);
		}
		close(env->old_stdin);
		close(env->old_stdout);
		close(env->history_fd);
		exec_cmd(cmd, env);
}


void	cmd_runtime(t_command *cmd, t_global *env)
{
	if (!env->pipe)
	{
		if (cmd->in)
			dup2(cmd->in, STDIN_FILENO);
		if (cmd->out)
			dup2(cmd->out, STDOUT_FILENO);
		if (parse_builtins(env, cmd))
		{
			dup2(env->old_stdin, STDIN_FILENO);
			// dup2(env->old_stdout, STDOUT_FILENO);
			return ;
		}
	}
	if (env->pipe && pipe(env->fd) == -1)
	{
		perror("pipe");
		return ;
	}
	env->pid = fork();
	if (env->pid == -1)
	{
		perror("fork");
		return ;
	}
	else if (env->pid == 0)
		child_process(cmd, env);
	else
	{
		if (env->pipe)
		{
			dup2(env->fd[0], STDIN_FILENO);
			close(env->fd[1]);
			close(env->fd[0]);
		}
		else
			dup2(env->old_stdin, STDIN_FILENO);
	}
}
