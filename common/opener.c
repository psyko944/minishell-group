/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opener.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:38:17 by arlarzil          #+#    #+#             */
/*   Updated: 2024/07/26 11:53:54 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "minishell.h"

int	open_app(const char *f, t_command *store)
{
	int	fd;

	if (store->out)
		close(store->out);
	fd = open(f, O_APPEND | O_CREAT, 0644);
	if (fd < 0)
	{
		perror(f);
		return (-1);
	}
	store->out = fd;
	return (1);
}

int	open_here(const char *f, t_command *store)
{
	int fd;

	if (store->in)
		close(store->in);	
	fd = open("/tmp/hdoc_file", O_CREAT | O_RDWR | O_TRUNC, 0644);
	runtime_heredoc(f, &fd);
	close(fd);
	fd = open("/tmp/hdoc_file", O_RDONLY);
	store->in = fd;
	if (store->in == -1)
		exit(EXIT_FAILURE);
	return (1);
}

int	open_out(const char *f, t_command *store)
{
	int	fd;

	if (store->out)
		close(store->out);
	fd = open(f, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(f);
		return (-1);
	}
	store->out = fd;
	return (1);
}

int	open_in(const char *f, t_command *store)
{
	int	fd;

	if (store->in)
		close(store->in);
	fd = open(f, O_RDONLY);
	if (fd < 0)
	{
		perror(f);
		return (-1);
	}
	store->in = fd;
	return (1);
}
