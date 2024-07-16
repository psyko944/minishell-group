/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:21:34 by mekherbo          #+#    #+#             */
/*   Updated: 2024/07/16 20:16:01 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_tab(char **tab)
{
	char	**temp;

	if (tab == NULL)
		return ;
	temp = tab;
	while (*tab)
	{
		free(*tab);
		++tab;
	}
	free(temp);
}
