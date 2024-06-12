/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:36:10 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/17 21:21:33 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	nb_len_ptr(uintptr_t nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	else
	{
		while (nb)
		{
			nb /= 16;
			count++;
		}
	}
	return (count);
}

int	ft_print_ptr(va_list arg)
{
	uintptr_t	ptr;

	ptr = va_arg(arg, uintptr_t);
	if (ptr == 0)
		return ((int)write(1, "(nil)", 5));
	ft_putstr("0x");
	ft_putnbr_base_unsigned((unsigned long long)ptr, "0123456789abcdef");
	return (nb_len_ptr(ptr) + 2);
}
