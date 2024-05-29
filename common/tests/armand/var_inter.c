#include "../../parser/variables/variables.h"
#include "../../libft/libft.h"
#include <stdio.h>

void	test_var_inter(char *src, char **env, char *expected)
{
	char	*src_inter;

	src_inter = ft_strdup(src);
	interpret_variables(src);
	if (ft_strcmp(src, expected) != 0)
		printf("KO: expected %s but got %s\n", expected, src_inter);
	else
		printf("OK: %s=>\n", src, src_inter);
	free(src_inter);
}
