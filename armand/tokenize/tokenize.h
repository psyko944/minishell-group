#ifndef _TOKENIZE_H
# define _TOKENIZE_H

typedef enum e_token_type {
	TEXT,
	SEPARATOR,
	PARENTHESIS
}	t_token_type;	

typedef struct s_token {
	t_token_type	type;
	void			*content;
	struct s_token	*next;
}	t_token;

t_token	*tokenize(const char *s);

#endif
