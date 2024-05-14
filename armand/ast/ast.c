#include "ast.h"
#include "../tokenize/libft/libft.h"
#include <stdlib.h>

// Ajouter messages erreur de parsing
int	check_format(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens)
	{
		if (i % 2 && tokens->type != SEPARATOR)
			return (0);
		else if (i % 2 == 0 && tokens->type == SEPARATOR)
			return (0);
		tokens = tokens->next;
		++i;
	}
	return (1);
}

t_ast	*clear_ast(t_ast *ast)
{
	if (!ast)
		return (NULL);
	if (ast->type == PARENTHESIS)
		clear_ast(ast->content);
	else if (ast->type == TEXT)
	{
		free(*((char **)ast->content));
		free(ast->content);
		free(ast);
	}
	else
	{
		clear_ast(ast->l);
		clear_ast(ast->r);
		free(ast->content);
		free(ast);
	}
}

static t_token_type	get_sep_type(char *sep)
{
	const char			*seps[] = { "||", "&&", "<<", ">>", "|", "<", ">", 
		NULL };
	const t_token_type	types[] = { N_PIPE, N_AND, N_HEREDOC, N_APPEND, N_PIPE, 
		N_INFILE, N_OUTFILE };
	int					i;

	i = 0;
	while (seps[i])
	{
		if (ft_strncmp(seps[i], sep, ft_strlen(seps[i])) == 0)
			return (types[i]);
		++i;
	}
	return (SEPARATOR);
}

t_ast	*ast(t_token *tokens)
{
	t_token	*next_tok;
	t_token	*last_op;
	int		tok_count;

	last_op = NULL;
	if (!check_format(tokens))
		return ((t_ast *)free_tokens(tokens));
	while (tokens->next)
		tokens = tokens->next;
	while (tokens)
	{
		next_tok = tokens->prev;
		if (tokens->type == SEPARATOR)
		{
			tokens->type = get_sep_type(tokens->content);
			if (last_op)
				tokens->next = last_op;
			last_op = tokens;
		}
		else if (tokens->type == PARENTHESIS)
			tokens->content = ast(tokens->content);
		tokens = next_tok;
	}
	return ((t_ast *)last_op);
}


// a && b && c
// 