#include <minishell.h>

static void    addfront_env(t_env_var **env, t_env_var *new)
{
    if (!new || !env)
        return ;
    if (*env)
        new->next = *env;
    *env = new;
}

void    status_env(t_env_var **env, int status)
{
    char *str_status;
    char *tmp;

    str_status = ft_itoa(status);
    if (!str_status)
        return ;
    tmp = ft_strjoin("?=", str_status);
    free(str_status);
    if (!tmp)
        return ;
    addfront_env(env, first_node(tmp)); 
}