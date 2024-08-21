/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 14:06:49 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/21 15:16:29 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdbool.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

static bool	check_match(const char *exp, const char *str)
{
	while (1)
	{
		if (!*exp && !*str)
			return (true);
		else if (*exp == '*' && exp[1] && !*str)
			return (false);
		else if (*exp == '?' || *exp == *str)
		{
			++exp;
			++str;
		}
		else if (*exp == '*')
			return (check_match(exp + 1, str) || check_match(exp, str + 1));
		else
			return (false);
	}
}

static int	count_matches(const char *exp, const char *path)
{
	DIR				*dir;
	struct dirent	*entry;
	int				count;

	count = 0;
	dir = opendir(path);
	if (dir == NULL)
		return (perror("opendir"), -1);
	entry = readdir(dir);
	while (entry)
	{
		if (check_match(exp, entry->d_name))
			++count;
		entry = readdir(dir);
	}
	closedir(dir);
	return (count);
}

static char	**fill_tab(const char *exp, const char *path, char **res)
{
	DIR				*dir;
	struct dirent	*entry;
	int				i;

	i = 0;
	dir = opendir(path);
	if (dir == NULL)
		return (perror("opendir"), NULL);
	entry = readdir(dir);
	while (entry)
	{
		if (check_match(exp, entry->d_name))
		{
			res[i] = ft_strdup(entry->d_name);
			if (!res[i])
				return (perror("malloc"), free_tab(res), NULL);
			++i;
		}
		entry = readdir(dir);
	}
	closedir(dir);
	return (res);
}

char	**get_matches(const char *exp, const char *path)
{
	char			**res;
	int				count;

	count = count_matches(exp, path);
	if (count == 0)
	{
		res = ft_calloc(2, sizeof(char *));
		if (!res)
			return (perror("malloc"), NULL);
		res[0] = ft_strdup(exp);
		if (!res[0])
			return (free(res), perror("malloc"), NULL);
		return (res);
	}
	else if (count == -1)
		return (NULL);
	res = ft_calloc(count + 1, sizeof(char *));
	if (!res)
		return (perror("malloc"), NULL);
	res = fill_tab(exp, path, res);
	return (res);
}

char	**fill_wild_tab(char **base, const char *path)
{
	char	**temp;
	char	**res;

	res = NULL;
	if (!base)
		return (NULL);
	while (*base)
	{
		if (ft_strchr(*base, '*'))
		{
			temp = get_matches(*base, path);
			if (!temp)
				return (free_tab(res), NULL);
			if (!res)
				res = temp;
			else
				res = merge_tabs(res, temp);
			free(*base);
		}
		else
			res = tab_add_back(res, *base);
		++base;
	}
	return (res);
}
