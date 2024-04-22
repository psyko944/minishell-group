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

// Err return
static int	smart_recut(t_lexed_list *l)
{
	while (l)
	{
		if (l->content)
			l->parsed_content = tokenize(l->content);
		if (l->content && !l->parsed_content)
			return (1); // Clean la mémoire
		free(l->content);
		l->content = NULL;
		l = l->next;
	}
	return (0);
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
