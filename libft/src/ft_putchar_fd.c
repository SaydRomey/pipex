/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:33:10 by cdumais           #+#    #+#             */
/*   Updated: 2023/09/07 01:12:03 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/* 
writes a char to a file descriptor
returns the number of bytes written
*/
size_t	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
