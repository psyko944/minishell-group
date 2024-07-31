/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:55:46 by mekherbo          #+#    #+#             */
/*   Updated: 2024/07/28 21:11:30 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	error_line(const char *f)
{
	ft_putstr_fd("\nbash: warning: here-document", 2);
	ft_putstr_fd(" delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(f, 2);
	ft_putstr_fd("')\n", 2);
}

void	runtime_heredoc(const char *f, int *fd)
{
	int		fd_in;
	char	*line;
	size_t	eof_len;

	eof_len = ft_strlen(f);
	fd_in = dup(STDIN_FILENO);
	while (1)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(0);
		if (!line)
		{
			error_line(f);
			break ;
		}
		if (!ft_strncmp(line, f, eof_len) && line[eof_len] == '\n')
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, *fd);
		free(line);
	}
	dup2(fd_in, STDIN_FILENO);
}
