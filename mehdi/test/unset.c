#include "builtins.h"


void    remove_env(t_env_var **envp, char *key)
{
    t_env_var *tmp;
    t_env_var *remove;

    tmp = *envp;
    while (tmp && tmp->next)
    {
        if (!ft_strncmp(key, tmp->key, ft_strlen(tmp->key)))
        {
            printf("tmp->key = %s\n", tmp->key);
            remove = tmp->next;
            tmp->next = tmp->next->next;
        }
        tmp = tmp->next;
    }
    printf("\n\n==test==\n\n");
    tmp = *envp;
    if (tmp && (!ft_strncmp(key, tmp->key, ft_strlen(tmp->key))))
    {
        *envp = tmp->next;
        free(tmp);
    }
}

void    ft_unset(t_env_var *envp, int ac, char **av)
{
    int i;

    (void)ac;
    i = 1;
    remove_env(&envp, av[i++]);
}