/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:42:32 by arlarzil          #+#    #+#             */
/*   Updated: 2024/02/22 10:15:09 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*m1;
	const char	*m2;

	m1 = s1;
	m2 = s2;
	i = 0;
	while (i < n << 3)
	{
		if ((*(const long long *)s1) != *((const long long *)s2))
			break ;
		i += 8;
		m1 += 8;
		m2 += 8;
	}
	while (i + 1 < n)
	{
		if (*((const char *)s1) != *((const char *)s2))
			return (*((const unsigned char *)s1) - \
				*((const unsigned char *)s2));
		++i;
		++s1;
		++s2;
	}
	return (0);
}
