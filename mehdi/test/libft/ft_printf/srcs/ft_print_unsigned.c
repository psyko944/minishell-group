/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:08:16 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/16 00:01:46 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_print_unsigned(va_list arg)
{
	unsigned int	u_nb;

	u_nb = va_arg(arg, unsigned int);
	ft_putnbr_base_unsigned((unsigned long long)u_nb, "0123456789");
	return (ft_nblen_u((unsigned long)u_nb, 10));
}
