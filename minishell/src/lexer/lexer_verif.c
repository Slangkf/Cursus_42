/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 11:38:33 by seruff            #+#    #+#             */
/*   Updated: 2025/07/03 12:04:57 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static	int	ft_isdire(char *types)
{
	if (!ft_strcmp(types, "INPUT") || !ft_strcmp(types, "HEREDOC")
		|| !ft_strcmp(types, "OUTPUT") || !ft_strcmp(types, "APPEND"))
		return (0);
	return (1);
}

static	int	wrong_pipes(char **types, char **token)
{
	int	i;

	i = 1;
	if (types[0] && !ft_strcmp(types[0], "T_PIPE"))
		return (2);
	while (types[i] && ft_strcmp(types[i], "END"))
	{
		if (ft_strcmp(types[i], "T_PIPE") == 0)
		{
			if (ft_strlen(token[i]) != 1 || !types[i + 1])
				return (2);
			if (!ft_strcmp(types[i + 1], "T_PIPE"))
				return (2);
			if (ft_isdire(types[i - 1]) == 0)
				return (2);
		}
		i++;
	}
	if (!ft_strcmp(types[i - 1], "T_PIPE"))
		return (2);
	return (0);
}

static	int	wrong_redirection(char **types)
{
	int	i;

	i = 0;
	while (ft_strcmp(types[i], "END"))
	{
		if (ft_strcmp(types[i], "WRONG") == 0
			|| (!ft_strcmp(types[i], "INPUT")
				&& !ft_strcmp(types[i + 1], "OUTPUT")))
			return (-2);
		else if (!ft_isdire(types[i]) && !ft_isdire(types[i + 1]))
			return (i + 1);
		i++;
	}
	return (-1);
}

static int	wrong_newline(char **types)
{
	int	i;

	i = 0;
	while (ft_strcmp(types[i], "END"))
	{
		if (!ft_isdire(types[i]))
		{
			if (ft_strcmp(types[i + 1], "WORD")
				&& ft_strcmp(types[i + 1], "T_PIPE"))
				return (2);
		}
		i++;
	}
	return (0);
}

int	main_lexer_verif(t_shell *shell)
{
	int	ret;

	if (wrong_pipes(shell->tok->types, shell->tok->token) != 0)
	{
		write(2, "bash: syntax error near unexpected token `|'\n", 45);
		return (2);
	}
	ret = wrong_redirection(shell->tok->types);
	if (ret != -2 && ret != -1)
	{
		write(2, "bash: syntax error near unexpected token `", 43);
		write(2, shell->tok->token[ret], ft_strlen(shell->tok->token[ret]));
		write(2, "'\n", 2);
		return (2);
	}
	ret = wrong_newline(shell->tok->types);
	if (ret != 0)
		return (print_syntax_error(shell), 2);
	return (0);
}
