/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:31:02 by arlarzil          #+#    #+#             */
/*   Updated: 2024/05/22 15:59:34 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int	skip_quote(const char *s)
{
	char		c;
	const char	*s2;

	c = *s;
	s += 1;
	s2 = ft_strchr(s, c);
	if (!s2)
		return (-1);
	return (s2 - s + 2);
}