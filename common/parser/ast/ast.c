/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:52 by arlarzil          #+#    #+#             */
/*   Updated: 2024/08/07 21:14:04 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ast.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool	is_redirec_token(const char *tok)
{
	bool	prev_redirec;

	prev_redirec = false;
	while (*tok)
	{
		if (*tok == '&' || *tok == '|')
			break ;
		else if (*tok == '>' || *tok == '<')
			prev_redirec = true;
		else if (prev_redirec == false && ft_isalpha(*tok))
			return (false);
		else if (ft_isalpha(*tok))
		{
			while (*tok && !ft_isspace(*tok))
				++tok;
			prev_redirec = false;
			--tok;
		}
		++tok;
	}
	return (true);
}

static void	ast_step(t_token *tokens, t_token **last_op)
{
	if (tokens->type == SEPARATOR)
	{
		tokens->type = get_sep_type(tokens->content);
		if (*last_op)
			tokens->next = *last_op;
		*last_op = tokens;
		if (tokens->next->type == TEXT
			&& tokens->next->next && tokens->next->next->type == PARENTHESIS)
		{
			tokens->next = tokens->next->next;
		}
	}
	else if (tokens->type == PARENTHESIS)
		tokens->content = build_ast(tokens->content);
}

static t_ast	*no_sep_handle(t_token *tokens)
{
	if (tokens->type == TEXT && tokens->next)
		print_parse_err("(");
	else if (tokens->type == PARENTHESIS)
		tokens->content = build_ast(tokens->content);
	return ((t_ast *)tokens);
}

static t_ast	*fix_par_redirect(t_ast *ast)
{
	t_ast	*res;

	res = ast;
	while (ast)
	{
		if (ast->l && ast->l->type == TEXT)
			if (ast->l->l && ast->l->l->type == PARENTHESIS)
				ast->l = ast->l->l;
		ast = ast->r;
	}
	return (res);
}

t_ast	*build_ast(t_token *tokens)
{
	t_token	*next_tok;
	t_token	*last_op;

	if (!tokens || !check_format(tokens))
		return (free_tokens(tokens), NULL);
	last_op = NULL;
	if (!has_seps(tokens))
		return (no_sep_handle(tokens));
	while (tokens->next)
		tokens = tokens->next;
	while (tokens)
	{
		next_tok = tokens->prev;
		ast_step(tokens, &last_op);
		tokens = next_tok;
	}
	return (fix_par_redirect((t_ast *)last_op));
}
