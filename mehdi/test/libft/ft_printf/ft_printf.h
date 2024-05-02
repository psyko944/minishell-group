/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:18:56 by mekherbo          #+#    #+#             */
/*   Updated: 2024/03/19 22:59:22 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include "../libft.h"

int		ft_print_char(va_list arg);
int		ft_print_int(va_list arg);
int		ft_print_string(va_list arg);
int		ft_print_ptr(va_list arg);
int		ft_print_unsigned(va_list arg);
int		ft_print_hexa(va_list arg, char flag);
int		ft_printf(const char *format, ...);
void	ft_putnbr(int nb);
void	ft_putnbr_base_unsigned(unsigned long long nb, char *base);
int		ft_nblen_u(unsigned long nb, int base);
int		ft_printf(const char *format, ...);
void	ft_putstr(char *str);

#endif
