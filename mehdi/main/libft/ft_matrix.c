#include "libft.h"

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
		cpy[i] = matrix[i];
		if (!cpy[i])
			return (free_matrix(cpy), NULL);
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}