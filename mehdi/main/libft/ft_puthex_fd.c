/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:22:48 by arlarzil          #+#    #+#             */
/*   Updated: 2023/11/08 16:22:50 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_fd(long n, int fd)
{
	if (n / 10)
		ft_puthex_fd(n / 10, fd);
	ft_putchar_fd("0123456789ABCDEF"[n % 16], fd);
}

void	ft_puthex(long n)
{
	ft_puthex_fd(n, 1);
}
