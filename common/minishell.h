/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <armand.larzilliere@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:31:28 by arlarzil          #+#    #+#             */
/*   Updated: 2024/05/30 03:03:41 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

void	init_signals(void);
void	init(void);

typedef struct	s_command {
	char	**tab;
	int		in;
	int		out;
}	t_command;

int	open_app(const char *f, t_command *store);
int	open_here(const char *f, t_command *store);
int	open_in(const char *f, t_command *store);
int	open_out(const char *f, t_command *store);

#endif