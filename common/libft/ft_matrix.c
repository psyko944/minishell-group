/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:39:15 by mekherbo          #+#    #+#             */
/*   Updated: 2024/08/25 06:05:50 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	print_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		printf("%s\n", matrix[i]);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free(matrix[i]);
	free(matrix);
}

char	**ft_cpy_matrix(char **matrix)
{
	char	**cpy;
	size_t	i;

	i = 0;
	while (matrix[i])
		i++;
	cpy = malloc(sizeof(char *) * (i + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (matrix[i])
	{
		cpy[i] = ft_strdup(matrix[i]);
		if (!cpy[i])
			return (free_matrix(cpy), NULL);
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}
