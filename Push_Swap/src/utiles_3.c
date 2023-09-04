/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:54:19 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/04 19:57:41 by qbanet           ###   ########.fr       */
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

int	find_place(t_data *stacks, int nbr)
{
	int		i;
	t_stack	*tmp1;
	t_stack	*tmp2;

	i = 0;
	if (nbr > max_stack(&stacks->stack_b) || nbr < min_stack(&stacks->stack_b))
	{
		if (find_index(stacks->stack_b, max_stack(&stacks->stack_b))
			< stacks->sizes.size_a / 2)
			i = find_index(stacks->stack_b, max_stack(&stacks->stack_b));
		else
			i = find_index(stacks->stack_b, max_stack(&stacks->stack_b))
				- stacks->sizes.size_a / 2;
	}
	else
	{
		tmp1 = stacks->stack_b;
		tmp2 = stacks->stack_b->next;
		while ((tmp1->content < nbr || tmp2->content > nbr) && tmp2->next)
		{
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
			i++;
		}
	}
	return (i);
}

int	max_stack(t_stack **stk)
{
	t_stack	*tmp;
	int		max;

	tmp = *stk;
	max = 0;
	while (tmp)
	{
		if (max < tmp->content)
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
		if (min > tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}