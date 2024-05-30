#include "parser/tokenize/tokenize.h"
#include <stdlib.h>
void    free_env(t_env_var **env)
{
    t_env_var *tmp;

    tmp = *env;
    if (!env || !*env)
        return ;
    while (tmp)
    {
        free(tmp->key);
        free(tmp->content);
        tmp = (*env)->next;
        free(*env);
        *env = tmp;
    }
    *env = NULL;
}