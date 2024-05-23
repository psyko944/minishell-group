/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:20:53 by arlarzil          #+#    #+#             */
/*   Updated: 2023/11/06 16:38:04 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_charset(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		++set;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	len;

	len = 0;
	if (!s1 || !set)
		return (0);
	while (*s1 && is_in_charset(*s1, set))
		++s1;
	while (s1[len])
		++len;
	while (is_in_charset(s1[len - 1], set))
		--len;
	if (len < 0)
		len = 0;
	return (ft_strndup_e(s1, len));
}
