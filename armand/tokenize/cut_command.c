#include "tokenize.h"
#include "libft/libft.h"

#include <stdlib.h>

static int	count_args(char *s)
{
	int	res;

	res = 0;
	while (*s)
	{
		while (ft_isspace(*s))
			++s;
		if (*s)
			res += 1;
		while (*s && !ft_isspace(*s))
		{
			if (*s == '"' || *s == '\'')
				s += skip_quote(s);
			else
				s += 1;
		}
	}
	return (res);
}

static void	fill_tab(char *s, char **res, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		while (ft_isspace(*s))
			++s;
		res[i] = s;
		while (*s && !ft_isspace(*s))
		{
			if (*s == '"' || *s == '\'')
				s += skip_quote(s);
			++s;
		}
		*s = 0;
		++s;
		++i;
	}
	res[i] = NULL;
}

char	**cut_command(char *s)
{
	int		len;
	char	**res;

	if (!s)
		return (NULL);
	len = count_args(s);
	__builtin_printf("%d args\n", len);
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
	{
		free(s);
		return (NULL);
	}
	fill_tab(s, res, len);
	return (res);
}