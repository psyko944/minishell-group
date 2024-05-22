#include "builtins.h"


static void parse_export(char *arg, t_env_var)
{
    int i;

    i = 0;
    while(av[i])
    {
        if (av[i] == '=')
        
    }
}

void print_export_env(t_env_var *env)
{
    size_t  i;
    t_env_var *tmp;

    tmp = env;
    i = 0;
    while (tmp)
    {
        if (tmp->content != NULL)
            printf("declare -x %s=\"%s\"\n", tmp->key, tmp->content);
        else
            printf("declare -x %s\n", tmp->key);
        tmp = tmp->next;
    }
}

// void    ft_export(t_env_var *env, int ac, char **av)
// {
//      t_env_var *tmp;

//      tmp = env;    
// }