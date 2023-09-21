/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:54:57 by cdumais           #+#    #+#             */
/*   Updated: 2023/09/21 15:50:13 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/*
Bonus version
*/
int	main(int argc, char **argv, char **envp)
{
	t_list	*path_lst;

	if (argc < 5)
		return (ft_fprintf(FD_ERROR, USAGE_B), FAILURE);
	validate_files(argv[1], argv[argc - 1]);
	path_lst = get_path_lst(envp);
	if (!path_lst)
		exit_error("Error: PATH not found in envp");
	pipex(argc, argv, path_lst);
	ft_lstclear(&path_lst, free);
	return (SUCCESS);
}
