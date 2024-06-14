/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:30:24 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/14 18:06:29 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenize.h>
#include <libft.h>
#include <stdlib.h>

// Inc string todo
int	get_par_len(const char *s)
{
	int	step;
	int	ret;
	int	par_count;

	ret = 1;
	par_count = 1;
	s += 1;
	while (par_count && *s)
	{
		if (*s == '(')
			par_count += 1;
		else if (*s == ')')
			par_count -= 1;
		if (*s == '"' || *s == '\'')
			step = skip_quote(s);
		else
			step = 1;
		if (step == -1)
			return (-1);
		s += step;
		ret += step;
	}
	if (par_count)
		return (-1);
	return (ret);
}

t_token	*get_parenthesis(const char **s_ptr)
{
	int			len;
	const char	*temp;

	while (ft_isspace(**s_ptr))
		++*s_ptr;
	temp = *s_ptr;
	len = get_par_len(temp);
	if (len == -1)
		return (NULL);
	*s_ptr += len;
	return (new_token(PARENTHESIS,
			ft_strndup_e(temp + 1, len - 2)));
}

size_t	is_sep(const char	*s)
{
	const char	*seps[] = {"||", "&&", "|", NULL};
	int			i;
	size_t		sep_len;

	i = 0;
	while (seps[i])
	{
		sep_len = ft_strlen(seps[i]);
		if (ft_strncmp(s, seps[i], sep_len) == 0)
			return (sep_len);
		i += 1;
	}
	return (0);
}

t_token	*get_word(const char **s)
{
	const char	*s2;
	int			len;
	int			step;

	s2 = *s;
	len = 0;
	step = is_sep(s2);
	if (step)
	{
		*s += step;
		return (new_token(SEPARATOR, ft_strndup_e(s2, step)));
	}
	while (**s && !is_sep(*s))
	{
		if (**s == '\'' || **s == '"')
			step = skip_quote(*s);
		else
			step = 1;
		if (step == -1)
			return (NULL);
		len += step;
		*s += step;
	}
	return (new_token(TEXT, cut_command(s2, len)));
}
