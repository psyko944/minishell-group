/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:47:04 by mekherbo          #+#    #+#             */
/*   Updated: 2024/06/21 21:42:44 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool parse_key(char *value)
{
	int i;
	char *line;

	i = 0;
	line = get_key(value);
	if (!line)
		return (false);
	if (line[0] != '_' && !ft_isalpha(line[0]))
		return (free(line), false);
	while (line[++i])
	{
		if (!ft_isalnum(line[i]) && line[i] != '_')
			return (free(line), false);
		if (line[i] == '+' && !line[i + 1])
			break;
	}
	return (free(line), true);
}

static bool parse_value(char *value)
{
	int i;
	char *line;

	i = -1;
	line = get_value(value);
	if (!line)
		return (true);
	while (line[++i])
	{
		if (!ft_isalpha(line[i]) && line[i] != ' ' && line[i] != '-')
			return (free(line), false);
	}
	free(line);
	return (true);
}

static void parse_export(t_env_var *env, char *value)
{
	if (!parse_key(value) || !parse_value(value))
		return ;
	addback_env(&env, first_node(value));
}
// static void check_back()

void print_export_env(t_env_var *env)
{
	size_t i;
	t_env_var *tmp;

	tmp = env;
	i = 0;
	while (tmp)
	{
		if (tmp->content != NULL && ft_strncmp(tmp->key, "?", 1))
			printf("declare -x %s=\"%s\"\n", tmp->key, tmp->content);
		else
			printf("declare -x %s=''\n", tmp->key);
		tmp = tmp->next;
	}
}

void ft_export(t_global *mini_s, char **tab)
{
	int i;

	i = 0;
	if (!tab[1])
	{
		print_export_env(mini_s->env);
		return;
	}
	 while (tab[++i])
		parse_export(mini_s->env, tab[i]);
}