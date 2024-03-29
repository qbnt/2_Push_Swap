/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 09:45:05 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/29 14:53:41 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	lendest;
	size_t	lensrc;
	size_t	i;

	if ((!dest || !src) && !size)
		return (0);
	lendest = ft_strlen(dest);
	lensrc = ft_strlen(src);
	i = 0;
	if (lendest >= size)
		return (size + lensrc);
	while (src[i] && i < (size - 1 - lendest))
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[lendest + i] = 0;
	return (lendest + lensrc);
}
