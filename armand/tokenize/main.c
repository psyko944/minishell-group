#include "tokenize.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_token	*tokens = tokenize(av[ac - 1]);
	
	while (tokens)
	{
		printf("Word: %s\n", tokens->content);
		tokens = tokens->next;
	}
}