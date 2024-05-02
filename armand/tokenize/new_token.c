#include "tokenize.h"
#include <stdlib.h>

t_token	*new_token(t_token_type type, void *content)
{
	t_token	*res;

	if (!content)
		return (NULL);
	res = malloc(sizeof(t_token));
	if (res)
	{
		res->next = NULL;
		res->prev = NULL;
		res->type = type;
		if (type == PARENTHESIS)
		{
			res->content = tokenize(content);
			free(content);
			if (!res->content)
			{
				free(res);
				res = NULL;
			}
		}
		else
			res->content = content;
	}
	return (res);
}
