/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 19:47:04 by mekherbo          #+#    #+#             */
/*   Updated: 2024/08/21 22:12:28 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	err_export(char *arg, int flag)
{
	if (flag == 1)
	{
		ft_putstr_fd("bash: export: `", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("`: not a valid identifier\n", 2);
		g_exit_status = 1;
	}
	else
	{
		ft_putstr_fd("bash: export: `", 2);
		write(2, arg, 2);
		ft_putstr_fd("`: invalid option\n", 2);
		g_exit_status = 2;
	}
	free(arg);
	return (false);
}

static bool	parse_key(char *value, int *join)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = -1;
	line = get_key(value);
	if (!line)
		return (false);
	if (line[0] == '-' && line[1])
		return (err_export(line, 0));
	while (line[++j])
		if (line[j] != '_' && !ft_isalpha(line[j]))
			return (err_export(line, 1));
	while (line[++i])
	{
		if (!ft_isalnum(line[i]) && line[i] != '_')
			return (free(line), false);
		if (line[i] == '+' && !line[i + 1])
			return (free(line), *join = 1, true);
	}
	return (free(line), true);
}

static void	parse_export(t_global *mini_s, char *value)
{
	char	*key;
	char	*tmp;
	int		join;

	free((join = 0, key = NULL, NULL));
	if (!parse_key(value, &join))
		return ;
	if (join)
		concat_env(&mini_s->env, value);
	else
	{
		key = get_key(value);
		if (search_in_env(mini_s->env, key))
		{
			tmp = get_value_search(mini_s->env, key);
			if (!tmp)
				replace_env(mini_s->env, value);
			free(tmp);
		}
		else
			addback_env(&mini_s->env, first_node(value));
		if (!ft_strncmp("PATH", key, 5))
		{
			free_matrix(mini_s->envp);
			mini_s->envp = new_matrix(mini_s->env);
		}
		free(key);
	}
}

void	print_export_env(t_env_var *env)
{
	t_env_var	*tmp;

	tmp = env;
	while (tmp)
	{
		if (tmp->content != NULL && ft_strncmp(tmp->key, "?", 1))
			printf("export %s=\%s\n", tmp->key, tmp->content);
		else
			printf("export %s\n", tmp->key);
		tmp = tmp->next;
	}
}

void	ft_export(t_global *mini_s, char **tab)
{
	int	i;

	i = 0;
	g_exit_status = 0;
	if (!tab[1])
	{
		print_export_env(mini_s->env);
		return ;
	}
	while (tab[++i])
		parse_export(mini_s, tab[i]);
}
