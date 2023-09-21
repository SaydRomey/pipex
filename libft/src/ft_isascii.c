/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 10:47:18 by cdumais           #+#    #+#             */
/*   Updated: 2023/08/23 11:01:10 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_isascii(int c)
{
	if (c >= '\0' && c <= 127)
		return (TRUE);
	else
		return (FALSE);
}

/*
int	ft_isascii(int c)
{
	return (c >= '\0' && c <= 0177);
}
*/
