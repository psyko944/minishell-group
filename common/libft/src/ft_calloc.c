/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:38:46 by arlarzil          #+#    #+#             */
/*   Updated: 2023/11/08 23:20:44 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <limits.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ret;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size > INT_MAX / nmemb)
		return (NULL);
	ret = malloc(size * nmemb);
	if (ret)
		ft_bzero(ret, nmemb * size);
	return (ret);
}
