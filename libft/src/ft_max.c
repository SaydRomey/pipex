/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdumais <cdumais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:12:52 by cdumais           #+#    #+#             */
/*   Updated: 2023/09/19 14:58:40 by cdumais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_max(int this, int that)
{
	if (this > that)
		return (this);
	else
		return (that);
}

// #define MAX(a, b) (a > b ? a : b)