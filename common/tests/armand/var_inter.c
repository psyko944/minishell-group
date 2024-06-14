/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_inter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 18:46:39 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/14 18:07:16 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vars.h>
#include <libft.h>
#include <minishell.h>
#include <stdio.h>
#include <stdlib.h>

void	test_var_inter(char *src, t_env_var *env, char *expected)
{
	char	*src_inter;
	char	*res;

	src_inter = ft_strdup(src);
	res = replace_vars(src, env);
	if (ft_strcmp(res, expected) != 0)
		printf("KO: expected %s but got %s\n", expected, res);
	else
		printf("OK: %s=>%s\n", src, res);
	free(src_inter);
	free(res);
}
