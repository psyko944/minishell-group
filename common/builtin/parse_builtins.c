/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:55:09 by mekherbo          #+#    #+#             */
/*   Updated: 2024/06/28 18:50:59 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	parse_builtins(t_global *mini_s, t_command *cmd)
{
	if (!ft_strncmp(cmd->tab[0], "cd", 2))
		return (ft_cd(mini_s, cmd->tab), true);
	else if (!ft_strncmp(cmd->tab[0], "export", 6))
		return (ft_export(mini_s, cmd->tab), true);
	else if (!ft_strncmp(cmd->tab[0], "unset", 5))
		return (ft_unset(mini_s, cmd->tab), true);
	else if (!ft_strncmp(cmd->tab[0], "echo", 4))
		return (mini_echo(mini_s, cmd->tab), true);
	else if (!ft_strncmp(cmd->tab[0], "env", 3))
		return (print_env(mini_s->env), true);
	else if (!ft_strncmp(cmd->tab[0], "exit", 4))
		return (ft_exit(mini_s, cmd->tab), true);
	else if (!ft_strncmp(cmd->tab[0], "pwd", 3))
		return (print_pwd(mini_s, cmd->tab), true);
	return (false);
}
