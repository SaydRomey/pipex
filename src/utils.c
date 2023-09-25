/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:42:58 by cdumais           #+#    #+#             */
/*   Updated: 2023/09/21 15:52:31 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

int	open_flag(char *file, char *o_flag)
{
	int	fd;

	if (ft_strncmp(o_flag, "infile", 1) == SAME)
		fd = open(file, READ);
	else if (ft_strncmp(o_flag, "outfile", 1) == SAME)
		fd = open(file, CREATE | READ_WRITE | TRUNCATE, 0644);
	else if (ft_strncmp(o_flag, "heredoc", 1) == SAME)
		fd = open(file, CREATE | READ_WRITE | APPEND, 0644);
	else
		fd = ERROR;
	return (fd);
}

int	validate_files(char *infile, char *outfile)
{
	int	fd_in;
	int	fd_out;
	int	valid_infile;

	valid_infile = TRUE;
	fd_out = open(outfile, CREATE | READ_WRITE | TRUNCATE, 0644);
	if (fd_out == ERROR)
	{
		ft_fprintf(FD_ERROR, "Pipex: %s: %s\n", strerror(errno), outfile);
		exit(FAILURE);
	}
	close(fd_out);
	fd_in = open(infile, READ);
	if (fd_in == ERROR)
	{
		ft_fprintf(FD_ERROR, "Pipex: %s: %s\n", strerror(errno), infile);
		valid_infile = FALSE;
	}
	else
		close(fd_in);
	return (valid_infile);
}
