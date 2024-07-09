/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_tabs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:52:00 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/25 21:38:44 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**merge_tabs(char **a, char **b)
{
	char	**res;
	int		a_size;
	int		b_size;

	a_size = tab_size(a);
	b_size = tab_size(b);
	res = ft_calloc(a_size + b_size + 1, sizeof(char *));
	if (res)
	{
		ft_memcpy(res, a, a_size * 8);
		ft_memcpy(res + a_size, b, b_size * 8);
	}
	free(a);
	free(b);
	return (res);
}
