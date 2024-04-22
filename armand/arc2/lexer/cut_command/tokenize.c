#include "tokenize.h"
#include "../../libft/libft.h"

#include <stdlib.h>

// Alloc un seul double tab de taille nombre de symboles
// Remplir le double tableau soit avec du texte soit des NULL pour les seps
// Parcourir ce double tab en remplissant notre commande parsée
// Attention 1 seul double pointeur devra être free 

static unsigned int	is_sep(const char *str)
{
	const char		*ops[] = {"|", "<", ">", "<<", ">>", "&&", "||", NULL};
	unsigned int	sep_len;
	unsigned int	i;

	i = 0;
	while (ops[i])
	{
		sep_len = ft_strlen(ops[i]);
		if (ft_strncmp(ops[i], str, sep_len) == 0)
			return (sep_len);
		++i;
	}
	return (0);
}

static char	**create_double_tab(t_cmd_symbol *cmd)
{
	unsigned int	i;
	t_cmd_symbol	*tmp;
	char			**res;

	res = malloc(sizeof(char *) * (get_len(cmd) + 1));
	if (!res)
		return (NULL); // Free cmd
	i = 0;
	while (cmd)
	{
		tmp = cmd->next;
		res[i] = cmd->content;
		free(cmd);
		cmd = tmp;
		++i;
	}
	res[i] = NULL;
	return (res);
}

static t_parsed_cmd	*get_block(char ***tab_index, t_link_type *prev)
{
	t_parsed_cmd	*res;

	res = malloc(sizeof(t_parsed_cmd));
	if (!res)
		return (NULL); // Rien à free cette fois c'est dans add_block
	res->command = *tab_index;
	res->next = NULL;
	res->link_prev = *prev;
	while (**tab_index && !is_sep(**tab_index))
		++(*tab_index);
	res->link_next = get_link_eq(**tab_index); // Trouver le type de link ici
	*prev = res->link_next;
	while (**tab_index && is_sep(**tab_index))
	{
		free(**tab_index);
		**tab_index = NULL;
		++(*tab_index);
	}
	return (res);
}

static t_parsed_cmd_cont	*unite_blocks(t_cmd_symbol *cmd)
{
	
	t_parsed_cmd_cont	*res;
	unsigned int		len;
	char				**double_tab_index;
	t_link_type			link;

	res = malloc(sizeof(t_parsed_cmd_cont));
	if (!res) // Free cmd a ajouter
		return (NULL);
	res->double_tab = create_double_tab(cmd);
	if (!res->double_tab)
		return (free(res), NULL);
	res->cont = NULL;
	double_tab_index = res->double_tab;
	link = NONE;
	while (*double_tab_index)
	{
		add_block(get_block(&double_tab_index, &link), &(res->cont));
		if (!res)
			return (free_parsed_cmd(res), NULL);
	}
	return (res);
}

t_parsed_cmd_cont	*tokenize(const char *cmd)
{
	t_cmd_symbol		*cut;
	t_parsed_cmd_cont	*res;
	
	cut = cut_command(cmd);
	if (!cut)
		return (NULL);
	res = unite_blocks(cut);
	return (res);
}
