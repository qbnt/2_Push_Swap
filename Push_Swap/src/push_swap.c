/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:46:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/20 16:34:48 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/

void	push_swap(t_data *stacks)
{
	if (stacks->nb_elems == 2
		&& *(int *)stacks->stack_a->content
		> *(int *)stacks->stack_a->next->content)
		return (move_sa(&stacks->stack_a));
	if (stacks->nb_elems == 3)
		algo_3(&stacks->stack_a);
	if (stacks->nb_elems == 5)
		algo_5(stacks);
	else
		main_algo(stacks);
}
