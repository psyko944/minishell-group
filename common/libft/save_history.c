/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:05:43 by mekherbo          #+#    #+#             */
/*   Updated: 2024/06/05 17:06:29 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	cleanup(char *line, char *keep)
{
	int	i;
	int	j;
	int	end;

	j = 0;
	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	end = i + 1;
	while (line[i++])
	{
		keep[j] = line[i];
		j++;
	}
	line[end - 1] = '\0';
	keep[j] = '\0';
	return ;
}

char	*line_no_nl(int fd)
{
	char		*line;
	static char	keep[BUFFER_SIZE + 1] = {0};

	line = NULL;
	if (keep[0] != 0)
	{
		line = ft_strdup(keep);
		if (ft_strchr(line, '\n'))
			return (cleanup(line, keep), line);
	}
	ft_bzero(keep, BUFFER_SIZE + 1);
	while (read(fd, keep, BUFFER_SIZE) > 0)
	{
		if (!line)
			line = ft_strdup("");
		line = ft_strjoin2(line, keep);
		if (ft_strchr(line, '\n') || ft_strchr(line, '\0'))
			return (cleanup(line, keep), line);
		ft_bzero(keep, BUFFER_SIZE + 1);
	}
	return (line);
}
