/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:55:46 by mekherbo          #+#    #+#             */
/*   Updated: 2024/08/11 21:14:54 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	error_line(const char *f)
{
	if (g_exit_status == 135)
		return (false);
	ft_putstr_fd("\nbash: warning: here-document", 2);
	ft_putstr_fd(" delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(f, 2);
	ft_putstr_fd("')\n", 2);
	return (false);
}

static void	heredoc_handler(int sig)
{
	(void)sig;
	close(STDIN_FILENO);
	g_exit_status = 135;
}

void	runtime_heredoc(const char *f, int *fd, t_global *mini_s)
{
	int		fd_in;
	char	*line;
	size_t	eof_len;

	eof_len = ft_strlen(f);
	fd_in = dup(STDIN_FILENO);
	dup2(mini_s->old_stdin, STDIN_FILENO);
	signal(SIGINT, heredoc_handler);
	while (1 && g_exit_status != 135)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(0);
		if ((!line && !error_line(f)))
			break ;
		if (!ft_strncmp(line, f, eof_len) && line[eof_len] == '\n')
		{
			free(line);
			break ;
		}
		line = replace_vars(line, mini_s->env);
		ft_putstr_fd(line, *fd);
		free(line);
	}
	dup2(fd_in, STDIN_FILENO);
}
