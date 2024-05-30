#include "libft.h"
#include <stdlib.h>

// WARNING: Quick implementation only for larger reallocs of strings
char	*ft_realloc(char *src, size_t size)
{
	char	*res;

	res = ft_calloc(size, 1);
	if (res)
		ft_strcpy(res, src);
	free(src);
	return (res);
}
