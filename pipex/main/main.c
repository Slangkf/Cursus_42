/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 11:04:00 by tclouet           #+#    #+#             */
/*   Updated: 2025/03/05 11:04:01 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static void	child_process1(char **argv, char **envp, int *pipe_fd)
{
	int		infile_fd;

	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
		ft_print_error();
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
		ft_print_error();
	close(pipe_fd[0]);
	if (!argv[2][0])
	{
		read_from_infile(infile_fd, pipe_fd[1]);
		close(infile_fd);
		close(pipe_fd[1]);
		exit(0);
	}
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		ft_print_error();
	close(pipe_fd[1]);
	close(infile_fd);
	execute_cmd(argv[2], envp);
}

static void	child_process2(char **argv, char **envp, int *pipe_fd)
{
	int		outfile_fd;

	outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile_fd == -1)
		ft_print_error();
	if (!argv[3][0])
	{
		if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
			ft_print_error();
		if (dup2(outfile_fd, STDOUT_FILENO) == -1)
			ft_print_error();
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(outfile_fd);
		read_from_stdin(STDIN_FILENO, STDOUT_FILENO);
		exit(0);
	}
	if (dup2(pipe_fd[0], STDIN_FILENO) == -1)
		ft_print_error();
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
		ft_print_error();
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(outfile_fd);
	execute_cmd(argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		return (write(2, "Wrong argument(s)\n", 18));
	if (pipe(pipe_fd) == -1)
		ft_print_error();
	pid1 = fork();
	if (pid1 == -1)
		ft_print_error();
	if (pid1 == 0)
		child_process1(argv, envp, pipe_fd);
	pid2 = fork();
	if (pid2 == -1)
		ft_print_error();
	if (pid2 == 0)
		child_process2(argv, envp, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
