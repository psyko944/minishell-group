/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:31:28 by arlarzil          #+#    #+#             */
/*   Updated: 2024/07/03 20:42:34 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <unistd.h>
# include <stdbool.h>
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
# include <ast.h>

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
	int			shlvl;
	t_env_var	*env;
	char		**envp;
	int			pid;
	int			wstatus;
	int			history_fd;
	bool		pipe;
	bool		check;
	int			count_pipe;
}	t_global;

typedef struct s_command
{
	char	**tab;
	int		in;
	int		out;
}			t_command;

void		init_signals(void);
void		init(t_global *mini_s, char **envp);
int			get_history(t_global *mini_s);
void		ft_append_history(char *cmd, int fd);

// env functions
t_env_var	*get_env(t_global *mini_s, char **envp);
void		addback_env(t_env_var **alst, t_env_var *new);
t_env_var	*first_node(char *env_line);
char		*get_value(char *line);
void		free_env(t_global *mini_s);
int			search_in_env(t_env_var *env, char *key);
void		concat_env(t_env_var **env, char *value);
void		replace_env(t_env_var *env, char *value);
char		*get_key(char *line);
void		err_msg(char *msg);
int			get_sub_tok_count(const char *);
int	ph_exec_tree(t_ast *tree, int *exit_cmd, t_global *env);
// builtins

bool		parse_builtins(t_global *mini_s, t_command *cmd);
void		mini_echo(t_global *mini_s, char **tab);
void		remove_env(t_env_var **envp, char *key);
void		ft_unset(t_global *mini_s, char **tab);
void		ft_export(t_global *mini_s, char **tab);
void		ft_cd(t_global *mini_s, char **tab);
char		*get_pwd(void);
void		pwd_env(t_global *mini_s);
void		ft_exit(t_global *mini_s, char **tab);
void		print_pwd(t_global *mini_s, char **tab);

int			open_here(const char *f, t_command *store);
int			open_app(const char *f, t_command *store);
int			open_in(const char *f, t_command *store);
int			open_out(const char *f, t_command *store);

char		**fill_wild_tab(char **base, const char *path);
char		*get_cmd(char *cmd, char **envp);
void		cmd_runtime(t_command *cmd, t_global *env);
void		err_msg(char *msg);
void		status_env(t_env_var **env, int exit_status);
void		print_env(t_env_var *lst);
void		get_shlvl(t_global *mini_s);
// exec functions
#endif