/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:02:42 by cdumais           #+#    #+#             */
/*   Updated: 2023/09/19 17:54:10 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/*
Prints an error message to stderr
and exits the program with EXIT_ERROR
*/
void	exit_error(char *msg)
{
	ft_putendl_fd(msg, FD_ERROR);
	exit(ERROR);
}

/*
Prints an error message to stderr
and exits the program with EXIT_ERROR
(uses variadic arguments)
*/
void	va_exit_error(const char *msg, ...)
{
	va_list	args;

	va_start(args, msg);
	ft_vfprintf(FD_ERROR, msg, args);
	va_end(args);
	ft_putchar_fd('\n', FD_ERROR);
	exit(ERROR);
}

void	exit_perror(const char *msg)
{
	perror(msg);
	exit(ERROR);
}
