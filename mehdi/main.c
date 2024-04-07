#include "parser.h"

static void	print_cmd(t_parsed_cmd *cmd)
{
	t_parsed_cmd 	*tmp;
	unsigned int	tmpi = 1;
	tmp = cmd;
	while (tmp)
	{
		if (tmp->command[0]);
			printf("cmd = %s\n", tmp->command[0]);
		while (tmp->command[tmpi])
			printf("cmd = %s\n", tmp->command[tmpi]);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	t_parsed_cmd_cont	*parsed = parse_command(av[ac - 1], 0);
	t_parsed_cmd		*cur = parsed->cont;

	//print_cmd(cur);
	while (cur)
	{
		if (cur->command[0])
		{
			__builtin_printf("Created command %s with parameters:\n", cur->command[0]);
			unsigned int	tmpi = 1;
			while (cur->command[tmpi])
				__builtin_printf("\t%s\n", cur->command[tmpi++]);
			__builtin_printf("Link types are: %d %d\n", cur->link_prev, cur->link_next);
		}
		cur = cur->next;
	}
	free_parsed_cmd(parsed);
}
