/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:22:57 by arlarzil          #+#    #+#             */
/*   Updated: 2023/11/08 16:22:58 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putptr_fd(const void *p, int fd)
{
	ft_puthex_fd((long)p, fd);
}

void	ft_putptr(const void *p)
{
	ft_putptr_fd(p, 1);
}
