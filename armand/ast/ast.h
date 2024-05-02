#ifndef _AST_H
# define _AST_H

# include "../tokenize/tokenize.h"

typedef struct s_ast {
	t_token_type	type;
	void			*content;
	struct s_ast	*l;
	struct s_ast	*r;
}	t_ast;

#endif
