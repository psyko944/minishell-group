#ifndef BUILTINS_H
# define BUILTINS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"


t_env_var *get_env(char **envp);
void mini_echo(int ac, char **av);
void    remove_env(t_env_var **envp, char *key);
void    ft_unset(t_env_var **envp, int ac, char **av);
void    ft_cd(t_env_var *env, int ac, char **av);
char    *get_pwd(t_env_var *env);
void	addback_env(t_env_var **alst, t_env_var *new);
void	print_export_env(t_env_var *env);
# endif
