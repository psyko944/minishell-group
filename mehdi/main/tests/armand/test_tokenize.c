/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tokenize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:30:40 by arlarzil          #+#    #+#             */
/*   Updated: 2024/05/28 18:22:35 by mekherbo         ###   ########.fr       */
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
		printf("Token %p type: %d\n", tokens, tokens->type);
		if (tokens->type == TEXT)
			print_double_tab(tokens->content, ind + 1);
		else if (tokens->type == SEPARATOR)
		{
			print_ind(ind + 1);
			printf("in sep = %s\n", (char *)tokens->content);
		}
		else if (tokens->type == PARENTHESIS)
		{
			print_tokens(tokens->content, ind + 1);
			print_ind(ind + 1);
			printf("Content adress: %p\n", tokens->content);
		}
		tokens = tokens->next;
	}
}
