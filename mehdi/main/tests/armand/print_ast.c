/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:59:53 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/14 18:36:03 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ast.h>

void	print_double_tab(const char **s, int ind);
void	print_ind(int ind);

void	print_ast(t_ast *ast, int ind)
{
	if (!ast)
		return ;
	if (ast->type == PARENTHESIS)
	{
		print_ind(ind);
		printf("Parenthesis: %p\n", ast);
		print_ast(ast->content, ind + 1);
	}
	else if (ast->type == TEXT)
	{
		print_ind(ind);
		printf("Token: %p\n", ast);
		print_double_tab(ast->content, ind + 1);
	}
	else
	{
		print_ind(ind);
		printf("Separator: %p %s\n", ast,
			(ast->type == 3 ? "PIPE" : ast->type == 4 ? "AND" : "OR"));
		print_ind(ind + 1);
		printf("l: %p r: %p\n", ast->l, ast->r);
		print_ast(ast->l, ind);
		print_ast(ast->r, ind);
	}
}
