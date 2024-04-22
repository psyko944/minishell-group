/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_parenthesis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 18:19:14 by arlarzil          #+#    #+#             */
/*   Updated: 2024/04/16 18:19:16 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "lexer.h"
#include "../quote.h"
#include <stdlib.h>

// Doit prendre les guillemets en compte
// Approche moins stupide avec strchr possible
static	t_lexed_list	*get_till_parenthesis(const char *s, u_int32_t *len)
{
	const char		*tmp;
	int				step;

	tmp = s;
	while (*s && *s != '(')
	{
		if (*s == ')')
			return (NULL); // Message parenthese fermante anormale
		if (is_quote(*s))
			step = quote_len(s);
		else
			step = 1;
		s += step;
		*len += step;
	}
	return (lex_new_node(ft_strndup_e(tmp, *len), NULL));
}

static int	get_par_len(const char *s)
{
	int	par_count;
	int	len;
	int	step;

	len = 0;
	par_count = 1;
	while (*s && par_count)
	{
		if (*s == '(')
			par_count += 1;
		else if (*s == ')')
			par_count -= 1;
		if (is_quote(*s))
			step = quote_len(s);
		else
			step = 1;
		s += step;
		len += step;
	}
	if (par_count)
		return (-1); // Parenthese non fermée
	return (len);
}

// Doit aussi prendre les guillemets en compte
static	t_lexed_list	*get_parenthesis(const char *s, u_int32_t *len)
{
	t_lexed_list	*res;
	char			par_len;
	char			*temp_cont;

	s += 1;
	par_len = get_par_len(s);
	if (par_len == -1)
		return (NULL);
	*len += par_len;
	temp_cont = ft_strndup_e(s, *len - 1);
	res = lex_new_node(NULL, mini_lexer(temp_cont));
	free(temp_cont);
	*len += 1;
	return (res);
}

// Attention aux guillemets
t_lexed_list	*split_parenthesis(const char *s)
{
	unsigned int	token_len;
	t_lexed_list	*res;

	res = NULL;
	while (*s)
	{
		token_len = 0;
		if (*s == ')')
			return (ft_putstr_fd("Parse error\n", 2), free_lexer(res));
		else if (*s != '(')
			lex_add_back(&res, get_till_parenthesis(s, &token_len));
		else
			lex_add_back(&res, get_parenthesis(s, &token_len));
		if (res == NULL)
			return (NULL);
		s += token_len;
	}
	return (res);
}
