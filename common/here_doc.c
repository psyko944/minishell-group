/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 22:55:46 by mekherbo          #+#    #+#             */
/*   Updated: 2024/07/24 04:51:43 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	runtime_heredoc(const char *f,int *fd)
{
	int		fd_in = dup(STDIN_FILENO);
	char	*line;
	size_t	delimiter_len;

	delimiter_len = ft_strlen(f);
	while (1)
	{
		ft_putstr_fd("> ", 1);
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, f, delimiter_len) == 0
			&& line[delimiter_len] == '\n')
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, *fd);
		free(line);
	}
	dup2(fd_in, STDIN_FILENO);
}