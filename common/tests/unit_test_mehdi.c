#include "../parser/tokenize/tokenize.h"
#include <stdio.h>

static void print_env(t_env_var *lst)
{
    t_env_var *tmp;

	tmp = lst;
	while (tmp)
	{
		if (tmp->content != NULL)
			printf("%s=%s\n", tmp->key, tmp->content);
		tmp = tmp->next;
    }
}

void    unit_test_mehdi(int ac, char **av, char **envp)
{
    t_env_var *env;

    (void)ac;
    (void)av;
    env = get_env(envp);
    print_env(env);
}