/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:25:16 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/21 15:31:19 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_format(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens->next)
	{
		if (tokens->type == SEPARATOR && i % 2 == 0)
			return (print_parse_err(tokens->content), 0);
		else if (tokens->type == TEXT && i % 2 == 1)
			return (print_parse_err(tokens->content), 0);
		else if (tokens->type == PARENTHESIS)
		{
			if (tokens->next->type == PARENTHESIS || (tokens->next->type == TEXT
					&& !is_redirec_token(tokens->next->content)))
				return (print_parse_err(tokens->content), 0);
			if (tokens->next->type == TEXT)
				i -= 1;
		}
		tokens = tokens->next;
		i += 1;
	}
	if (tokens->type == SEPARATOR)
		return (print_parse_err("newline"), 0);
	return (1);
}
