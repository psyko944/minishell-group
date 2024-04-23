#include "tokenize.h"

#include <stdlib.h>

t_token	*free_tokens(t_token *ls)
{
	t_token	*cur;

	while (ls)
	{
		cur = ls;
		ls = ls->next;
		if (cur->type == TEXT)
			free(*((char **)cur->content));
		if (cur->type == PARENTHESIS)
			free_tokens(cur->content);
		else
			free(cur->content);
		free(cur);
	}
	return (NULL);
}
