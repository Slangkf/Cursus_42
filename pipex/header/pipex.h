/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclouet <tclouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:01:00 by tclouet           #+#    #+#             */
/*   Updated: 2025/03/04 12:51:17 by tclouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>
# include "../libft/libft.h"

//main
int		main(int argc, char **argv, char **envp);

//utils
int		check_args(char **argv);
char	*ft_find_good_path(char *argv, char **envp);
void	ft_free_all(char **paths);
void	ft_print_error(void);
void	execute_cmd(char *argv, char **envp);
void	read_from_infile(int infile_fd, int pipe_fd);
void	read_from_stdin(int pipe_fd, int outfile);

#endif
