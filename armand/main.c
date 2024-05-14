#include "tokenize/tokenize.h"
#include "ast/ast.h"
#include <stdio.h>

static void	print_double_tab(const char **s)
{
	int i = 0;

	while (s[i])
	{
		printf("Word %d: %s\n", i, s[i]);
		++i;
	}
}

void	ast_print(t_ast *tk)
{
	printf("Node adress: %p type: %d content: ", tk, tk->type);
	if (tk->type == PARENTHESIS)
		printf("parenthesis");
	else if (tk->type == TEXT)
		print_double_tab(tk->content);
	printf("l: %p ", tk->l);
	printf("r: %p", tk->r);
	printf("\n");
	if (tk->l && tk->type != TEXT)
		ast_print(tk->l);
	if (tk->r && tk->type != TEXT)
		ast_print(tk->r);
}

int	main(int ac, char **av)
{
	t_token	*tokens = tokenize(av[ac - 1]);
	t_token	*beg = tokens;
	t_ast	*ast_val;

	while (tokens)
	{
		printf("%p Token type: %d\n", tokens, tokens->type);
		if (tokens->type == TEXT)
			print_double_tab(tokens->content);
		tokens = tokens->next;
	}
	ast_val = ast(beg);
	printf("val: %p\n", ast_val);
	printf("func: %p\n", ast);
	ast_print(ast_val);
	clear_ast(ast_val);
}
