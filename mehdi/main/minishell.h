/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:31:28 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/04 08:23:59 by mekherbo         ###   ########.fr       */
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
# include "libft/libft.h"

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
    t_env_var *env;
}   t_global;


void	init_signals(void);
void	init(void);
void    get_history(t_global *mini_s);
t_env_var *get_env(char **envp);
void    free_env(t_env_var **env);


#endif