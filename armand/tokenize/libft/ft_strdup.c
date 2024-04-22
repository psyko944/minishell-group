/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:42:06 by arlarzil          #+#    #+#             */
/*   Updated: 2023/11/07 20:32:50 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include <string.h>

char	*ft_strdup(const char *s)
{
	return (strdup(s));
}

const char	*ft_strncpy(char *dest, const char *src, size_t size)
{
	return (strncpy(dest, src, size));
}

char	*ft_strndup_e(const char *s, size_t n)
{
	char	*res;

	if (!s)
		return (NULL);
	if (n <= 0)
		n = 0;
	res = malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	ft_strncpy(res, s, n);
	res[n] = 0;
	return (res);
}
