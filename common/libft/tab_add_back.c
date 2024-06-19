/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:10:08 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/19 18:26:02 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**tab_add_back(char **tab, char *elem)
{
	int		size;
	char	**res;
	int		i;

	if (tab == NULL)
		size = 0;
	else
		size = tab_size(tab);
	res = ft_calloc(size + 2, sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (tab && tab[i])
	{
		res[i] = tab[i];
		i += 1;
	}
	res[i] = elem;
	free(tab);
	return (res);
}
