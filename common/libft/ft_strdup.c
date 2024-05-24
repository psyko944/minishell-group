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

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	len;

	len = ft_strlen(s) + 1;
	res = malloc(sizeof(char) * (len));
	if (!res)
		return (NULL);
	return (ft_memcpy(res, s, len));
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*res;

	if (!n)
		return (NULL);
	res = malloc(sizeof(char) * (n + 1));
	if (!res)
		return (NULL);
	ft_strncpy(res, s, n);
	res[n] = 0;
	return (res);
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
