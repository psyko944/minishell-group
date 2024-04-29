/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:10:00 by mekherbo          #+#    #+#             */
/*   Updated: 2023/11/17 21:22:34 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base_unsigned(unsigned long long nb, char *base)
{
	unsigned long long	base_size;

	base_size = ft_strlen(base);
	if (nb >= base_size)
		ft_putnbr_base_unsigned(nb / base_size, base);
	ft_putchar(base[nb % base_size]);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

int	ft_nblen_u(unsigned long nb, int base)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		len++;
		nb = nb / base;
	}
	return (len);
}
