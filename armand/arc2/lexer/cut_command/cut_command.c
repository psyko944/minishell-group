#include "tokenize.h"
#include "../../quote.h"
#include "../../libft/libft.h"
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>

int		ft_isspace(char c);
char	*ft_strndup_e(const char *s, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t size)
{
	return (strncmp(s1, s2, size));
}

static unsigned int	is_sep(const char *str)
{
	const char		*ops[] = {"<<", ">>", "&&", "||", "|", "<", ">", ")", NULL};
	unsigned int	sep_len;
	unsigned int	i;

	i = 0;
	if (!*str || ft_isspace(*str))
		return (1);
	while (ops[i])
	{
		sep_len = ft_strlen(ops[i]);
		if (ft_strncmp(ops[i], str, sep_len) == 0)
			return (sep_len);
		++i;
	}
	return (0);
}

static unsigned int	get_word_len(const char *str)
{
	unsigned int	res;
	unsigned int	len;

	res = 0;
	len = is_sep(str);
	if (len)
		return (len);
	while (!is_sep(str))
	{
		if (*str == '\'' || *str == '"')
			len = quote_len(str);
		else
			len = 1;
		str += len;
		res += len;
	}
	return (res);
}

t_cmd_symbol	*get_and_skip_word(const char **str)
{
	t_cmd_symbol		*ret;
	unsigned int		word_len;

	ret = malloc(sizeof(t_cmd_symbol));
	if (!ret)
		return (ret);
	word_len = get_word_len(*str);
	ret->next = NULL;
	ret->last = NULL;
	ret->content = 
	ret->content = ft_strndup_e(*str, word_len);
	*str += word_len;
	return (ret);
}

t_cmd_symbol	*cut_command(const char *str)
{
	t_cmd_symbol	*ret;
	t_cmd_symbol	*new;

	ret = NULL;
	while (*str)
	{
		while (ft_isspace(*str))
			++str;
		new = get_and_skip_word(&str);
		if (!new)
			return (free_parse(ret));
		add_back(new, &ret);
	}
	return (ret);
}
