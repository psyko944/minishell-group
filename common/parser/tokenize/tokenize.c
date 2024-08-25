/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:31:15 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/23 00:04:09 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenize.h>
#include <libft.h>
#include <minishell.h>
#include <stdlib.h>

static t_token	*add_back(t_token *node, t_token **ls)
{
	t_token	*cur;

	if (!*ls)
		*ls = node;
	else
	{
		cur = *ls;
		while (cur->next)
			cur = cur->next;
		cur->next = node;
		node->prev = cur;
	}
	return (*ls);
}

t_token	*tokenize(const char *s, t_global *glo)
{
	t_token	*res;
	t_token	*new;

	res = NULL;
	while (*s)
	{
		while (ft_isspace(*s))
			++s;
		if (!*s)
			break ;
		if (*s == '(')
			new = get_parenthesis(&s, glo);
		else if (*s == ')')
			return (print_parse_err(")"), free_tokens(res));
		else
			new = get_word(&s);
		if (new)
			res = add_back(new, &res);
		else
			return (free_tokens(res));
	}
	return (res);
}
