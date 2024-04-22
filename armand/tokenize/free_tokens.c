#include "tokenize.h"

#include <stdlib.h>

t_token	*free_tokens(t_token *ls)
{
	t_token	*cur;

	while (ls)
	{
		cur = ls;
		ls = ls->next;
		//	
		free(cur);
	}
	return (NULL);
}
