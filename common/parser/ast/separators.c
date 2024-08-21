/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:26:14 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/21 15:31:23 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	has_seps(t_token *tokens)
{
	while (tokens)
	{
		if (tokens->type == SEPARATOR)
			return (true);
		tokens = tokens->next;
	}
	return (false);
}

t_token_type	get_sep_type(char *sep)
{
	const char			*seps[] = {"||", "&&", "|", NULL };
	const t_token_type	types[] = {N_OR, N_AND, N_PIPE};
	int					i;

	i = 0;
	while (seps[i])
	{
		if (ft_strncmp(seps[i], sep, ft_strlen(seps[i])) == 0)
		{
			free(sep);
			return (types[i]);
		}
		++i;
	}
	return (SEPARATOR);
}
