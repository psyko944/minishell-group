/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:16:23 by arlarzil          #+#    #+#             */
/*   Updated: 2024/04/16 18:16:24 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#include <string.h>

int	is_quote(char c)
{
	if (c == '\'' || c == '"')
		return (c);
	return (0);
}

int	quote_len(const char *c)
{
	const char	*c2;

	c2 = strchr(c + 1, *c);
	if (!c2)
		return (-1);
	return (c2 - c + 1);
}
/*
int	main(int ac, char **av) // Quote related tests
{
	printf("%d\n", quote_len(av[ac - 1]));
}
*/
