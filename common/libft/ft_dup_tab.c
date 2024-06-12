/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:45:35 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/12 16:47:36 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	**ft_dup_tab(char **tab)
{
	int		i;
	char	**res;

	i = 0;
	while (tab[i])
		++i;
	res = ft_calloc(i + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	while (tab[i])
	{
		res[i] = ft_strdup(tab[i]);
		i += 1;
	}
	return (res);
}