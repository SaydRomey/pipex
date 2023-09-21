/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:40:35 by cdumais           #+#    #+#             */
/*   Updated: 2023/09/21 15:50:40 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static char	**split_path(char **envp)
{
	int		i;
	char	*envp_path;
	char	**path_array;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strnstr(envp[i], "PATH", 4))
		{
			envp_path = ft_substr(envp[i], ft_strlen("PATH="),
					ft_strlen(envp[i]));
			path_array = ft_split(envp_path, ':');
			free(envp_path);
			return (path_array);
		}
		i++;
	}
	return (NULL);
}

t_list	*get_path_lst(char **envp)
{
	char	**path_array;
	t_list	*path_lst;
	t_list	*new_node;
	int		i;

	path_lst = NULL;
	path_array = split_path(envp);
	if (path_array)
	{
		i = 0;
		while (path_array[i] != NULL)
		{
			new_node = ft_lstnew(ft_strdup(path_array[i]));
			ft_lstadd_back(&path_lst, new_node);
			i++;
		}
		free_split(path_array);
		return (path_lst);
	}
	return (NULL);
}

char	*get_cmd_path(const char *cmd, t_list *path_lst)
{
	char	*possible_path;
	char	*full_cmd_path;

	while (path_lst)
	{
		possible_path = ft_strjoin(path_lst->content, "/");
		full_cmd_path = ft_strjoin(possible_path, cmd);
		free(possible_path);
		if (access(full_cmd_path, F_OK) == 0)
			return (full_cmd_path);
		free(full_cmd_path);
		path_lst = path_lst->next;
	}
	return (NULL);
}

void	execute_cmd(char *arg, t_list *path_lst)
{
	char	**cmd_tokens;
	char	*cmd;
	char	*path;

	cmd_tokens = ft_split(arg, ' ');
	cmd = cmd_tokens[0];
	path = get_cmd_path(cmd, path_lst);
	if (!path)
	{
		ft_fprintf(FD_ERROR, "Error: command not found: %s\n", cmd);
		free_split(cmd_tokens);
		ft_lstclear(&path_lst, free);
		exit(FAILURE);
	}
	if (execve(path, cmd_tokens, NULL) == ERROR)
	{
		ft_fprintf(FD_ERROR, "Error executing program: %s\n", strerror(errno));
		free_split(cmd_tokens);
		ft_lstclear(&path_lst, free);
		exit(FAILURE);
	}
}
