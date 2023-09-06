/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/06 11:44:16 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	normal_case(t_data *stacks, int nbr);
static void	double_rotate(int *a_index, int *b_index, t_data *stacks);

/*----------------------------------------------------------------------------*/

int	find_place(t_data *stacks, int nbr)
{
	int		i;

	i = 0;
	if (nbr > max_stack(&stacks->stack_b) || nbr < min_stack(&stacks->stack_b))
			i = find_index(stacks->stack_b, max_stack(&stacks->stack_b));
	else if (nbr > stacks->stack_b->content
		&& nbr < last_elem_stack(stacks->stack_b)->content)
			i = 0;
	else
		i = normal_case(stacks, nbr);
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
	while (!(tmp1->content > nbr && nbr > tmp2->content) && tmp2->next)
	{
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
		i++;
	}
	return (i);
}

void	place_stacks_elems(int a_index, int b_index, t_data *stacks)
{
	while (a_index || b_index)
	{
		if (a_index && b_index)
			double_rotate(&a_index, &b_index, stacks);
		else
		{
			if (a_index)
			{
				accio("ra", stacks);
				a_index --;
			}
			else
			{
				accio("rb", stacks);
				b_index --;
			}
		}
	}
}

static void	double_rotate(int *a_index, int *b_index, t_data *stacks)
{
	if (*a_index-- < stacks->sizes.size_a / 2
		&& *b_index-- < stacks->sizes.size_b / 2)
		return (accio("rr", stacks));
	else if (*a_index++ > stacks->sizes.size_a / 2
		&& *b_index++ > stacks->sizes.size_b / 2)
	{
		return (accio("rrr", stacks));
	}
	else if (*a_index-- > stacks->sizes.size_a / 2
		&& *b_index-- < stacks->sizes.size_b / 2)
	{
		accio("ra", stacks);
		return (accio("rrb", stacks));
	}
	else if (*a_index-- < stacks->sizes.size_a / 2
		&& *b_index-- > stacks->sizes.size_b / 2)
	{
		accio("rra", stacks);
		return (accio("rb", stacks));
	}
}
