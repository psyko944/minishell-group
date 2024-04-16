/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:15:44 by arlarzil          #+#    #+#             */
/*   Updated: 2024/04/16 18:15:44 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "lexer.h"
#include "../quote.h"
#include <stdlib.h>

#include <string.h>

static t_lexed_list	*smart_recut(t_lexed_list *l)
{
	t_lexed_list	*res;
	t_lexed_list	*node;

	res = NULL;
	while (l)
	{
		__builtin_printf("%s\n", l->content);
		if (l->content)
			node = cut_expression(l);
		else
			node = lex_new_node(NULL, l->soft_content);
		if (node)
			lex_add_back(&res, node);
		else
			return (free_lexer(l), free_lexer(res));
		l = l->next;
	}
	free_lexer(l);
	return (res);
}

t_lexed_list	*mini_lexer(const char *s)
{
	t_lexed_list	*ret;

	if (!s)
		return (NULL);
	if (strstr(s, "(("))
	{
		ft_putstr_fd("Error: Arythmetic operations not supported\n", 2);
		return (NULL);
	}
	ret = split_parenthesis(s);
	smart_recut(ret);
	return (ret);
}
