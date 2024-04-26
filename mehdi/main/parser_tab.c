#include <stdlib.h>

#include "parser.h"

t_cmd_symbol	*free_parse(t_cmd_symbol *tab)
{
	t_cmd_symbol	*tmp;

	while (tab)
	{
		tmp = tab->next;
		free(tab->content);
		free(tab);
		tab = tmp;
	}
	return (NULL);
}

void	add_back(t_cmd_symbol *new, t_cmd_symbol **dest)
{
	t_cmd_symbol	*e;

	if (*dest)
	{
		e = (*dest)->last;
		e->next = new;
	}
	else
		*dest = new;
	(*dest)->last = new;
}

unsigned int	get_len(t_cmd_symbol *list)
{
	unsigned int	res;

	res = 0;
	while (list)
	{
		++res;
		list = list->next;
	}
	return (res);
}