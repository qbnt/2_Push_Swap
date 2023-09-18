/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 09:41:48 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/14 15:14:46 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	nbr;
	int	sign;

	sign = 1;
	nbr = 0;
	while ((*str >= '\a' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '-')
	{
		sign *= -1;
		while (*str == '-')
			str++;
	}
	else if (*str == '+')
		while (*str == '+')
			str ++;
	while (*str >= '0' && *str <= '9')
		nbr = (((int)*str++ - 48) + nbr * 10);
	return (nbr * sign);
}
