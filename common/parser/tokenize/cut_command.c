/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:29:57 by arlarzil          #+#    #+#             */
/*   Updated: 2024/05/28 17:06:52 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include "../../libft/libft.h"

#include <stdlib.h>

static int	command_sep(const char *s)
{
	const char	*seps[] = {">>", "<<", ">", "<", NULL};
	int			i;
	int			len;

	i = 0;
	while (seps[i])
	{
		len = ft_strlen(seps[i]);
		if (ft_strncmp(s, seps[i], len) == 0)
			return (len);
		++i;
	}
	return (0);
}

static int	count_args(const char *s)
{
	int	res;
	int	step;

	res = 0;
	while (*s)
	{
		while (ft_isspace(*s))
			++s;
		if (*s)
			res += 1;
		step = command_sep(s);
		if (!step)
		{
			while (s[step] && !ft_isspace(s[step]) && !command_sep(s + step))
			{
				if (*s == '\'' || *s == '"')
					step += skip_quote(s);
				else
					step += 1;
			}
		}
		s += step;
	}
	return (res);
}

static void	add_spaces(char *s)
{
	int	step;

	while (*s)
	{
		step = command_sep(s);
		if (step)
		{
			ft_memmove(s + 1, s, ft_strlen(s));
			*s = ' ';
			s += step + 1;
			ft_memmove(s + 1, s, ft_strlen(s));
			*s = ' ';
			s += 1;
		}
		else
			++s;
	}
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
	char	*s2;

	if (!s)
		return (NULL);
	s2 = ft_calloc(tot_len + 2, 1);
	if (!s2)
		return (NULL);
	ft_strncpy(s2, s, tot_len);
	len = count_args(s2);
	printf("%s len: %d\n", s2, tot_len + len + 1);
	s2 = ft_realloc(s2, tot_len + len + 1);
	res = malloc(sizeof(char *) * (len + 1));
	if (!s2 || !res)
		return (free(s2), free(res), NULL);
	add_spaces(s2);
	fill_tab(s2, res, len);
	return (res);
}
