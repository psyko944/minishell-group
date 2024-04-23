#include "tokenize.h"
#include "libft/libft.h"

#include <stdlib.h>

static t_token	*add_back(t_token *node, t_token **ls)
{
	t_token	*cur;

	if (!*ls)
		*ls = node;
	else
	{
		cur = *ls;
		while (cur->next)
			cur = cur->next;
		cur->next = node;
	}
	return (*ls);
}

t_token	*tokenize(const char *s)
{
	t_token	*res;
	t_token	*new;

	res = NULL;
	while (*s)
	{
		__builtin_printf("Tokenizing: %s\n", s);
		while (ft_isspace(*s))
			++s;
		if (!*s)
			break ;
		if (*s == '(')
			new = get_parenthesis(&s);
		else
			new = get_word(&s);
		if (new)
			res = add_back(new, &res);
		else
			return (free_tokens(res));
	}
	return (res);
}
