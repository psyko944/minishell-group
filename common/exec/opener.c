/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opener.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:38:17 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/11 21:55:13 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "minishell.h"

int	open_app(const char *f, t_command *store, t_global *mini_s)
{
	int	fd;

	if (store->out)
		close(store->out);
	(void)mini_s;
	fd = open(f, O_APPEND | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(f);
		g_exit_status = 1;
		return (-1);
	}
	store->out = fd;
	return (1);
}

int	open_here(const char *f, t_command *store, t_global *mini_s)
{
	int	fd;

	if (store->in)
		close(store->in);
	fd = open("/tmp/hdoc_file", O_CREAT | O_RDWR | O_TRUNC, 0644);
	runtime_heredoc(f, &fd, mini_s);
	close(fd);
	if (g_exit_status == 135)
	{
		g_exit_status = 130;
		return (-1);
	}
	fd = open("/tmp/hdoc_file", O_RDONLY);
	store->in = fd;
	if (store->in == -1)
		exit(EXIT_FAILURE);
	return (1);
}

int	open_out(const char *f, t_command *store, t_global *mini_s)
{
	int	fd;

	if (store->out)
		close(store->out);
	(void)mini_s;
	fd = open(f, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(f);
		g_exit_status = 1;
		return (-1);
	}
	store->out = fd;
	return (1);
}

int	open_in(const char *f, t_command *store, t_global *mini_s)
{
	int	fd;

	if (store->in)
		close(store->in);
	(void)mini_s;
	fd = open(f, O_RDONLY);
	if (fd < 0)
	{
		perror(f);
		g_exit_status = 1;
		return (-1);
	}
	store->in = fd;
	return (1);
}
