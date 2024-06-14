#include <tokenize.h>
#include <minishell.h>
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
    t_global    mini_s;
    (void)ac;
    (void)av;
    env = get_env(&mini_s, envp);
    if (!env)
        printf("no env\n");
    mini_s.env = env;
    get_history(&mini_s);
    pwd_env(&mini_s);
    // search_node(&mini_s, ast_tree);
    free_env(&mini_s);
    //printf("%s\n", get_pwd());
    //print_env(env);
    //free_matrix(mini_s.envp);
}