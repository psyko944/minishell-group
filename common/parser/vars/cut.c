/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:12:12 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/21 15:17:08 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <stdlib.h>
#include <stdio.h>

static int	skip_dol(const char **s)
{
	*s += 1;
	if (**s == '?' || ft_isdigit(**s))
		*s += 1;
	else if (**s == '{')
		*s = ft_strchr(*s, '}');
	else
	{
		while (ft_isalnum(**s))
			++*s;
	}
	if (!*s)
		return (-1);
	return (1);
}

static int	skip_var(const char **s)
{
	if (**s == '$')
		return (skip_dol(s));
	else
	{
		while (**s && **s != '$')
		{
			if (**s == '\'')
				*s = ft_strchr(*s + 1, '\'');
			if (*s == (char *)1)
				return (-1);
			++*s;
		}
	}
	return (1);
}

static int	var_count(const char *s)
{
	int	res;

	res = 0;
	while (*s)
	{
		if (skip_var(&s) == -1)
			return (-1);
		++res;
	}
	return (res);
}

static int	get_word_len(char *s)
{
	int	i;

	i = 0;
	if (*s == '$')
	{
		i += 1;
		if (s[i] == '?' || ft_isdigit(s[i]))
			return (2);
		if (s[1] == '{')
			return (ft_strchr(s, '}') - s + 1);
		while (ft_isalnum(s[i]))
			i += 1;
	}
	else
	{
		while (s[i] && s[i] != '$')
		{
			if (s[i] == '\'')
				return (i + get_word_len(ft_strchr(s + i + 1, '\'') + 1)
					+ ft_strchr(s + i + 1, '\'') - s + i + 1);
			++i;
		}
	}
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
	if (!res)
		return (perror("malloc"), NULL);
	i = 0;
	while (i < len)
	{
		w_len = get_word_len(s);
		res[i] = ft_strndup_e(s, w_len);
		s += w_len;
		i += 1;
	}
	return (res);
}
