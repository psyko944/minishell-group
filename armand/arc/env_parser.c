#include <stdlib.h>

#include "parser.h"

char	*ft_strdup(const char *s);
char	*ft_strndup_e(const char *s, size_t l);

t_env_var	*free_env(t_env_var *env)
{
	t_env_var	*tmp;

	while (env)
	{
		tmp = env->next;
		free(env->key);
		free(env->content);
		free(env);
		env = tmp;
	}
	return (NULL);
}
// Verifier que les dup ont bien fonctionné, à voir aussi dans le parser "standard"
static t_env_var	*add_env_line(t_env_var **base, char *key, char *content)
{
	t_env_var	*new;
	t_env_var	*cur;

	if (!key || !content)
		return (free(key), free_env(*base));
	new = malloc(sizeof(t_env_var));
	if (!new)
		return (free_env(*base));
	new->key = key;
	new->content = content;
	new->next = NULL;
	if (!*base)
		*base = new;
	else
	{
		cur = *base;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
	return (*base);
}

int	get_key_len(const char *s)
{
	int	res;

	res = 0;
	while (*s && *s != '=')
	{
		++s;
		++res;
	}
	return (res);
}

t_env_var	*parse_env(const char **env)
{
	int			i;
	int			key_len;
	t_env_var	*res;

	i = 0;
	res = NULL;
	while (env[i])
	{
		key_len = get_key_len(env[i]);
		if (add_env_line(&res, ft_strndup_e(env[i], key_len),
			ft_strdup(env[i] + key_len + 1)) == NULL)
			return (res);
	}
	return (res);
}

char	*get_env_key_value(t_env_var *env, const char *key)
{
	while (env)
	{
		if (strcmp(key, env->key) == 0)
			return (env->content);
		env = env->next;
	}
	return (NULL);
}