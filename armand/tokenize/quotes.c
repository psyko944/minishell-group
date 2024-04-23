#include "libft/libft.h"

int	skip_quote(const char *s)
{
	char		c;
	const char	*s2;

	c = *s;
	s += 1;
	s2 = ft_strchr(s, c);
	if (!s2)
		return (-1);
	return (s2 - s + 2);
}