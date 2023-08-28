/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:44:42 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/26 23:56:26 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	set_pivot(t_stack **stk);

/*----------------------------------------------------------------------------*/

void	sort_a(t_data *stacks, int nb)
{
	int	pivot;
	int	i;

	if (!nb)
		return ;
	i = 0;
	pivot = set_pivot(&stacks->stack_a);
	while (i < nb)
	{
		if (stacks->stack_a->content < pivot)
			accio("pb", stacks);
		else if (stacks->stack_a->content == pivot)
		{
			accio("pb", stacks);
		}
		else
			accio("ra", stacks);
		i ++;
	}
	sort_a(stacks, nb - 1);
	sort_b(stacks, nb);
}

void	sort_b(t_data *stacks, int nb)
{
	int	pivot;
	int	i;

	if (!nb)
		return ;
	i = 0;
	pivot = set_pivot(&stacks->stack_a);
	while (i < nb)
	{
		if (stacks->stack_b->content < pivot)
			accio("pa", stacks);
		else if (stacks->stack_b->content == pivot)
		{
			accio("pa", stacks);
		}
		else
			accio("rb", stacks);
		i ++;
	}
	sort_b(stacks, nb - 1);
	sort_a(stacks, nb);
}

static int	set_pivot(t_stack **stk)
{
	int		piv;
	t_stack	*tmp;

	tmp = last_elem_stack(*stk);
	piv = tmp->content;
	return (piv);
}
