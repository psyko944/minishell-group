/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mekherbo <mekherbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 08:21:39 by mekherbo          #+#    #+#             */
/*   Updated: 2024/08/01 14:23:53 by mekherbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*get_session(t_env_var *env)
{
	char	*session;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	session = malloc(sizeof(char) * 13);
	if (!session)
		return (NULL);
	tmp = get_value_search(env, "SESSION_MANAGER");
	if (!tmp)
		return (free(session), NULL);
	while (tmp[i] && tmp[i] != '/')
		i++;
	i++;
	if (tmp[i] && (tmp[i] == 'm' || tmp[i] == 'p' || tmp[i] == 'b'))
	{
		while (tmp[i] && tmp[i] != '.')
			session[j++] = tmp[i++];
		session[j] = 0;
		free(tmp);
		return (session);
	}
	(free(tmp), free(session));
	return (NULL);
}

static char	*add_dollars(char *prompt)
{
	char	*final_prompt;

	final_prompt = ft_strjoin2(prompt, "$ ");
	if (!final_prompt)
		return (NULL);
	return (final_prompt);
}

static char	*get_tilde(void)
{
	char	*tilde;
	char	*pwd;

	pwd = get_pwd();
	if (!pwd)
		return (NULL);
	tilde = NULL;
	if (!ft_strncmp("/home/mekherbo", pwd, 14))
		tilde = ft_strjoin("~", pwd + 14);
	else
		return (pwd);
	free(pwd);
	return (tilde);
}

char	*get_prompt(t_env_var *env)
{
	char	*user;
	char	*tmp;
	char	*session;
	char	*pwd;
	char	*final_prompt;

	user = get_value_search(env, "USER");
	session = get_session(env);
	if (!session && user != NULL)
		free(user);
	pwd = get_tilde();
	if (!pwd && session != NULL)
		free(session);
	if (!user || !pwd || !session)
	{
		if (pwd)
			free(pwd);
		return (ft_strdup("minishell$ "));
	}
	tmp = ft_strjoin3(user, "@", session);
	free(session);
	if (!tmp)
		return (free(pwd), ft_strdup("minishell$ "));
	final_prompt = ft_strjoin3(tmp, ":", pwd);
	free(pwd);
	if (!final_prompt)
		return (NULL);
	final_prompt = add_dollars(final_prompt);
	if (!final_prompt)
		return (ft_strdup("minishell$ "));
	return (final_prompt);
}
