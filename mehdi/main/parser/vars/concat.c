/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:19:39 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/14 23:06:34 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <stdio.h>

static int	get_full_len(char **tab)
{
	int	res;

	res = 0;
	while (*tab)
	{
		res += ft_strlen(*tab);
		++tab;
	}
	return (res + 1);
}

char	*concat_tab(char **tab)
{
	char	*res;
	char	*respt;
	int		i;

	res = malloc(get_full_len(tab));
	if (!res)
		return (perror("malloc"), NULL);
	i = 0;
	*res = 0;
	respt = res;
	while (tab[i])
	{
		ft_strcpy(respt, tab[i]);
		while (*respt)
			++respt;
		i += 1;
	}
	return (res);
}
/*
int	main()
{
	char	*tab[] = { "coucou ", "les ", "gens!", NULL};
	char	*str = concat_tab(tab);

	printf("%s\n", str);
	free(str);
}*/
