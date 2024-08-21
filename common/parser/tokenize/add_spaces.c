/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_spaces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:46:52 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/21 15:56:35 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <tokenize.h>

void	add_spaces(char *s)
{
	int	step;

	while (*s)
	{
		step = command_sep(s);
		if (step)
		{
			ft_memmove(s + 1, s, ft_strlen(s));
			*s = ' ';
			s += step + 1;
			ft_memmove(s + 1, s, ft_strlen(s));
			*s = ' ';
			s += 1;
		}
		else
			++s;
	}
}
