/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 14:43:08 by mekherbo          #+#    #+#             */
/*   Updated: 2024/06/14 15:06:49 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void		replace_pwd(t_global *mini_s, char *pwd)
{
	t_env_var	*tmp;
	int			n;

	n = 0;
	tmp = mini_s->env;
	while (tmp)
	{	
		if (!ft_strncmp("PWD", tmp->key, 3))
		{
            free(tmp->content);
			tmp->content = get_value(pwd);
			n = 1;
		}
		tmp = tmp->next;
	}
	 if (!n)
	 	addback_env(&tmp, first_node(pwd));
}	


void	pwd_env(t_global *mini_s)
{
	char	*pwd;
    char    *tmp;

	pwd = get_pwd();
    tmp = NULL;
	if (!pwd)
		perror("PWD error");
	else
    {
		tmp = ft_strjoin("PWD=", pwd);
        free(pwd);
    }
	if (!tmp)
			perror("PWD error");
	replace_pwd(mini_s, tmp);
	free(tmp);
}