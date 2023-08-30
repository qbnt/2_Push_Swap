/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:44:42 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/30 12:03:32 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_to_b(t_stack *a, t_stack *b, t_sizes *sizes);
static void	return_to_a(t_stack *b, t_stack *a);

/*----------------------------------------------------------------------------*/

void	turk_algo(t_data *stacks)
{

	accio("pb", stacks);
	accio("pb", stacks);
	stacks->sizes.size_a = stack_size(stacks->stack_a);
	stacks->sizes.size_b = stack_size(stacks->stack_b);
	while (stacks->sizes.size_a > 3)
		sort_to_b(stacks->stack_a, stacks->stack_b, &stacks->sizes);
	algo_3(stacks->stack_a);
	return_to_a(stacks->stack_b, stacks->stack_a);
}

static void	sort_to_b(t_stack *a, t_stack *b, t_sizes *sizes)
{
	
}

static void	return_to_a(t_stack *b, t_stack *a)
{
	
}
