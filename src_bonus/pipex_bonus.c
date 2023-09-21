/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:55:52 by cdumais           #+#    #+#             */
/*   Updated: 2023/09/21 15:52:05 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	pipe_error(t_list **path_lst)
{
	perror("pipe");
	ft_lstclear(path_lst, free);
	exit(EXIT_FAILURE);
}

static void	fork_error(int *fd, t_list **path_lst)
{
	perror("fork");
	close(fd[0]);
	close(fd[1]);
	ft_lstclear(path_lst, free);
	exit(EXIT_FAILURE);
}

static void	parent_process(int fd[2], pid_t child_pid)
{
	close(fd[1]);
	dup2(fd[0], FD_INPUT);
	close(fd[0]);
	waitpid(child_pid, NULL, 0);
}

static void	fork_and_execute(char *arg, t_list *path_lst, int fd_in, int fd_out)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == ERROR)
		pipe_error(&path_lst);
	pid = fork();
	if (pid == ERROR)
		fork_error(fd, &path_lst);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], FD_OUTPUT);
		close(fd[1]);
		close(fd_in);
		close(fd_out);
		execute_cmd(arg, path_lst);
	}
	else
		parent_process(fd, pid);
}

void	pipex(int argc, char **argv, t_list *path_lst)
{
	int	i;
	int	fd_in;
	int	fd_out;

	i = 2;
	fd_in = open_flag(argv[1], "infile");
	fd_out = open_flag(argv[argc - 1], "outfile");
	dup2(fd_in, FD_INPUT);
	close(fd_in);
	while (i < argc - 2)
	{
		fork_and_execute(argv[i], path_lst, fd_in, fd_out);
		i++;
	}
	dup2(fd_out, FD_OUTPUT);
	close(fd_out);
	execute_cmd(argv[argc - 2], path_lst);
}
