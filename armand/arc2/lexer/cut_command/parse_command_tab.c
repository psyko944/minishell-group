#include "tokenize.h"

#include <stdlib.h>

void	add_block(t_parsed_cmd *new, t_parsed_cmd **list)
{
	t_parsed_cmd	*tmp;

	if (!new)
		__builtin_printf("Y'a une erreur chef faut tout free\n");
	if (!*list)
		*list = new;
	else
	{
		tmp = *list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_parsed_cmd	*free_parsed_cmd(t_parsed_cmd_cont *cmd)
{
	t_parsed_cmd	*tmp;
	t_parsed_cmd	*cur;
	unsigned int	i;

	if (!cmd)
		return (NULL);
	cur = cmd->cont;
	while (cur)
	{
		tmp = cur->next;
		i = 0;
		while (cur->command[i])
		{
			free(cur->command[i]);
			++i;
		}
		free(cur);
		cur = tmp;
	}
	free(cmd->double_tab);
	free(cmd);
}
