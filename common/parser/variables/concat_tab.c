/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <armand.larzilliere@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:33:51 by arlarzil          #+#    #+#             */
/*   Updated: 2024/05/24 14:50:38 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../libft/libft.h"

char	**free_tab(char **tab);

size_t	get_tab_content_len(char **tab)
{
	size_t	len;

	len = 0;
	while (*tab)
	{
		len += ft_strlen(*tab);
		++tab;
	}
	return (len);
}

char	*copy_tab(char **tab, char *dest)
{
	size_t	len;
	char	*res;

	res = dest;
	while (*tab)
	{
		len = ft_strlen(*tab);
		__builtin_printf("%s\n", *tab);
		ft_strcpy(dest, *tab);
		dest += len;
		++tab;
	}
	return (res);
}

char	*concat_tab(char **tab)
{
	size_t	size;
	char	*res;

	size = get_tab_content_len(tab);
	res = malloc(sizeof(char) * (size + 1));
	*res = 0;
	if (res)
		copy_tab(tab, res);
	return (free_tab(tab), res);
}
/*
int	main()
{
	char	*tab[] = {"Fleur", NULL};
	char	**tabcpy = malloc(sizeof(char *) * 10);
	int		i = 0;

	while (tab[i])
	{
		tabcpy[i] = __builtin_strdup(tab[i]);
		++i;
	}
	tabcpy[i] = NULL;
	__builtin_printf("%s\n", concat_tab(tabcpy));
}
*/