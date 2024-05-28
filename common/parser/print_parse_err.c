/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_parse_err.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:22:22 by arlarzil          #+#    #+#             */
/*   Updated: 2024/05/28 17:28:08 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

void	print_parse_err(const char *tok)
{
	ft_putstr_fd("Parse error near token: '", 1);
	ft_putstr_fd(tok, 1);
	ft_putstr_fd("'\n", 1);
}
