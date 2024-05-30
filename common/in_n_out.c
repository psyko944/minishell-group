/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_n_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <armand.larzilliere@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:17:19 by arlarzil          #+#    #+#             */
/*   Updated: 2024/05/30 03:09:09 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_fd(const char *op, const char *file, t_command *storage)
{
	const char	*ops[] = {">>", "<<", ">", "<", 0}; 
	const int	(*funcs[])(const char *, t_command *)
	= {open_app, open_here, open_out, open_in};
	int			(*fun)(const char *, t_command *);
	int			i;

	i = 0;
	fun = 0;
	while (ops[i])
	{
		if (strncmp(ops[i], op) == 0)
		{
			fun = funcs[i];
		}
	}
	if (fun && !file)
		return (print_parse_err("newline"), -1);
	if (fun)
		return ((*fun)(file, storage));
	return (0);
}

static void	replace_elements(char **tab)
{
	int	i;

	i = 0;
	free(*tab);
	free(*(tab + 1));
	while (*tab[i + 2])
	{
		tab[i] = tab[i + 2];
		++i;
	}
	tab[i] = 0;
}

int	get_files(char **command, t_command *storage)
{
	int	i;
	int	success;

	i = 0;
	while (command[i])
	{
		success = handle_fd(command[i], command[i + 1], storage);
		if (success == 1)
			replace_elements(command + i);
		else if (success == -1)
			return (0);
		else
			i += 1;
	}
	return (1);
}