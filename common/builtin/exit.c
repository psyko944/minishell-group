/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 03:43:41 by mekherbo          #+#    #+#             */
/*   Updated: 2024/06/25 19:17:37 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <limits.h>

static bool	is_numeric(char *str, long long *code)
{
	long long	res;
	int			sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign = -1;
	if (!(*str))
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		res = res * 10 + *str++ - '0';
	}
	*code = res * sign;
	if (*code > LLONG_MAX || *code < LLONG_MIN)
		return (false);
	return (true);
}

void	ft_exit(t_global *mini_s, char **cmd)
{
	long long	exit_status;

	(void)mini_s;
	exit_status = 0;
	printf("exit\n");
	if (cmd[1])
	{
		exit_status = 0;
		if (!is_numeric(cmd[1], &exit_status))
		{
			ft_putstr_fd("bash: exit: ", 2);
			ft_putstr_fd(cmd[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
		}
		else if (cmd[2] && is_numeric(cmd[1], &exit_status))
			(ft_putstr_fd("exit: too many arguments\n", 2));
		else
			exit(exit_status % 256);
	}
	else
		exit(ft_atoi(mini_s->env->content));
}
