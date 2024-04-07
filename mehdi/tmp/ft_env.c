#include "minishell.h"
static void	addback_env(t_env **alst, t_env *new)
{
	t_env	*last;

	if (*alst)
	{
		last = *alst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
	else
		*alst = new;
}


static t_env *first_node(char *env_line)
{
    t_env   *new;

    new = malloc(sizeof * new);
    if (!new)
        return (NULL);
    new->line = ft_strdup(env_line);
    return (new);
}

t_env *get_env(char **envp)
{
    t_env *env;
    int  i = 0;
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