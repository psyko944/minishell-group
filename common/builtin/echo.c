/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 01:37:32 by mekherbo          #+#    #+#             */
/*   Updated: 2024/07/12 23:54:50 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h> 

static bool	check_option(char *cmd)
{
	int	i;

	if (*cmd != '-')
		return (false);
	i = 1;
	while (cmd[i] == 'n')
		i++;
	if (!cmd[i])
		return (true);
	return (false);
}

void	mini_echo(t_global *mini_s, char **tab)
{
	int		i;
	bool	n_line;

	(void)mini_s;
	n_line = true;
	i = 1;
	while (tab[i] && check_option(tab[i]))
	{
		n_line = false;
		i++;
	}
	while (tab[i])
	{
		printf("%s", tab[i++]);
		if (tab[i])
			printf(" ");
	}
	if (n_line)
		printf("\n");
}
