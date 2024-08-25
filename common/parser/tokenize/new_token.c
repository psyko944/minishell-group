/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:30:52 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/23 00:31:10 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include <stdlib.h>
#include <libft.h>
#include <minishell.h>

void	add_fribi(t_global *glo, char *pt)
{
	int	i;

	i = 0;
	while (glo->fribi[i])
		i += 1;
	glo->fribi[i] = pt;
}

t_token	*new_token(t_token_type type, void *content, t_global *glo)
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
			res->content = tokenize(content, glo);
			if (!res->content)
			{
				free(res);
				free(content);
				res = NULL;
			}
			add_fribi(glo, (char *)content);
		}
		else
			res->content = content;
	}
	return (res);
}
