/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:36:02 by arlarzil          #+#    #+#             */
/*   Updated: 2024/05/21 13:36:14 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, char c)
{
	return (strchr(s, c));
}

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	return (strncmp(s1, s2, len));
}
