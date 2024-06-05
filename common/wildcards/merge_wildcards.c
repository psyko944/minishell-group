/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_wildcards.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:29:19 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/05 18:56:33 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdlib.h>

int	tab_len(char **tab)
{
	int	res;

	res = 0;
	while (tab[res])
		++res;
	return (res);
}

char	**merge_wildcards(char **dest, int i, char **merge)
{
	int		len1;
	int		len2;
	char	**res;
	int		pos;

	if (!merge || *merge == NULL)
	{
		free(merge);
		return (dest);
	}
	len1 = tab_len(dest);
	len2 = tab_len(merge);
	res = ft_calloc(len1 + len2, sizeof(char *));
	ft_memcpy(res, dest, i * 8);
	free(dest[i]);
	if (merge)
		ft_memcpy(res + i, merge, tab_len(merge) * sizeof(char *));
	free(dest);
	free(merge);
	return (res);
}
