/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:52:10 by tclouet           #+#    #+#             */
/*   Updated: 2025/03/11 15:52:11 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	execute_cmd(char *argv, char **envp)
{
	char	**cmd;
	char	*good_path;

	cmd = ft_split(argv, ' ');
	if (!cmd[0] || !cmd)
	{
		ft_free_all(cmd);
		exit(0);
	}
	good_path = ft_find_good_path(cmd[0], envp);
	if (!good_path)
	{
		ft_free_all(cmd);
		ft_print_error();
	}
	if (execve(good_path, cmd, envp) == -1)
	{
		ft_free_all(cmd);
		ft_print_error();
	}
}

char	*ft_find_good_path(char *argv, char **envp)
{
	int		i;
	char	**paths;
	char	*temp;
	char	*complete_path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		complete_path = ft_strjoin(temp, argv);
		free(temp);
		if (access(complete_path, F_OK) == 0)
		{
			ft_free_all(paths);
			return (complete_path);
		}
		free(complete_path);
		i++;
	}
	ft_free_all(paths);
	return (NULL);
}

void	ft_print_error(void)
{
	perror("Error");
	exit(1);
}

void	ft_free_all(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
}
