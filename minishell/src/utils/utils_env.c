/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:10:36 by seruff            #+#    #+#             */
/*   Updated: 2025/06/24 15:56:37 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// return (-1) if s isn't included into arr_env;
// Otherwise return is position into arr_env
int	give_env_pos(char **arr_env, char *s)
{
	int		i;
	char	*d;

	i = 0;
	if (!arr_env || !s)
		return (-1);
	d = ft_strjoin(s, "=");
	if (!d)
		return (-1);
	while (i < ft_array_len(arr_env))
	{
		if (!ft_strncmp(d, arr_env[i], ft_strlen(d)))
			return (free(d), i);
		i++;
	}
	free(d);
	return (-1);
}

int	check_key_env(char *s)
{
	int	i;

	i = 0;
	if (ft_isalpha(s[i]) == 0 && s[i] != '_')
		return (0);
	i++;
	while (s[i] && s[i] != '=')
	{
		if (ft_isalnum(s[i]) == 0 && s[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

int	size_env_value(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!line)
		return (-1);
	while (line[i] != '=')
		i++;
	if (line[i] == '=')
		i++;
	while (line[i])
	{
		len++;
		i++;
	}
	return (len);
}

char	*give_env_value(char **arr_env, char *s)
{
	int		i;
	int		pos;
	char	*d;
	char	*res;

	i = 0;
	d = ft_strjoin(s, "=");
	if (!d)
		return (NULL);
	while (arr_env[i])
	{
		if (!ft_strncmp(d, arr_env[i], ft_strlen(d)))
		{
			pos = position_carac(arr_env[i], '=', 0);
			res = ft_substr(arr_env[i], pos + 1, size_env_value(arr_env[i]));
			if (!res)
				return (free(d), NULL);
			return (free(d), res);
		}
		i++;
	}
	return (free(d), NULL);
}
