#include "tokenize.h"
#include <stdio.h>

static void	print_double_tab(const char **s)
{
	int i = 0;

	while (s[i])
	{
		printf("Word %d: %s\n", i, s[i]);
		++i;
	}
}

int	main(int ac, char **av)
{
	t_token	*tokens = tokenize(av[ac - 1]);
	t_token	*beg = tokens;

	while (tokens)
	{
		printf("Token type: %d\n", tokens->type);
		if (tokens->type == TEXT)
			print_double_tab(tokens->content);
		tokens = tokens->next;
	}
	free_tokens(beg);
}