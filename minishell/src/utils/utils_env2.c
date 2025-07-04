/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:53:27 by seruff            #+#    #+#             */
/*   Updated: 2025/05/28 12:16:28 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**ft_realloc_env(char **environ)
{
	int		i;
	char	**env;

	i = 0;
	env = ft_calloc(ft_array_len(environ) + 2, sizeof(char *));
	if (!env)
		return (NULL);
	while (environ[i] && i < ft_array_len(environ))
	{
		env[i] = ft_strdup(environ[i]);
		if (!env[i])
			return (ft_free_array(env), NULL);
		i++;
	}
	env[i] = NULL;
	ft_free_array(environ);
	return (env);
}

static char	**ft_realloc_unset_env(char **environ, int element)
{
	int		i;
	int		j;
	char	**env;

	i = 0;
	j = 0;
	env = ft_calloc(ft_array_len(environ) + 1, sizeof(char *));
	if (!env)
		return (NULL);
	while (i < (ft_array_len(environ)) && j < (ft_array_len(environ) - 1))
	{
		if (i != element)
		{
			env[j] = ft_strdup(environ[i]);
			if (!env[j])
				return (ft_free_array(env), NULL);
			j++;
			i++;
		}
		else
			i++;
	}
	env[i] = NULL;
	ft_free_array(environ);
	return (env);
}

int	remove_element_env(t_shell *shell, int element)
{
	if (element > ft_array_len(shell->environ))
		return (1);
	shell->environ = ft_realloc_unset_env(shell->environ, element);
	if (!shell->environ)
		return (1);
	return (0);
}

int	add_element_env(t_shell *shell, char *key, char *value)
{
	int		index;
	char	*tmp;

	index = give_env_pos(shell->environ, key);
	if (!value)
		value = "";
	tmp = ft_strjoin("=", value);
	if (!tmp)
		return (1);
	if (index != -1 && shell->environ[index])
	{
		free(shell->environ[index]);
		shell->environ[index] = ft_strjoin(key, tmp);
	}
	else
	{
		index = ft_array_len(shell->environ);
		shell->environ = ft_realloc_env(shell->environ);
		if (!shell->environ)
			return (1);
		shell->environ[index] = ft_strjoin(key, tmp);
	}
	free(tmp);
	return (0);
}
