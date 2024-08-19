/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:30:52 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/07 20:52:14 by arlarzil         ###   ########.fr       */
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
			if (!res->content)
			{
				free(res);
				free(content);
				res = NULL;
			}
		}
		else
			res->content = content;
	}
	return (res);
}
