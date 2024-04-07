/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 18:00:55 by mekherbo          #+#    #+#             */
/*   Updated: 2024/03/27 09:10:29 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int	is_quote(char *input)
// {
// 	int	i;

// 	i = 0;
// 	while (input[i])
// 	{
// 		if (input[i] == '"')
// 			return (1);
// 	}
// 	return (0);
// }

// static void	cmd_routine(t_data *data)
// {
// 	int	i;

// 	i = -1;
// 	while (++i)
// 	{
// 		exec_cmd(data->cmd);
// 	}
// 	while (--i)
// 		add_history(data->cmd);
// }

static void choice(char *input)
{
	enum e_link_types choice;	
	
	if (!ft_strncmp(input, "<", 1))
		choice = IN_REDIRECT;
	else if (!ft_strncmp(input, ">", 1))
		choice = OUT_REDIRECT;
	else if (!ft_strncmp(input, "<<", 2))
		choice = HEREDOC;
	else if (!ft_strncmp(input, ">>", 2))
		choice = APPEND;
	else if (!ft_strncmp(input, "|", 1))
		choice = PIPE;
	else if (!ft_strncmp(input, "&&", 2))
		choice = AND_OPERATOR;
	else if (!ft_strncmp(input, "||", 2))
		choice = OR_OPERATOR;
	else
		choice = NONE;
	printf("choice = %d\n", choice);
}

static void	print_env(t_env *env)
{
	t_env *tmp;
	
	tmp = env;
	while (tmp)
	{
		printf("%s\n", tmp->line);
		tmp = tmp->next;
	}
}
int main(int ac, char **av, char **envp)
{
	char *input;
	char **tab;
	char	*path;
	int		i;

	t_env *env;

	env  = get_env(envp);
	path = get_path(envp);
	//printf("Path = %s\n", path);
	//print_env(env);
	(void)ac;
	(void)av;
	while (1)
	{
		i = -1;
		input = readline("$ ");
		if (!input)
		{
			printf("readline error no display prompt\n");
			break ;
		}
		printf("without quotes = %s\n", parse_token(input));
		if (strcmp(input, "clear") == 0)
		{
			printf("clear history\n");
			rl_clear_history();
		}
		else
		{
			add_history(input);
			//printf("you entered : %s\n", input);
			if (strcmp(input, "env") == 0)
			{
				print_env(env);
			}
		}
		tab = ft_split(input, ' ');
		if (!tab)
		{
			free(input);
			break ;
		}
		while (tab[++i])
			choice(tab[i]);
		free(input);
	}
	return (0);
}
