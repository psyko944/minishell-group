/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:50:12 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/12 18:50:30 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// WARNING: Quick implementation only for larger reallocs of strings
char	*ft_realloc(char *src, size_t size)
{
	char	*res;

	res = ft_calloc(size, 1);
	if (res)
		ft_strcpy(res, src);
	free(src);
	return (res);
}
