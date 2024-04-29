/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:29:17 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/17 21:20:38 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

int	ft_print_string(va_list arg)
{
	char	*str;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (sizeof(char) * 6);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}
