/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/05 12:03:05 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	new_min_max_case(t_data *stacks);
static int	normal_case(t_data *stacks, int nbr);

/*----------------------------------------------------------------------------*/

int	find_place(t_data *stacks, int nbr)
{
	int		i;

	i = 0;
	if (nbr > max_stack(&stacks->stack_b) || nbr < min_stack(&stacks->stack_b))
		i = new_min_max_case(stacks);
	else if (nbr > stacks->stack_b->content
		&& nbr < last_elem_stack(stacks->stack_b)->content)
		i = 0;
	else
		i = normal_case(stacks, nbr);
	return (i);
}

static int	new_min_max_case(t_data *stacks)
{
	int	i;

	i = 0;
	if (find_index(stacks->stack_b, max_stack(&stacks->stack_b))
		< stacks->sizes.size_a / 2)
		i = find_index(stacks->stack_b, max_stack(&stacks->stack_b));
	else
		i = find_index(stacks->stack_b, max_stack(&stacks->stack_b))
			- stacks->sizes.size_a / 2;
	return (i);
}

static int	normal_case(t_data *stacks, int nbr)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		i;

	tmp1 = stacks->stack_b;
	tmp2 = stacks->stack_b->next;
	i = 0;
	while (!(tmp1->content > nbr && nbr > tmp2->content))
	{
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
		i++;
	}
	if (i < stacks->sizes.size_b / 2)
		return (i);
	else
		return (i - stacks->sizes.size_b / 2);
}
