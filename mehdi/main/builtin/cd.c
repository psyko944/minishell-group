#include "../minishell.h"

static int  check_dir(char *path)
{
    if (path == NULL || ft_strlen(path) == 0)
        return (-1);
    if (chdir(path) != 0)
    {
        perror("chdir");
        return (-1);
    }
    printf("reussi\n");
    return (0);
}

static char    *get_home(t_env_var *env)
{
    char    *home;
    t_env_var *tmp;

    tmp = env;
    while (tmp)
    {
        if (!ft_strncmp("HOME", tmp->key, 4))
            home = ft_strdup(tmp->content);
        tmp = tmp->next;
    }
    return (home);
}

char    *get_pwd(void)
{
    char    *pwd;

    pwd = ft_calloc(4096, sizeof(char));
    if (!pwd)
        return (perror("minishell"), NULL);
    getcwd(pwd, 4096);
    return (pwd);
}

char    *get_pwd_2(t_env_var *env)
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
    //const char *cur_dir = get_pwd();
    char    *path;

    if (ac == 1)
    {
        path = get_home(env);
        printf("path = %s\n", path);
        if (!path)
            return ;
    }
    else if (ac == 2)
        path = av[1];
    else
        return ;
    if (!ft_strncmp(path, "-", 1))
    {
        printf("%s", get_pwd());
        return ;
    }
    if (check_dir(path))
    {
        printf("error changement de path\n");
        return ;
    }
}