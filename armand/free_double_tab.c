#include <stdlib.h>

void	*free_double_tab(void **tab)
{
	void	**tmp;

	while (*tmp)
	{
		free(*tmp);
		++tmp;
	}
	free(tab);
	return (0);
}
