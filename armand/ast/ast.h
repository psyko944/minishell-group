#ifndef _AST_H
# define _AST_H

# include "../tokenize/tokenize.h"

typedef struct s_ast {
	t_token_type	type;
	void			*content;
	struct s_ast	*l;
	struct s_ast	*r;
}	t_ast;

t_ast	*ast(t_token *tokens);
t_ast	*clear_ast(t_ast *ast);

#endif
