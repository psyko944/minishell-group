/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:44:10 by arlarzil          #+#    #+#             */
/*   Updated: 2024/07/25 16:22:04 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*remove_quotes(char *s)
{
	int		i;
	int		step;
	char	quote;

	quote = 0;
	i = 0;
	step = 0;
	while (s[i])
	{
		if (!quote && (s[i] == '\'' || s[i] == '"'))
		{
			quote = s[i];
			step += 1;
		}
		else if (quote && s[i] == quote)
		{
			++step;
			quote = 0;
		}
		else
			s[i - step] = s[i];
		++i;
	}
	s[i - step] = 0;
	return (s);
}
