/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 21:54:19 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/05 11:17:23 by qbanet           ###   ########.fr       */
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