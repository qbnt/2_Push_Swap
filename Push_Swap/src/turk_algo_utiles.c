/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/07 16:57:23 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	double_rotate(int *a_index, int *b_index, t_data *stacks);
static void	single_rotate(int *a_index, int *b_index, t_data *stacks);

/*----------------------------------------------------------------------------*/

int	test_moves(t_data *stacks, int nbr)
{
	int	moves_a;
	int	moves_b;

	if (find_index(stacks->stack_a, nbr) < stacks->sizes.size_a / 2)
		moves_a = find_index(stacks->stack_a, nbr);
	else
		moves_a = stacks->sizes.size_a - find_index(stacks->stack_a, nbr);
	if (find_place(stacks->stack_b, nbr) < stacks->sizes.size_b / 2)
		moves_b = find_place(stacks->stack_b, nbr);
	else
		moves_b = stacks->sizes.size_b - find_place(stacks->stack_b, nbr);
//	printf("moves a = %d, moves b = %d\n", moves_a, moves_b);
	return (moves_a + moves_b);
}

int	find_place(t_stack *stk, int nbr)
{
	int		i;
	t_stack	*tmp1;
	t_stack	*tmp2;

	i = 0;
	tmp1 = stk;
	tmp2 = stk->next;
	if (nbr > stk->content && nbr < last_elem_stack(stk)->content)
		return (0);
	else if (nbr > max_stack(&stk) || nbr < min_stack(&stk))
	{
		return (find_index(stk, max_stack(&stk)));
	}
	else
	{
		while (tmp2->next)
		{
			if (tmp1->content > nbr && tmp2->content < nbr)
				return (++ i);
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
			i ++;
		}
	}
	return (i);
}

void	place_stacks_elems(int a_index, int b_index, t_data *stacks)
{
//	printf("a index = %d, b index = %d\n", a_index, b_index);
	while (a_index || b_index)
	{
		if (a_index && b_index)
			double_rotate(&a_index, &b_index, stacks);
		else
			single_rotate(&a_index, &b_index, stacks);
	}
}

static void	double_rotate(int *a_index, int *b_index, t_data *stacks)
{
	if (*a_index < stacks->sizes.size_a / 2
		&& *b_index < stacks->sizes.size_b / 2)
		return (*a_index -= 1, *b_index -= 1, accio("rr", stacks));
	else if (*a_index > stacks->sizes.size_a / 2
		&& *b_index > stacks->sizes.size_b / 2)
	{
		if (++ *a_index >= stacks->sizes.size_a)
			*a_index = 0;
		if (++ *b_index >= stacks->sizes.size_b)
			*b_index = 0;
		return (accio("rrr", stacks));
	}
	else if (*a_index > stacks->sizes.size_a / 2
		&& *b_index < stacks->sizes.size_b / 2)
	{
		if (++ *a_index >= stacks->sizes.size_a)
			*a_index = 0;
		accio("rra", stacks);
		return (*b_index -= 1, accio("rb", stacks));
	}
	else if (*a_index < stacks->sizes.size_a / 2
		&& *b_index > stacks->sizes.size_b / 2)
	{
		accio("ra", stacks);
		if (++ *b_index >= stacks->sizes.size_b)
			*b_index = 0;
		return (accio("rrb", stacks));
	}
}

static void	single_rotate(int *a_index, int *b_index, t_data *stacks)
{
	if (*a_index)
	{
		if (*a_index <= stacks->sizes.size_a / 2)
		{
			accio("ra", stacks);
			*a_index -= 1;
		}
		else
		{
			accio("rra", stacks);
			if (++ *a_index >= stacks->sizes.size_a)
				*a_index = 0;
		}
	}
	else if (*b_index)
	{
		if (*b_index <= stacks->sizes.size_b / 2)
		{
			accio("rb", stacks);
			*b_index -= 1;
		}
		else
		{
			accio("rrb", stacks);
			if (++ *b_index >= stacks->sizes.size_b)
				*b_index = 0;
		}
	}
}