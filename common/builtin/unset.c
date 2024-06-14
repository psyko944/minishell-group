#include "builtins.h"


void    remove_env(t_env_var **envp, char *key)
{
    t_env_var *tmp;

    if (!envp || !*envp)
        return ;
    tmp = *envp;
    if (!ft_strncmp(tmp->key, key, ft_strlen(tmp->key)))
    {
        *envp = tmp->next;
        free(tmp);
        remove_env(envp, key);
    }
    else
    {
        tmp = *envp;
        remove_env(&tmp->next, key);
    }
}

void    ft_unset(t_env_var **envp, int ac, char **av)
{
    int i;

    (void)ac;
    i = 1;
    if (!av[i])
    {
        printf("pas d'arguments\n");
        return ;
    }
    remove_env(envp, av[i]);
}