#ifndef BUILTINS_HGJS_DEBUG_TOPICS
# define BUILTINS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_env_var
{
	char				*key;
	char				*content;
	struct s_env_var	*next;
}	t_env_var;

t_env_var *get_env(char **envp);
void mini_echo(int ac, char **av);
void    remove_env(t_env_var **envp, char *key);
void    ft_unset(t_env_var **envp, int ac, char **av);
void    ft_cd(t_env_var *env, int ac, char **av);
# endif