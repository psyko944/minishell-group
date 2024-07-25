/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_wildcards.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 18:50:07 by arlarzil          #+#    #+#             */
/*   Updated: 2024/07/25 20:36:40 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	**merge_wildcards(char **dest, int i, char **merge);
char	**get_matches(const char *exp, const char *path);

char	**run_wildcards(char **a, char *path)
{
	char	**res;
	int		i;

	i = 0;
	res = a;
	while (res[i])
	{
		if (ft_strchr(res[i], '*'))
			res = merge_wildcards(res, i, get_matches(res[i], path));
		++i;
	}
	return (res);
}
