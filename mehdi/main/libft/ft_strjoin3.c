/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:51:21 by mekherbo          #+#    #+#             */
/*   Updated: 2024/06/04 18:46:00 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	char	*join;
	if (!s1 || !s2 || !s3)
		return (NULL);
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1));
	if (join == NULL)
		return (NULL);
    ft_strlcpy(join, s1, ft_strlen(s1) + 1);
    ft_strlcpy(join + ft_strlen(s1) , s2, ft_strlen(s2) + 1);
    ft_strlcpy(join + ft_strlen(s1) +  ft_strlen(s2) , s3, ft_strlen(s3) + 1);
	//free((char *)s1);
	return (join);
}