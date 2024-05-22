/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokenize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:30:40 by arlarzil          #+#    #+#             */
/*   Updated: 2024/05/22 16:35:40 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parser/tokenize/tokenize.h"
#include <stdio.h>

void	print_ind(int ind)
{
	while (ind)
	{
		printf("\t");
		--ind;
	}
}

void	print_double_tab(const char **s, int ind)
{
	int	i;

	i = 0;
	while (s[i])
	{
		print_ind(ind);
		printf("Word %d: %s\n", i, s[i]);
		++i;
	}
}

void	print_tokens(t_token *tokens, int ind)
{
	while (tokens)
	{
		print_ind(ind);
		printf("Token type: %d\n", tokens->type);
		if (tokens->type == TEXT)
			print_double_tab(tokens->content, ind + 1);
		else if (tokens->type == SEPARATOR)
		{
			print_ind(ind + 1);
			printf("%s\n", (char *)tokens->content);
		}
		else if (tokens->type == PARENTHESIS)
			print_tokens(tokens->content, ind + 1);
		tokens = tokens->next;
	}
}
