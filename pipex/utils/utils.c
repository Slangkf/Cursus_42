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

int	check_args(char **argv, char **envp)
{
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;

	if (ft_count_sub(argv[2], ' ') < 1 || ft_count_sub(argv[3], ' ') < 1)
		return (1);
	cmd1 = ft_split(argv[2], ' ');
	cmd2 = ft_split(argv[3], ' ');
	path1 = ft_find_good_path(cmd1[0], envp);
	path2 = ft_find_good_path(cmd2[0], envp);
	if (!path1 || !path2)
	{
		free(path1);
		free(path2);
		ft_free_all(cmd1);
		ft_free_all(cmd2);
		return (1);
	}
	free(path1);
	free(path2);
	ft_free_all(cmd1);
	ft_free_all(cmd2);
	return (0);
}

void	execute_cmd(char *argv, char **envp)
{
	char	**cmd;
	char	*good_path;

	cmd = ft_split(argv, ' ');
	if (!cmd)
	{
		ft_free_all(cmd);
		exit(1);
	}
	good_path = ft_find_good_path(cmd[0], envp);
	if (!good_path)
		ft_print_error();
	if (execve(good_path, cmd, envp) == -1)
		ft_print_error();
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
