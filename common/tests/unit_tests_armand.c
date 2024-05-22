#include "../parser/ast/ast.h"

void	print_tokens(t_token *tokens, int ind);

void	unit_tests_armand(int ac, char **av, char **envp)
{
	t_token	*tok;
	t_ast	*ast;

	(void)envp;
	tok = tokenize(av[ac - 1]);
	print_tokens(tok, 0);
}
