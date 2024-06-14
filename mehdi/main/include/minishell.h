/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:31:28 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/14 18:32:34 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <signal.h>
# include <string.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <libft.h>

# define COMMAND_SUCCESS 0
# define COMMAND_TOO_MANY_ARGUMENTS 1
# define COMMAND_REDIRECTION_ERROR 1
# define COMMAND_PARSING_ERROR 2
# define COMMAND_NOT_EXECUTABLE 126
# define COMMAND_ISDIRECTORY 126
# define COMMAND_NOT_FOUND 127
# define COMMAND_SIGINT 130
# define COMMAND_SIGQUIT 131
# define HISTORY_NAME "ValhallaShell"

typedef struct s_env_var
{
	char				*key;
	char				*content;
	struct s_env_var	*next;
}	t_env_var;

typedef struct s_global
{
    t_env_var	*env;
	char		**envp;	
}   t_global;

typedef struct s_command {
	char	**tab;
	int		in;
	int		out;
}	t_command;

void	init_signals(void);
void	init(void);
void    get_history(t_global *mini_s);


// env functions
t_env_var *get_env(t_global *mini_s,char **envp);
void	addback_env(t_env_var **alst, t_env_var *new);
t_env_var *first_node(char *env_line);
char	*get_value(char *line);
void    free_env(t_global *mini_s);
void    err_msg(char *msg);


// builtins

void mini_echo(int ac, char **av);
void    remove_env(t_env_var **envp, char *key);
void    ft_unset(t_env_var **envp, int ac, char **av);
void    ft_cd(t_env_var *env, int ac, char **av);
char    *get_pwd(void);
void	pwd_env(t_global *mini_s);


int	open_here(const char *f, t_command *store);
int	open_app(const char *f, t_command *store);
int	open_in(const char *f, t_command *store);
int	open_out(const char *f, t_command *store);

// exec functions
#endif