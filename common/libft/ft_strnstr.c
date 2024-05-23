/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:55:41 by arlarzil          #+#    #+#             */
/*   Updated: 2023/11/07 16:50:34 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_l;

	i = 0;
	if (len == 0 && !big)
		return (NULL);
	if (!*little)
		return ((char *)big);
	len_l = ft_strlen(little);
	while (big[i] && i + len_l - 1 < len)
	{
		if (ft_strncmp(little, &big[i], len_l) == 0)
			return ((char *)&big[i]);
		++i;
	}
	return (NULL);
}
