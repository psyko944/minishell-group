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

static void	print_pwd(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp("PWD", envp[i], 3))
			printf("%s\n", envp[i]);
		i++;
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
	//ft_unset(&new, ac, av);
	printf("%s\n", get_pwd(new));
	ft_cd(new, ac, av);
	printf("%s\n", get_pwd(new));
	print_pwd(envp);
	//print_env(new);
	//print_env(new);
	//mini_echo(ac, av);
	return (0);
}
