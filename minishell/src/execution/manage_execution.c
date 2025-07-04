/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_execution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 13:00:53 by tclouet           #+#    #+#             */
/*   Updated: 2025/07/02 11:48:24 by seruff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	no_cmd(t_shell *shell)
{
	ft_manage_heredoc_no_pipe(shell);
	ft_manage_redirections(shell);
}

static void	hard_builtin(t_shell *shell)
{
	int			i;
	t_command	*current;

	i = 0;
	current = shell->cmds;
	ft_manage_heredoc_no_pipe(shell);
	ft_manage_redirections(shell);
	if (shell->error != 130 && shell->error != 1)
		ft_hard_builtin(shell, shell->cmds->args);
}

void	ft_manage_execution(t_shell *shell)
{
	if (!ft_check_pipe(shell->tok->types))
	{
		if (!shell->cmds->args[0])
			no_cmd(shell);
		else if (ft_is_builtin(shell->cmds->args[0]) == 1)
			hard_builtin(shell);
		else
		{
			if (ft_manage_heredoc_in_pipe(shell))
				return ;
			ft_new_pipex(shell);
		}
	}
	else
	{
		if (ft_manage_heredoc_in_pipe(shell))
			return ;
		ft_new_pipex(shell);
	}
	if (shell->error == 131)
		write(2, "Quit (core dumped)\n", 19);
	g_signal = 0;
}
