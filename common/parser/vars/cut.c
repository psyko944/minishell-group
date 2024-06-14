/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:12:12 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/14 12:21:51 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include "../../libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	var_count(const char *s)
{
	int	res;

	res = 0;
	while (*s)
	{
		if (*s == '$')
		{
			if (*(++s) == '{')
				s = ft_strchr(s, '}');
			else
			{
				while (*s && *s != ' ' && *s != '$')
					++s;
			}
			if (!s)
				return (-1);
		}
		else
		{
			while (*s && *s != '$')
				++s;
		}
		++res;
	}
	return (res);
}

static int	get_word_len(char *s)
{
	int	i;

	i = 1;
	if (*s == '$')
	{
		if (s[i] == '?')
			return (2);
		if (s[1] == '{')
			return (ft_strchr(s, '}') - s + 1);
		while (s[i] && s[i] != ' ' && s[i] != '$')
			i += 1;
	}
	else
		while (s[i] && s[i] != '$')
			i += 1;
	return (i);
}

char	**cut_vars(char *s)
{
	char	**res;
	int		len;
	int		i;
	int		w_len;

	len = var_count(s);
	if (len == -1)
		return (ft_putstr_fd("Parse error: unclosed var\n", 2), NULL);
	res = ft_calloc(len + 1, sizeof(char *));
	printf("%d words\n", len);
	if (!res)
		return (perror("malloc"), NULL);
	i = 0;
	while (i < len)
	{
		w_len = get_word_len(s);
		printf("%s: len %d\n", s, w_len);
		res[i] = ft_strndup_e(s, w_len);
		s += w_len;
		i += 1;
	}
	return (res);
}
/*
int	main(int ac, char **av)
{
	char	**tab = cut_vars(av[ac - 1]);
	char	**pt = tab;

	while (*pt)
	{
		printf("%s\n", *pt);
		free(*pt);
		++pt;
	}
	free(tab);
}*/
