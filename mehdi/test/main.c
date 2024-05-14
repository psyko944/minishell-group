#include "builtins.h"

static void	print_env(t_env_var *lst)
{
	t_env_var *tmp;

	tmp = lst;
	while (tmp)
	{
		printf("%s=%s\n", tmp->key, tmp->content);
		tmp = tmp->next;
	}
}

static void	print_env_sep(t_env_var *lst)
{
	t_env_var *tmp;

	tmp = lst;
	while (tmp)
	{
		printf("key = %s\tcontent = %s\n", tmp->key, tmp->content);
		tmp = tmp->next;
	}
}

int main(int ac, char **av, char **envp)
{
	t_env_var *new;
	new = get_env(envp);
	ft_unset(&new, ac, av);
	printf("first = %s\n",new->key);
	ft_cd(new, ac, av);
	//print_env(new);
	//print_env(new);
	//mini_echo(ac, av);
	return (0);
}
