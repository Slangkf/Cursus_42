/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seruff <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:16:00 by seruff            #+#    #+#             */
/*   Updated: 2025/06/25 15:11:25 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_quote(char c)
{
	return (c == '"' || c == '\'');
}

int	is_var_start(char c)
{
	return (ft_isalpha((unsigned char)c) || c == '_');
}

int	is_var_char(char c)
{
	return (ft_isalnum((unsigned char)c) || c == '_');
}

char	*append_str(char *res, char *add, int len)
{
	int		old_len;
	char	*new;

	old_len = 0;
	if (res)
		old_len = ft_strlen(res);
	new = malloc(old_len + len + 1);
	if (!new)
		return (free(res), NULL);
	if (res)
		ft_memcpy(new, res, old_len);
	ft_memcpy(new + old_len, add, len);
	new[old_len + len] = '\0';
	return (free(res), new);
}

char	*append_char(char *res, char c)
{
	return (append_str(res, &c, 1));
}
