/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:46:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/20 11:27:31 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/

void	push_swap(t_data *stacks)
{
	ft_printf("push swap\n");
	if (stacks->nb_elems > 3 && stacks->nb_elems <= 10)
		algo_4_10(stacks);
	else if (stacks->nb_elems > 10 && stacks->nb_elems <= 100)
		algo_11_100(stacks);
	else
		algo_101(stacks);
}
