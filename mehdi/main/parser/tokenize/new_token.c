/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:30:52 by arlarzil          #+#    #+#             */
/*   Updated: 2024/05/21 13:30:53 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include <stdlib.h>

t_token	*new_token(t_token_type type, void *content)
{
	t_token	*res;

	if (!content)
		return (NULL);
	res = malloc(sizeof(t_token));
	if (res)
	{
		res->next = NULL;
		res->prev = NULL;
		res->type = type;
		if (type == PARENTHESIS)
		{
			res->content = tokenize(content);
			free(content);
			if (!res->content)
			{
				free(res);
				res = NULL;
			}
		}
		else
			res->content = content;
	}
	return (res);
}
