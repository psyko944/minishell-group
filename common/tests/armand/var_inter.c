/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:46:39 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/12 19:29:15 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parser/vars/vars.h"
#include "../../libft/libft.h"
#include "../../minishell.h"
#include <stdio.h>

void	test_var_inter(char *src, t_env_var **env, char *expected)
{
	char	*src_inter;

	src_inter = ft_strdup(src);
	replace_vars(src, env);
	if (ft_strcmp(src, expected) != 0)
		printf("KO: expected %s but got %s\n", expected, src_inter);
	else
		printf("OK: %s=>\n", src, src_inter);
	free(src_inter);
}
