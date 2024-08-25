/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:28:15 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/23 00:24:07 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include <tokenize.h>
# include <stdbool.h>

// typedef struct s_ast {
// 	t_token_type	type;
// 	void			*content;
// 	struct s_ast	*l;
// 	struct s_ast	*r;
// }	t_ast;

t_ast			*build_ast(t_token *tokens);
t_ast			*free_ast(t_ast *ast);
bool			has_seps(t_token *tokens);
t_token_type	get_sep_type(char *sep);
int				check_format(t_token *tokens);
bool			is_redirec_token(const char *tok);

#endif
