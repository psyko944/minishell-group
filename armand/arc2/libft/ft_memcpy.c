/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:52:42 by arlarzil          #+#    #+#             */
/*   Updated: 2024/02/19 14:59:48 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aio.h>
#include <stdint.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *(res) = dest;
	if (!dest && !src)
		return (0);
	while (n >= 8)
	{
		*((long long *)res) = *((long long *)src);
		res += 8;
		src += 8;
		n -= 8;
	}
	if (n & 4)
	{
		*((int *)res) = *((int *)src);
		src += 4;
		res += 4;
	}
	if (n & 2)
	{
		*((short *)res) = *((short *)src);
		res += 2;
		src += 2;
	}
	if (n & 1)
		*((char *)res) = *((char *)src);
	return (dest);
}

void	*ft_memrcpy(void *dest, const void *src, size_t n)
{
	void		*res;

	if (!dest && !src)
		return (0);
	res = dest + n;
	while (n >= 8)
	{
		res -= 8;
		src -= 8;
		n -= 8;
		(*(long long *)res) = (*(long long *)src);
	}
	while (n)
	{
		*((uint8_t *)--res) = *((uint8_t *)--src);
		--n;
	}
	return (dest);
}
