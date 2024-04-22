/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:15:34 by arlarzil          #+#    #+#             */
/*   Updated: 2024/04/16 18:15:35 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"
#include <stdlib.h>

t_lexed_list	*free_lexer(t_lexed_list *ls)
{
	if (!ls)
		return (NULL);
	free_lexer(ls->next);
	if (ls->content)
		free(ls->content);
	else
		free_lexer(ls->soft_content);
	free_parsed_cmd(ls->parsed_content);
	free(ls);
	return (NULL);
}
