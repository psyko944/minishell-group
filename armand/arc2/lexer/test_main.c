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

static void	print_ls_parse_content(t_parsed_cmd_cont *content)
{
	t_parsed_cmd	*cmd;
	unsigned int	i;

	cmd = content->cont;
	i = 1;
	while (cmd)
	{
		printf("%s:\n", cmd->command[0]);
		i = 1;
		while (cmd->command[i])
		{
			printf("\t%s\n", cmd->command[i]);
			i += 1;
		}
		cmd = cmd->next;
	}
}

static void	print_lexed_list(t_lexed_list *ls, int nested_count)
{
	__builtin_printf("Ret: %p\n", ls);

	while (ls)
	{
		if (ls->parsed_content)
		{
			printf("%d\n", nested_count);
			print_ls_parse_content(ls->parsed_content);
		}
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
