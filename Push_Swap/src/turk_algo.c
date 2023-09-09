/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:44:42 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/09 08:33:09 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_to_b(t_data *stacks);
static void	back_divided(t_data *stacks);
static void	return_to_a(t_data *stacks);

/*----------------------------------------------------------------------------*/

void	turk_algo(t_data *stacks)
{
	stacks->size_divided = (stack_size(stacks->stack_a) / 100) * 6;
	if (stacks->size_divided < 3)
		stacks->size_divided = 3;
	stacks->max = max_stack(&stacks->stack_a);
	stacks->min = min_stack(&stacks->stack_a);
	accio("pb", stacks);
	accio("pb", stacks);
	stacks->sizes.size_a = stack_size(stacks->stack_a);
	stacks->sizes.size_b = stack_size(stacks->stack_b);
	while (stacks->sizes.size_a > 3)
		sort_to_b(stacks);
	algo_3(stacks);
	back_divided(stacks);
	return_to_a(stacks);
}

static void	sort_to_b(t_data *stacks)
{
	int		moves;
	int		i;
	t_stack	*tmp1;
	t_stack	*tmp2;

	moves = test_moves(stacks, stacks->stack_a->content);
	tmp1 = stacks->stack_a;
	tmp2 = last_elem_stack(stacks->stack_a);
	stacks->a_index = find_index(stacks->stack_a, tmp1->content);
	stacks->b_index = find_place(stacks->stack_b, tmp1->content);
	i = 0;
	while (i < moves && tmp1 && tmp2)
	{
		test_sort_b(stacks, &moves, tmp1, tmp2);
		tmp1 = tmp1->next;
		tmp2 = tmp2->prev;
		i ++;
	}
	place_stacks_elems(stacks->a_index, stacks->b_index, stacks);
	stacks->sizes.size_a --;
	stacks->sizes.size_b ++;
}

void	test_sort_b(t_data *stacks, int *moves, t_stack *tmp1, t_stack *tmp2)
{
	if (tmp1 && test_moves(stacks, tmp1->content) < *moves)
	{
		*moves = test_moves(stacks, tmp1->content);
		stacks->a_index = find_index(stacks->stack_a, tmp1->content);
		stacks->b_index = find_place(stacks->stack_b, tmp1->content);
	}
	if (tmp2 && test_moves(stacks, tmp2->content) < *moves)
	{
		*moves = test_moves(stacks, tmp2->content);
		stacks->a_index = find_index(stacks->stack_a, tmp2->content);
		stacks->b_index = find_place(stacks->stack_b, tmp2->content);
	}
}

static void	back_divided(t_data *stacks)
{
	int	i;

	i = 3;
	if (stacks->stack_a->content > stacks->stack_b->content)
	{
		while (stacks->stack_b->content != stacks->max)
			accio("pa", stacks);
	}
	while (stacks->stack_b->content != stacks->max)
	{
		while (i > 0 && last_elem_stack(stacks->stack_a)->content
			> stacks->stack_b->content)
		{
			accio("rra", stacks);
			i--;
		}
		accio("pa", stacks);
	}
	while (last_elem_stack(stacks->stack_a)->content < stacks->stack_a->content)
		accio("rra", stacks);
}

static void	return_to_a(t_data *stacks)
{
	int	i;

	i = stacks->size_divided;
	if (stacks->stack_a->content > stacks->stack_b->content)
	{
		while (stacks->stack_b)
			accio("pa", stacks);
	}
	while (stacks->stack_b)
	{
		while (i > 0 && last_elem_stack(stacks->stack_a)->content
			> stacks->stack_b->content)
		{
			accio("rra", stacks);
			i --;
		}
		accio("pa", stacks);
	}
	while (last_elem_stack(stacks->stack_a)->content < stacks->stack_a->content)
	{
		accio("rra", stacks);
	}
}
