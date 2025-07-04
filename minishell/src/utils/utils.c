/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:09:57 by seruff            #+#    #+#             */
/*   Updated: 2025/05/21 11:24:14 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_is_operator(char c)
{
	return (c == '|' || c == '>' || c == '<');
}

int	position_carac(char *line, char c, int i)
{
	while (line[i])
	{
		if (line[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*remove_quotes(char *s)
{
	int		i;
	char	*d;

	i = 0;
	d = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!d)
		return (NULL);
	while (s[i])
	{
		while (s[i] != '"')
		{
			d[i] = s[i];
			i++;
		}
		if (s[i] == '"')
			i++;
	}
	free(s);
	return (d);
}

int	empty_string(char *line)
{
	int	i;

	i = 0;
	if (!line || ft_strlen(line) == 0)
		return (0);
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (1);
		i++;
	}
	return (0);
}

int	verif(char *line)
{
	bool	single_q;
	bool	double_q;

	single_q = false;
	double_q = false;
	while (*line)
	{
		if (*line == '"')
		{
			if (!single_q)
				double_q = !double_q;
		}
		else if (*line == '\'')
		{
			if (!double_q)
				single_q = !single_q;
		}
		line++;
	}
	if (double_q || single_q)
	{
		write(2, "Unclosed quote\n", 15);
		return (1);
	}
	return (0);
}
