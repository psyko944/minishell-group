/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:20:25 by arlarzil          #+#    #+#             */
/*   Updated: 2024/04/16 18:20:26 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "lexer.h"
#include <stdlib.h>

t_lexed_list	*lex_add_back(t_lexed_list **ls, t_lexed_list *node)
{
	t_lexed_list	*tmp;

	if (!node)
		return (free_lexer(*ls));
	if (node->content == NULL && node->soft_content == NULL)
		return (free(node), free_lexer(*ls));
	tmp = *ls;
	if (!tmp)
	{
		*ls = node;
		return (node);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->prev = tmp;
	return (*ls);
}

//ajoute un node seul a l'emplacement dest, dest et node doivent exister
void	lex_insert(t_lexed_list *dest, t_lexed_list *node)
{
	node->next = dest->next;
	dest->next = node;
	if (node->next)
		node->next->prev = node;
	node->prev = dest;
}

//ajoute une sublist a l'emplacement dest, dest et src doivent exister
void	lex_insert_bulk(t_lexed_list *dest, t_lexed_list *src)
{
	t_lexed_list	*last;

	last = src;
	while (last->next)
		last = last->next;
	last->next = dest->next;
	if (last->next)
		last->next = last;
	dest->next = src;
}

/* // Pas fini, ni utile si on fait les choses bien
void	clean_empty_nodes(t_lexed_list **l)
{
	t_lexed_list	*target;
	t_lexed_list	*cur;

	cur = *l;
	while (cur)
	{
		if (!cur->content && !cur->soft_content)
		{
			target = cur;
			if (target->prev)
			{
				target->prev->next = target->next;
			}
			else
			{
				*l = target->next;
			}
		}
		cur = cur->next;
	}
}
*/
t_lexed_list	*lex_new_node(char *content, t_lexed_list *soft_content)
{
	t_lexed_list	*res;

	if (!content && !soft_content)
		return (NULL);
	res = malloc(sizeof(t_lexed_list));
	if (!res)
		return (NULL);
	ft_bzero(res, sizeof(t_lexed_list));
	res->content = content;
	res->soft_content = soft_content;
	return (res);
}
