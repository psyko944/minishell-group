/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:30:40 by arlarzil          #+#    #+#             */
/*   Updated: 2024/05/21 13:35:29 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"
#include <stdio.h>

static void	print_double_tab(const char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		printf("Word %d: %s\n", i, s[i]);
		++i;
	}
}

int	main(int ac, char **av)
{
	t_token	*tokens;
	t_token	*beg;

	tokens = tokenize(av[ac - 1]);
	beg = tokens;
	while (tokens)
	{
		printf("Token type: %d\n", tokens->type);
		if (tokens->type == TEXT)
			print_double_tab(tokens->content);
		tokens = tokens->next;
	}
	free_tokens(beg);
}
