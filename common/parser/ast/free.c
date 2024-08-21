/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:27:00 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/21 15:27:08 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_ast	*free_ast(t_ast *ast)
{
	if (!ast)
		return (NULL);
	if (ast->type == PARENTHESIS)
		free_ast(ast->content);
	else if (ast->type == COMMAND)
		free_tab(ast->content);
	else if (ast->type & (N_AND | N_OR | N_PIPE))
	{
		free_ast(ast->l);
		free_ast(ast->r);
	}
	free(ast);
	return (NULL);
}
