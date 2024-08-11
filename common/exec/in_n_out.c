/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_n_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 20:17:19 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/11 17:37:35 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include <libft.h>

void	print_parse_err(const char *s);

static int	handle_fd(const char *op, const char *file,
	t_command *storage, t_global *mini_s)
{
	const char	*ops[] = {">>", "<<", ">", "<", 0};
	const void	*funcs[] = {open_app, open_here, open_out, open_in};
	int			(*fun)(const char *, t_command *, t_global *);
	int			i;

	i = 0;
	fun = 0;
	while (ops[i])
	{
		if (ft_strncmp(ops[i], op, ft_strlen(ops[i])) == 0)
		{
			fun = funcs[i];
			break ;
		}
		i += 1;
	}
	if (fun && !file)
		return (print_parse_err("newline"), -1);
	if (fun)
	{
		i = 0;
		while (ops[i])
			if (*file == '>' || *file == '<')
				return (print_parse_err(file), -1);
		return ((*fun)(file, storage, mini_s));
	}
	return (0);
}

static void	replace_elements(char **tab)
{
	int	i;

	i = 0;
	free(*tab);
	free(*(tab + 1));
	while (tab[i])
		i += 1;
	ft_memmove(tab, tab + 2, (i - 1) * sizeof(char *));
}

int	get_files(char **command, t_command *storage, t_global *mini_s)
{
	int	i;
	int	success;

	i = 0;
	while (command[i])
	{
		success = handle_fd(command[i], command[i + 1], storage, mini_s);
		if (success == 1)
			replace_elements(command + i);
		else if (success == -1)
			return (0);
		else
			i += 1;
	}
	return (1);
}
