#include <stdlib.h>

static size_t	count_dol(char *s)
{
	size_t	res;

	res = 0;
	while (*s)
	{
		res += 1;
		printf("Word starting at: %s\n", s);
		if (*s == '$')
		{
			s += 1;
			while (*s && !ft_isspace(*s) && *s != '$')
				++s;
		}
		else
			while (*s && *s != '$')
				++s;
	}
	printf("Word count: %d\n", res);
	return (res);
}

size_t	get_var_len(char *s)
{
	size_t	res;

	if (*(s + 1) == '?')
		return (2);
	res = 1;
	s += 1;
	while (*s && !ft_isspace(*s) && *s != '$')
	{
		++s;
		++res;
	}
	return (res);
}

size_t	get_len_to_var(char *s)
{
	size_t res;

	res = 0;
	while (*s && *s != '$')
	{
		++s;
		res += 1;
	}
	return (res);
}

char	*extract_var(char **s)
{
	char	*cur;
	size_t	len;

	cur = *s;
	if (*cur == '$')
		len = get_var_len(cur);
	else
		len = get_len_to_var(cur);
	*s += len;
	printf("Len: %ld\n", len);
	return (ft_strndup_e(cur, len));
}

char	**extract_vars(char *s)
{
	size_t	size;
	char	**res;
	int		i;
	char	*p;

	i = 0;
	p = s;
	size = count_dol(s);
	res = malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (free(p), NULL);
	while (i < size)
		res[i++] = extract_var(&s);
	res[i] = 0;
	free(p);
	return (res);
}

int	main(int ac, char **av)
{
	char	**res = extract_vars(strdup(av[ac - 1]));
	char	**p = res;

	while (*res)
	{
		printf("%s\n", *res);
		free(*res);
		++res;
	}
	free(p);
}