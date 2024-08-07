/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parse_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:22:22 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/07 20:49:09 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

extern int	g_exit_status;

void	print_parse_err(const char *tok)
{
	ft_putstr_fd("Parse error near token: '", 2);
	ft_putstr_fd(tok, 2);
	ft_putstr_fd("'\n", 2);
	g_exit_status = 2;
}
