/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <armand.larzilliere@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:38:37 by arlarzil          #+#    #+#             */
/*   Updated: 2024/05/24 14:38:46 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**free_tab(char **tab)
{
	char	**tabptr;

	tabptr = tab;
	while (*tabptr)
		free(*(tabptr++));
	free(tab);
	return (NULL);
}