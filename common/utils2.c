/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 00:58:00 by mekherbo          #+#    #+#             */
/*   Updated: 2024/08/23 00:59:49 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	tempfree(char **tab)
{
	while (*tab)
	{
		free(*tab);
		++tab;
	}
}

void	freesbie(t_ast *ast)
{
	if (ast)
	{
		if (ast->type == N_OR || ast->type == N_AND || ast->type == N_PIPE)
		{
			freesbie(ast->l);
			freesbie(ast->r);
		}
		if (ast->type == PARENTHESIS)
			freesbie(ast->content);
		if (ast->type == COMMAND)
			free_matrix(ast->content);
		free(ast);
	}
}
