#include "../parser/tokenize/tokenize.h"
#include "../minishell.h"
#include <stdio.h>

//void    runtime_cmd()
// static void print_env(t_env_var *lst)
// {
//     t_env_var *tmp;

// 	tmp = lst;
// 	while (tmp)
// 	{
// 		if (tmp->content != NULL && tmp->key) 
// 			printf("%s=%s\n", tmp->key, tmp->content);
// 		tmp = tmp->next;
//     }
// }

void    unit_test_mehdi(int ac, char **av, char **envp)
{
    t_env_var   *env;
    t_global    minichienne;
    (void)ac;
    (void)av;
    env = get_env(envp);
    if (!env)
        printf("no env\n");
    minichienne.env = env;
    get_history(&minichienne);
    //print_env(env);
    free_env(&env);
}