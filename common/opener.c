/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opener.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <armand.larzilliere@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:38:17 by arlarzil          #+#    #+#             */
/*   Updated: 2024/05/30 17:04:58 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include "minishell.h"

int	open_app(const char *f, t_command *store)
{
	int	fd;

	if (store->out)
		close(store->out);
	fd = open(f, O_APPEND | O_CREAT);
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
	printf("Heredoc still to do\n");
	if (store->in)
		close(store->out);
	return (0);
}

int	open_out(const char *f, t_command *store)
{
	int	fd;

	if (store->out)
		close(store->out);
	fd = open(f, O_WRONLY | O_CREAT | O_TRUNC);
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
