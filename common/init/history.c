/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 19:09:23 by mekherbo          #+#    #+#             */
/*   Updated: 2024/06/25 19:00:06 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_append_history(char *cmd, int fd)
{
	ft_putendl_fd(cmd, fd);
}

static char	*check_history_name(t_global *mini_s)
{
	t_env_var	*tmp;

	tmp = mini_s->env;
	if (!tmp)
		return (NULL);
	while (tmp && ft_strncmp("HOME", tmp->key, 4))
		tmp = tmp->next;
	if (tmp && tmp->content)
		return (tmp->content);
	return (NULL);
}

int	get_history(t_global *mini_s)
{
	char	*history_filename;
	char	*save_history;
	int		fd;

	if (mini_s->env)
	{
		history_filename = check_history_name(mini_s);
		if (!history_filename)
			return (-1);
	}
	history_filename = ft_strjoin3(history_filename, "/.", HISTORY_NAME);
	if (!history_filename)
		return (-1);
	fd = open(history_filename, O_CREAT | O_RDWR | O_APPEND, 0600);
	if (fd == -1)
		return (free(history_filename), fd);
	save_history = line_no_nl(fd);
	while (save_history)
	{
		add_history(save_history);
		free(save_history);
		save_history = line_no_nl(fd);
	}
	return (free(history_filename), fd);
}
