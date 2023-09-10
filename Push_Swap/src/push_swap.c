/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:46:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/10 16:03:43 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/

void	push_swap(t_data *stacks)
{
	if (is_sort(&stacks->stack_a))
		return ;
	else if (stacks->sizes.size_a == 2
		&& stacks->stack_a->content
		> stacks->stack_a->next->content)
		return (accio("sa", stacks));
	else if (stacks->sizes.size_a == 3)
		return (algo_3(stacks));
	stacks->size_divided = (stack_size(stacks->stack_a) / 100) * 6;
	if (stacks->size_divided < 3)
		stacks->size_divided = 3;
	stacks->max = max_stack(&stacks->stack_a);
	stacks->min = min_stack(&stacks->stack_a);
	return (turk_algo(stacks));
}
