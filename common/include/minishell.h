/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:31:28 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/21 21:57:18 by mekherbo         ###   ########.fr       */
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
# include <termios.h>
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
	pid_t		pid;
	int			wait_status;
	int			history_fd;
	int			code;
	char		*prompt;
	bool		pipe;
	bool		check;
	bool		exit_pipe;
	int			parenthese_in;
	int			parenthese_out;
	int			count_pipe;
	int			old_stdin;
	int			old_stdout;
	int			fd[2];
}	t_global;

typedef struct s_command
{
	char	**tab;
	int		in;
	int		out;
}			t_command;

extern int	g_exit_status;
int			get_history(t_global *mini_s);

void		prompt_sig(void);
void		def_sig(void);
void		here_sig(void);
void		init(t_global *mini_s, char **envp);
void		ft_append_history(char *cmd, int fd);

// env functions
char		*get_value(char *line);
char		*get_value_search(t_env_var *env, char *key);
char		*get_prompt(t_env_var *env);
int			get_sub_tok_count(const char *s);
int			search_in_env(t_env_var *env, char *key);
t_env_var	*first_node(char *env_line);
t_env_var	*get_env(t_global *mini_s, char **envp);
void		addback_env(t_env_var **alst, t_env_var *new);
void		free_env(t_global *mini_s);
void		concat_env(t_env_var **env, char *value);
void		replace_env(t_env_var *env, char *value);
char		*get_key(char *line);
void		err_msg(char *msg);

// builtins

bool		parse_builtins(t_global *mini_s, t_command *cmd);
void		mini_echo(t_global *mini_s, char **tab);
void		remove_env(t_env_var **envp, char *key);
void		ft_unset(t_global *mini_s, char **tab);
void		ft_export(t_global *mini_s, char **tab);
void		ft_cd(t_global *mini_s, char **tab);
char		*get_pwd(void);
void		pwd_env(t_global *mini_s, int flag);
void		ft_exit(t_global *mini_s, char **tab);
void		print_pwd(t_global *mini_s, char **tab);

//          files
int			get_files(char **command, t_command *storage, t_global *mini_s);
int			open_here(const char *f, t_command *store, t_global *mini_s);
int			open_app(const char *f, t_command *store, t_global *mini_s);
int			open_in(const char *f, t_command *store, t_global *mini_s);
int			open_out(const char *f, t_command *store, t_global *mini_s);
void		runtime_heredoc(const char *f, int *fd, t_global *mini_s);

char		**fill_wild_tab(char **base, const char *path);
void		err_msg(char *msg);
void		status_env(t_env_var **env, int exit_status);
void		print_env(t_env_var *lst);
void		get_shlvl(t_global *mini_s);
char		*replace_vars(char *s, t_env_var *env);

// exec functions
bool		cmd_runtime(t_command *cmd, t_global *env);
char		*get_cmd(char *cmd, char **envp);
int			wait_status(t_global *mini_s);
int			ph_exec_tree(t_ast *tree, int *exit_cmd, t_global *env);
int			exec_and_cmd(t_ast *tree, int *exit_cmd, t_global *mini_s);
int			exec_or_cmd(t_ast *tree, int *exit_cmd, t_global *mini_s);
int			ph_exec_par(t_ast *node, t_global *env);
char		**new_matrix(t_env_var *env);

#endif