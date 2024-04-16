#ifndef AST_H
# define AST_H

typedef enum	e_node_type {
	ROOT,
	AND,
	OR,
	PARENTHESIS,
	
}	t_node_type;

typedef struct	s_ast_node {
	struct s_ast_node	*l;
	struct s_ast_node	*r;
	t_node_type			type;
	char				**data;
}	t_ast_node;

#endif
