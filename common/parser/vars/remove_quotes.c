/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:44:10 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/14 17:52:32 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*remove_quotes(char *s)
{
	int		i;
	int		step;
	char	quote;

	step = 0;
	i = 0;
	// printf("quote: %s\n", s);
	while (s[i + step])
	{
		if (s[i + step] == '\'' || s[i + step] == '"')
		{
			quote = s[i + step];
			step += 1;
			while (s[i + step] && s[i + step] != quote)
			{
				s[i] = s[i + step];
				++i;
			}
			step += 1;
		}
		else
			i += 1;
	}
	s[i] = 0;
	return (s);
}
