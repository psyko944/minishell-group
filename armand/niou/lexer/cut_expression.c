#include "lexer.h"
#include "../quote.h"

static int	ft_isspace(char c) // Temp version
{
	return (c == 32);
}

static int	get_token_len(const char *s)
{
	int	len;
	int	step;

	len = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (is_quote(*s))
			step = quote_len(s);
		else if (ft_isspace(*s))
			return (len);
		else
			step = 1;
		if (step == -1)
			return (-1);
		len += step;
		s += step;
	}
	__builtin_printf("len=%d\n", len);
	return (len);
}

t_lexed_list	*cut_expression(t_lexed_list *l)
{
	int			token_len;
	const char	*s;
	
	s = l->content;
	__builtin_printf("2: %s\n", s);
	while (*s)
	{
		while (ft_isspace(*s))
			++s;
		if (!*s)
			break ;
		token_len = get_token_len(s);
		//__builtin_printf("Found token at (%s) of len (%d)\n", s, token_len);
		s += token_len;
	}
	return (0); //ToDoDiDo
}
