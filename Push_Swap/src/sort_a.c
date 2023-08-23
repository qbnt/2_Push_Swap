/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:44:42 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/23 19:07:03 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_pivot(t_stack *stk);

/*----------------------------------------------------------------------------*/

void	sort_a(t_data *stacks)
{
	int	pivot;
	int	i;

	i = 0;
	pivot = set_pivot(stacks->stack_a);
	while (i < stacks->nb_elems)
	{
		if (stacks->stack_a->content > pivot)
			accio("pb", stacks);
		else
			accio("ra", stacks);
		i ++;
	}
}

static int	set_pivot(t_stack *stk)
{
	int		piv;
	t_stack	*tmp;

	tmp = last_elem_stack(stk);
	piv = tmp->content;
	return (piv);
}
