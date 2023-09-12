/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:54:19 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/12 15:13:26 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*----------------------------------------------------------------------------*/

int	find_index(t_stack *stk, int content)
{
	int		i;

	i = 0;
	while (stk->content != content)
	{
		i++;
		stk = stk->next;
	}
	return (i);
}

int	max_stack(t_stack **stk)
{
	t_stack	*tmp;
	int		max;

	tmp = *stk;
	max = tmp->content;
	while (tmp)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	min_stack(t_stack **stk)
{
	t_stack	*tmp;
	int		min;

	tmp = *stk;
	min = tmp->content;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

void	divided_algo(t_data *stacks)
{
	stacks->min = min_stack(&stacks->stack_a);
	if (find_index(stacks->stack_a, stacks->min) <= stacks->sizes.size_a / 2)
		while (stacks->stack_a->content != stacks->min)
			accio("ra", stacks);
	else
		while (stacks->stack_a->content != stacks->min)
			accio("rra", stacks);
	accio("pb", stacks);
	stacks->sizes.size_a = stack_size(stacks->stack_a);
	stacks->sizes.size_b = stack_size(stacks->stack_b);
}
