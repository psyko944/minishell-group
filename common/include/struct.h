/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 01:02:46 by mekherbo          #+#    #+#             */
/*   Updated: 2024/08/23 02:13:09 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdlib.h>

typedef enum e_token_type {
	TEXT,
	SEPARATOR,
	PARENTHESIS,
	N_PIPE,
	N_AND,
	N_OR,
	COMMAND
}	t_token_type;	

typedef struct s_token {
	t_token_type	type;
	void			*content;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_env_var
{
	char				*key;
	char				*content;
	struct s_env_var	*next;
}	t_env_var;

typedef struct s_ast {
	t_token_type	type;
	void			*content;
	struct s_ast	*l;
	struct s_ast	*r;
}	t_ast;

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
	bool		hflag;
	bool		pipe;
	bool		check;
	bool		exit_pipe;
	int			parenthese_in;
	int			parenthese_out;
	bool		par_flag;
	int			count_pipe;
	int			old_stdin;
	int			old_stdout;
	t_ast		*ast;
	char		*cmd;
	char		*fribi[128];
	int			fd[1];
}	t_global;

typedef struct s_command
{
	char	**tab;
	int		in;
	int		out;
}			t_command;

#endif