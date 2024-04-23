#include <string.h>

char	*ft_strchr(const char *s, char c)
{
	return (strchr(s, c));
}

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	return (strncmp(s1, s2, len));
}