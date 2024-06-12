/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arlarzil <arlarzil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:05:44 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/12 19:24:43 by arlarzil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

# include "../minishell.h"

char	*replace_vars(char *s, t_env_var *env);
char	**cut_vars(char *s);
char	*concat_tab(char **tab);

#endif
