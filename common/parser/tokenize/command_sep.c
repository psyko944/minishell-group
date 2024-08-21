/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_sep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:53:37 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/21 15:56:44 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	command_sep(const char *s)
{
	const char	*seps[] = {">>", "<<", ">", "<", 0};
	int			i;
	int			len;

	i = 0;
	while (seps[i])
	{
		len = ft_strlen(seps[i]);
		if (ft_strncmp(s, seps[i], len) == 0)
			return (len);
		++i;
	}
	return (0);
}
