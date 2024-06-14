/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:46:29 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/14 12:13:17 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stddef.h>
#include <stdint.h>

#define MAGIC1	0x0101010101010101
#define MAGIC2	0x8080808080808080
/*
static inline uint8_t	align_ptr(const char *p)
{
	const char	*e;

	e = (const char *)(((long long)(p + 7)) & ~7);
	return (e - p);
}

size_t	ft_strlen(const char *s)
{
	const char	*e;
	uint8_t		align;
	int			i;

	i = 0;
	align = align_ptr(s);
	e = s;
	while (*e && i++ < align)
		++e;
	if (!*e)
		return (e - s);
	while (!((*((uint64_t *)e) - MAGIC1) & ~*((uint64_t *)e) & MAGIC2))
		e += 8;
	if (!((*((uint32_t *)e) - 0x01010101) & ~*((uint32_t *)e) & 0x80808080))
		e += 4;
	if (!((*((uint16_t *)e) - 0x0101) & ~*((uint16_t *)e) & 0x8080))
		e += 2;
	if (*e)
		++e;
	return (e - s);
}
*/

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i += 1;
	return (i);
}
