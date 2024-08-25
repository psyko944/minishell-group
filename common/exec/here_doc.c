/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:55:46 by mekherbo          #+#    #+#             */
/*   Updated: 2024/08/23 02:27:39 by mekherbo         ###   ########.fr       */
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
	printf("^C\n");
	g_exit_status = 135;
}

static char	*free_hdoc(char *line, t_global *mini_s)
{
	char	*new_line;

	new_line = replace_vars(line, mini_s->env);
	free(line);
	return (new_line);
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
	signal(SIGQUIT, heredoc_handler);
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
		line = free_hdoc(line, mini_s);
		ft_putstr_fd(line, *fd);
		free(line);
	}
	(dup2(fd_in, STDIN_FILENO), close(fd_in));
}
