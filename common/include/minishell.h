/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:31:28 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/12 19:41:09 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

void	init_signals(void);
void	init(void);

typedef struct s_command {
	char	**tab;
	int		in;
	int		out;
}	t_command;

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


int		open_app(const char *f, t_command *store);
int		open_here(const char *f, t_command *store);
int		open_in(const char *f, t_command *store);
int		open_out(const char *f, t_command *store);

#endif