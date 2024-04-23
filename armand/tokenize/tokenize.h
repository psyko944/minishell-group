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

t_token	*get_parenthesis(const char **s_ptr);
t_token	*get_word(const char **s);
t_token	*new_token(t_token_type type, void *content);
char	**cut_command(char *s);
int	skip_quote(const char *s);

t_token	*tokenize(const char *s);
t_token	*free_tokens(t_token *t);

#endif
