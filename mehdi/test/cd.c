#include "builtins.h"

static char    *get_pwd(t_env_var *env)
{
    char    *pwd;
    t_env_var *tmp;

    tmp = env;
    while (tmp)
    {
        if (!ft_strncmp("PWD", tmp->key, 3))
            pwd = ft_strdup(tmp->content);
        tmp = tmp->next;
    }
    return (pwd);
}

void    ft_cd(t_env_var *env, int ac, char **av)
{
    const char *target_dir = av[1];
    (void)ac;
    const char *cur_dir = get_pwd(env);
    if (!cur_dir)
        return (NULL);
    
}