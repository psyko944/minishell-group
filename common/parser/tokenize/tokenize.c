/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:31:15 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/07 20:52:19 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokenize.h>
#include <libft.h>

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

t_token	*tokenize(const char *s)
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
			new = get_parenthesis(&s);
		else
			new = get_word(&s);
		if (new)
			res = add_back(new, &res);
		else
			return (free_tokens(res));
	}
	return (res);
}
