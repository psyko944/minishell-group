/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 01:47:12 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/16 00:03:50 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_hexa(va_list arg, char flag)
{
	unsigned long	nb;

	nb = va_arg(arg, unsigned int);
	if (flag == 'x')
		ft_putnbr_base_unsigned((unsigned long long)nb, "0123456789abcdef");
	else if (flag == 'X')
		ft_putnbr_base_unsigned((unsigned long long)nb, "0123456789ABCDEF");
	return (ft_nblen_u((unsigned long)nb, 16));
}
