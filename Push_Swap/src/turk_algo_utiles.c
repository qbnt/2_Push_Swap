/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo_utiles.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:07:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/07 10:56:16 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	double_rotate(int *a_index, int *b_index, t_data *stacks);

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
	printf("___nbr = %d\ntmp1 = %d, tmp2 = %d\n", nbr, tmp1->content,
		tmp2->content);
	if (nbr > stk->content && nbr < last_elem_stack(stk)->content)
	{
		printf("______sorted\n");
		i = 0;
	}
	else if (nbr > max_stack(&stk) || nbr < min_stack(&stk))
	{
		printf("______min = %d max = %d\n", min_stack(&stk), max_stack(&stk));
		i = find_index(stk, max_stack(&stk));
	}
	else
	{
		printf("______autre\n");
		while ((tmp1->content < nbr && tmp2->content > nbr))
		{
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
			i ++;
		}
	}
	printf("______i de b final = %d\n\n", i);
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
	if (*a_index < stacks->sizes.size_a / 2
		&& *b_index < stacks->sizes.size_b / 2)
		return (*a_index -= 1, *b_index -= 1, accio("rr", stacks));
	else if (*a_index > stacks->sizes.size_a / 2
		&& *b_index > stacks->sizes.size_b / 2)
	{
		if (++ *a_index > stacks->sizes.size_a)
			*a_index = 0;
		if (++ *b_index > stacks->sizes.size_b)
			*b_index = 0;
		return (accio("rrr", stacks));
	}
	else if (*a_index > stacks->sizes.size_a / 2
		&& *b_index < stacks->sizes.size_b / 2)
	{
		if (++ *a_index > stacks->sizes.size_a)
			*a_index = 0;
		accio("rra", stacks);
		return (*b_index -= 1, accio("rb", stacks));
	}
	else if (*a_index < stacks->sizes.size_a / 2
		&& *b_index > stacks->sizes.size_b / 2)
	{
		accio("ra", stacks);
		if (++ *b_index > stacks->sizes.size_b)
			*b_index = 0;
		return (accio("rrb", stacks));
	}
}
