/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:13:06 by arlarzil          #+#    #+#             */
/*   Updated: 2023/11/08 20:31:25 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	get_alloc_len(int n)
{
	int	res;

	res = 0;
	if (n < 0)
		res += 1;
	while (n / 10)
	{
		res += 1;
		n /= 10;
	}
	return (res + 1);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		pos;

	pos = get_alloc_len(n);
	res = malloc(sizeof(char) * (pos + 1));
	if (!res)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	else if (n == 0)
		res[0] = '0';
	res[pos] = 0;
	while (n)
	{
		res[pos - 1] = ft_abs(n % 10) + '0';
		n /= 10;
		--pos;
	}
	return (res);
}
