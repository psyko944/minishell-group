#include <minishell.h>
#include <stdlib.h>

static char	*get_key(char *line)
{
	int	i;
	char	*key;
	
	i = 0;
	while (line[i] && line[i] != '=')
		i++;
	key = malloc(sizeof(char) * i + 1);
	if (!key)
		return (NULL);
	i = 0;
	while (line[i] && line[i] != '=')
	{
		key[i] = line[i];
		i++;
	}
	key[i] = '\0';
	return (key);
}

char	*get_value(char *line)
{
	int		i;
	int		j;
	int		k;
	char	*content;

	i = 0;
	while (line[i] && line[i] != '=')
		i++;
	if (line[i] == '=')
		i++;
	j = 0;
	k = i;
	while (line[i++])
		j++;
	content = malloc(sizeof(char) * j + 1);
	if (!content)
		return (NULL);
	j = -1;
	while (line[k])
		content[++j] = line[k++];
	content[++j] = '\0';
	return (content);
}

void	addback_env(t_env_var **alst, t_env_var *new)
{
	t_env_var	*last;

	if (!new)
		return ;
	if (alst && *alst)
	{
		last = *alst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*alst = new;
}


t_env_var *first_node(char *env_line)
{
    t_env_var   *new;

    new = malloc(sizeof(*new));
    if (!new)
        return (NULL);
    new->key = get_key(env_line);
    new->content = get_value(env_line);
	new->next = NULL;
    return (new);
}

t_env_var *get_env(t_global *mini_s, char **envp)
{
    t_env_var *env;
    int  i = 0;
	if ((!envp) || (!envp[0][0]))
		return (NULL);
	(void)mini_s;
	mini_s->envp = ft_cpy_matrix(envp);
	 if (!mini_s->envp)
	 	(err_msg("envp error"), exit(EXIT_FAILURE));
    while (envp[i])
    {
        if (i == 0)
            env = first_node(envp[i]);
        else
           addback_env(&env, first_node(envp[i]));
        i++;
    }
    return (env);
}
