/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:54:19 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/04 15:08:28 by qbanet           ###   ########.fr       */
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
	int	i;

	i = 0;
	if (nbr > stacks->stack_b->content
		&& nbr < last_elem_stack(stacks->stack_b)->content)
		i = 0;
	else if (nbr > max_stack(stacks->stack_b)
		|| nbr < min_stack(stacks->stack_b))
		i = ft_find_index(stacks->stack_b, max_stack(stacks->stack_b));
	else
		
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
	min = 0;
	while (tmp)
	{
		if (min < tmp->content)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}