#include "libft.h"


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