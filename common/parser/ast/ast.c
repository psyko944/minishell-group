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

static bool	is_redirec_token(const char *tok)
{
	bool	prev_redirec;

	prev_redirec = false;
	printf("Coucou '%s'\n", tok);
	while (*tok)
	{
		printf("%c", *tok);
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
	printf("Check ok\n");
	return (true);
}

static int	check_format(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens->next)
	{
		printf("Checking %s at index %d\n", (char*)tokens->content, i);
		if (tokens->type == SEPARATOR && i % 2 == 0)
			return (print_parse_err(tokens->content), 0);
		else if (tokens->type == TEXT && i % 2 == 1)
			return (print_parse_err(tokens->content), 0);
		else if (tokens->type == PARENTHESIS)
		{
			if (tokens->next->type == PARENTHESIS || (tokens->next->type == TEXT && !is_redirec_token(tokens->next->content)))
			{
				printf("sa feil\n");
				return (print_parse_err(tokens->content), 0);
			}
			if (tokens->next->type == TEXT)
				i -= 1;
		}
		tokens = tokens->next;
		i += 1;
	}
	if (tokens->type == SEPARATOR)
		return (print_parse_err("newline"), 0);
	return (1);
}

t_ast	*free_ast(t_ast *ast)
{
	if (!ast)
		return (NULL);
	if (ast->type == PARENTHESIS)
		free_ast(ast->content);
	else if (ast->type == COMMAND)
		free_tab(ast->content);
	else if (ast->type & (N_AND | N_OR | N_PIPE))
	{
		free_ast(ast->l);
		free_ast(ast->r);
	}
	free(ast);
	return (NULL);
}

static t_token_type	get_sep_type(char *sep)
{
	const char			*seps[] = {"||", "&&", "|", NULL };
	const t_token_type	types[] = {N_OR, N_AND, N_PIPE};
	int					i;

	i = 0;
	while (seps[i])
	{
		if (ft_strncmp(seps[i], sep, ft_strlen(seps[i])) == 0)
		{
			free(sep);
			return (types[i]);
		}
		++i;
	}
	return (SEPARATOR);
}

void	ast_step(t_token *tokens, t_token **last_op)
{
	if (tokens->type == SEPARATOR)
	{
		tokens->type = get_sep_type(tokens->content);
		if (*last_op)
			tokens->next = *last_op;
		*last_op = tokens;
		if (tokens->next->type == TEXT && tokens->next->next && tokens->next->next->type == PARENTHESIS)
		{
			tokens->next = tokens->next->next;
		}
	}
	else if (tokens->type == PARENTHESIS)
		tokens->content = build_ast(tokens->content);
}

static bool	has_seps(t_token *tokens)
{
	while (tokens)
	{
		if (tokens->type == SEPARATOR)
			return (true);
		tokens = tokens->next;
	}
	return (false);
}

static t_ast	*no_sep_handle(t_token *tokens)
{
	if (tokens->type == TEXT && tokens->next)
		print_parse_err("(");
	else if (tokens->type == PARENTHESIS)
		tokens->content = build_ast(tokens->content);
	return ((t_ast*)tokens);
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
