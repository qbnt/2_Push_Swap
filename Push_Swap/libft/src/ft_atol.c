/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:55:20 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/14 12:26:09 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_l	ft_atol(const char *str)
{
	t_l	nbr;
	t_l	sign;

	sign = 1;
	nbr = 0;
	while ((*str >= '\a' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign *= -1;
		str++;
	}
	else if (*str == '+')
		str ++;
	while (*str >= '0' && *str <= '9')
		nbr = (((long)*str++ - 48) + nbr * 10);
	return (nbr * sign);
}
