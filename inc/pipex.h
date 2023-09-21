/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 15:47:25 by cdumais           #+#    #+#             */
/*   Updated: 2023/09/21 15:51:11 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/inc/libft.h"
# include <errno.h>
# include <sys/wait.h>

# define USAGE		"Usage: ./pipex file1 cmd1 cmd2 file2\n"
# define USAGE_B	"Usage: ./pipex file1 cmd1 cmd2 ... cmdn file2\n"

/* path.c */

t_list	*get_path_lst(char **envp);
void	execute_cmd(char *arg, t_list *path_lst);

/* pipex.c */

void	pipex(int argc, char **argv, t_list *path_lst);

/* utils.c */

int		open_flag(char *file, char *flag);
void	validate_files(char *infile, char *outfile);

#endif
