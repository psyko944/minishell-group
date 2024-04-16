/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:22:19 by arlarzil          #+#    #+#             */
/*   Updated: 2024/04/16 18:22:22 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "lexer.h"

static void	print_lexed_list(t_lexed_list *ls, int nested_count)
{
	while (ls)
	{
		if (ls->content)
			printf("%d: %s\n", nested_count, ls->content);
		else
			print_lexed_list(ls->soft_content, nested_count + 1);
		ls = ls->next;
	}
}

int	main(int ac, char **av)
{
	t_lexed_list	*ls;

	ls = mini_lexer(av[ac - 1]);
	print_lexed_list(ls, 0);
	free_lexer(ls);
}
