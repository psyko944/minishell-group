/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:56:59 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/12 20:46:10 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		replace_pwd(t_global *mini_s, char *pwd)
{
	t_global	*tmp;
	int			n;

	n = 0;
	tmp = mini_s->env;
	while (tmp)
	{	
		if (!ft_strncmp("PWD"), tmp->key, 3)
		{
			tmp->value = PWD + 3;
			n = 1;
		}
		tmp =  tmp->next;
	}
	 if (!n)
	 	addback_env(&tmp, first_node(pwd));
}	


static	void	pwd_env(t_global *mini_s)
{
	char	*pwd;

	pwd = get_pwd();
	if (!pwd)
		perror("PWD error");
	else
		pwd = ft_strjoin("PWD=", pwd);
		if (!pwd || !replace_pwd(mini_s, pwd))
	free(pwd);
}

void	init(void)
{
	int	i;

	(void)i;
}
