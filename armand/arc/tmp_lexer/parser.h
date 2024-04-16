#ifndef _PARSER_H
# define _PARSER_H

typedef struct s_cmd_symbol
{
	char				*content;
	struct s_cmd_symbol	*next;
	struct s_cmd_symbol	*last;
}	t_cmd_symbol;

t_cmd_symbol	*free_parse(t_cmd_symbol *tab);
void			add_back(t_cmd_symbol *new, t_cmd_symbol **dest);
unsigned int	get_len(t_cmd_symbol *list);

typedef struct s_env_var
{
	char				*key;
	char				*content;
	struct s_env_var	*next;
}	t_env_var;

// REDIRECTS are for files
typedef enum	e_link_type
{
	NONE = 0,
	PIPE = 0b00000001,
	IN_REDIRECT = 0b00000010,
	OUT_REDIRECT = 0b00000100,
	HEREDOC = 0b00001000,
	APPEND = 0b00010000,
	AND_OPERATOR = 0b00100000,
	OR_OPERATOR = 0b01000000
}	t_link_type;

t_link_type	get_link_eq(const char *s);

typedef struct s_parsed_cmd
{
	t_link_type			link_prev;
	t_link_type			link_next;
	char				**command;
	struct s_parsed_cmd	*next;
}	t_parsed_cmd;

void	add_block(t_parsed_cmd *new, t_parsed_cmd **list);

typedef struct s_parsed_cmd_cont
{
	t_parsed_cmd	*cont;
	char			**double_tab;
}	t_parsed_cmd_cont;


t_env_var			*parse_env(const char **env);
t_cmd_symbol		*cut_command(const char *str);
void				interpret_command_variables(t_parsed_cmd *cmd, 
	t_env_var *env);
t_parsed_cmd_cont	*parse_command(const char *cmd, t_env_var *env);
t_parsed_cmd	*free_parsed_cmd(t_parsed_cmd_cont *cmd);

typedef enum	e_type {
	FILE,
}	t_type;

typedef struct s_parse_tree	{
	char	**data;
	struct s_parse_tree	*r_node;
	struct s_parse_tree	*l_node;
}	t_parse_tree;







#endif
