#include "tokenize.h"

#include <string.h>
static int	ft_strcmp(const char *s1, const char *s2)
{
	return (strcmp(s1, s2));
}

t_link_type	get_link_eq(const char *s)
{
	const char			*ops[] = {"|", "<", ">", "<<", ">>", "&&", "||", 0};
	const t_link_type	eqs[] = {PIPE, IN_REDIRECT, OUT_REDIRECT, 
		HEREDOC, APPEND, AND_OPERATOR, OR_OPERATOR, 0};
	unsigned int 		i;

	i = 0;
	if (!s)
		return (NONE);
	while (eqs[i])
	{
		if (ft_strcmp(s, ops[i]) == 0)
			return (eqs[i]);
		++i;
	}
	return (NONE);
}
