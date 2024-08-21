/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:29:57 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/21 15:56:19 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include <libft.h>
#include <stdio.h>
#include <stdlib.h>

static int	quotester(int *sub, int *step, const char **s)
{
	*sub = skip_quote(*s + *step);
	if (*sub == -1)
		return (1);
	*step += *sub;
	return (0);
}

static int	count_args(const char *s)
{
	int	res;
	int	step;
	int	sub;

	res = 0;
	while (*s)
	{
		while (ft_isspace(*s))
			++s;
		res += (*s != 0);
		step = command_sep(s);
		if (!step)
		{
			while (s[step] && !ft_isspace(s[step]) && !command_sep(s + step))
			{
				if ((s[step] == '\'' || s[step] == '"')
					&& quotester(&sub, &step, &s))
					return (-1);
				else
					step += 1;
			}
		}
		s += step;
	}
	return (res);
}

static void	fill_tab(char *s, char **res, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		while (ft_isspace(*s))
			++s;
		res[i] = s;
		while (*s && !ft_isspace(*s))
		{
			if (*s == '"' || *s == '\'')
				s += skip_quote(s);
			else
				++s;
		}
		*s = 0;
		++s;
		++i;
	}
	res[i] = NULL;
}

char	**cut_command(const char *s, int tot_len)
{
	int		len;
	char	**res;
	char	**tmp;
	char	*s2;

	if (!s || tot_len < 0)
		return (NULL);
	s2 = ft_calloc(tot_len + 2, 1);
	if (!s2)
		return (NULL);
	len = count_args(ft_strncpy(s2, s, tot_len));
	if (len == -1)
		return (NULL);
	s2 = ft_realloc(s2, tot_len + len * 2 + 2);
	res = malloc(sizeof(char *) * (len + 1));
	if (!s2 || !res)
		return (perror("malloc"), free(s2), free(res), NULL);
	add_spaces(s2);
	fill_tab(s2, res, len);
	tmp = ft_dup_tab(res);
	free(res);
	free(s2);
	if (!tmp)
		perror("malloc");
	return (tmp);
}
