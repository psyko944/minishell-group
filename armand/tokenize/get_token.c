#include "tokenize.h"
#include "libft/libft.h"
#include <stdlib.h>

// Inc string todo
t_token	*get_parenthesis(const char **s_ptr)
{
	t_token		*res;
	const char	*s;
	int			step;
	int			len;

	s = *s_ptr;
	len = 1;
	while (**s_ptr && **s_ptr != ')')
	{
		if (**s_ptr == '"' || **s_ptr == '\'')
			step = skip_quote(s);
		else
			step = 1;
		if (step == -1)
			return (NULL); // Err message
		len += step;
		*s_ptr += step;
	}
	return (new_token(PARENTHESIS, ft_strndup_e(s + 1, len - 2))); // A vérifier
}

size_t	is_sep(const char	*s)
{
	const char	*seps[] = { "||", "&&", ">>", "<<", "(", "<", ">", "|", NULL};
	int			i;
	size_t		sep_len;

	i = 0;
	while (seps[i])
	{
		sep_len = ft_strlen(seps[i]);
		if (ft_strncmp(s, seps[i], sep_len) == 0)
			return (sep_len);
		i += 1;
	}
	return (0);
}

// Cas spécial separateur todo
t_token	*get_word(const char **s)
{
	const char	*s2;
	int			len;
	int			step;
	t_token		*res;

	__builtin_printf("%s\n", *s);
	s2 = *s;
	len = 0;
	step = is_sep(s2);
	if (step)
	{
		*s += step;
		return (new_token(SEPARATOR, ft_strndup_e(s2, step)));
	}
	while (**s && !is_sep(*s))
	{
		if (**s == '\'' || **s == '"')
			step = skip_quote(*s);
		else
			step = 1;
		len += step;
		*s += step;
	}
	return (new_token(TEXT, cut_command(ft_strndup_e(s2, len))));
}
