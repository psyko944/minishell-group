#include <stdlib.h>

#include "libft.h"
#include "parser.h"
/*
// Renvoie l'adresse de dest après avoir ajouté notre value
static char	*interpret_single_variable(char *dest, char *key, t_env_var *vars)
{
	char	*content;
	int		content_len;

	content = get_env_key_value(vars, key);
	content_len = ft_strlen(content);
	ft_strncpy(dest, content, content_len);
	return (dest + content_len);
}

static char	*interpret_variables(char *s, t_env_var *vars)
{
	char			*res;
	char			*res_loc;
	unsigned int	len;
	char			*key;

	// count_len ToDo
	res = ft_calloc(count_len(s, vars), sizeof(char));
	if (!res)
		return (NULL);
	res_loc = res;
	while (*s)
	{
		if (*s == '$')
		{
			len = get_key_len(s);
			key = ft_strndup_e(s, len);
			if (!key)
				__builtin_printf("PANIC\n");
			res_loc = interpret_single_variable(res_loc, key, vars);
			free(key);
		}
		else
			*res_loc = *s;
		++s;
	}
	return (res);
}
/**/
void	interpret_command_variables(t_parsed_cmd *cmd, t_env_var *env)
{
	while (cmd)
	{

		cmd = cmd->next;
	}
	__builtin_printf("That's temp bro\n");
}
