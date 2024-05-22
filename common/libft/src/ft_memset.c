/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:17:44 by arlarzil          #+#    #+#             */
/*   Updated: 2024/02/19 14:54:40 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		i;
	size_t		block_count;
	long long	filler;

	i = 0;
	while (i < 8)
		((char *)&filler)[i++] = (char)c;
	block_count = n / sizeof(long long);
	i = 0;
	while (i < block_count)
		((long long *)s)[i++] = (long long)filler;
	i = block_count * sizeof(long long);
	while (i < n)
		((char *)s)[i++] = (char)c;
	return (s);
}
