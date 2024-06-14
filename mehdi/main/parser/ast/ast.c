/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:27:52 by arlarzil          #+#    #+#             */
/*   Updated: 2024/06/14 18:31:07 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ast.h>
#include <stdlib.h>

// Ajouter messages erreur de parsing
int	check_format(t_token *tokens)
{
	int	i;

	if (!tokens)
		return (0);
	i = 0;
	while (tokens->next)
	{
		if (i % 2 && tokens->type != SEPARATOR)
			return (print_parse_err(tokens->content), 0);
		else if (i % 2 == 0 && tokens->type == SEPARATOR)
			return (print_parse_err(tokens->content), 0);
		tokens = tokens->next;
		++i;
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
	else if (ast->type == TEXT)
		free_matrix(ast->content);
	else
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
	}
	else if (tokens->type == PARENTHESIS)
		tokens->content = build_ast(tokens->content);
}

t_ast	*build_ast(t_token *tokens)
{
	t_token	*next_tok;
	t_token	*last_op;

	if (!check_format(tokens))
		return ((t_ast *)free_tokens(tokens));
	last_op = NULL;
	if (!tokens->next)
		return ((t_ast *)tokens);
	while (tokens->next)
		tokens = tokens->next;
	while (tokens)
	{
		next_tok = tokens->prev;
		ast_step(tokens, &last_op);
		tokens = next_tok;
	}
	return ((t_ast *)last_op);
}
