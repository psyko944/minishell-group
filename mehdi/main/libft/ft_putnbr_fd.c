/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:32:29 by arlarzil          #+#    #+#             */
/*   Updated: 2023/11/07 17:10:01 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	digit_by_digit(int n, int fd)
{
	if (n / 10)
		digit_by_digit(n / 10, fd);
	ft_putchar_fd(-(n % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	else
		n = -n;
	digit_by_digit(n, fd);
}

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
}
