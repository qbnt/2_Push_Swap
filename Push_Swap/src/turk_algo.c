/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:44:42 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/13 12:02:42 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_to_b(t_data *stacks);
static void	back_divided(t_data *stacks);
static void	return_to_a(t_data *stacks);

/*----------------------------------------------------------------------------*/

void	turk_algo(t_data *stacks)
{
	if (!is_sort(&stacks->stack_a) && stack_size(stacks->stack_a) > 3)
		accio("pb", stacks);
	if (!is_sort(&stacks->stack_a) && stack_size(stacks->stack_a) > 3)
		accio("pb", stacks);
	stacks->sizes.size_a = stack_size(stacks->stack_a);
	stacks->sizes.size_b = stack_size(stacks->stack_b);
	while (stacks->sizes.size_a > stacks->size_divided)
		sort_to_b(stacks);
	stacks->max = max_stack(&stacks->stack_b);
	stacks->min = min_stack(&stacks->stack_a);
	if (find_index(stacks->stack_b, stacks->max) <= stacks->sizes.size_b / 2)
	{
		if (stacks->stack_a->content != stacks->min
			&& find_index(stacks->stack_a, stacks->min)
			<= stacks->sizes.size_a / 2)
			while (stacks->stack_b->content != stacks->max)
				accio("rr", stacks);
		else
			while (stacks->stack_b->content != stacks->max)
				accio("rb", stacks);
	}
	else
	{
		if (stacks->stack_a->content != stacks->min
			&& find_index(stacks->stack_a, stacks->min)
			> stacks->sizes.size_a / 2)
			while (stacks->stack_b->content != stacks->max)
				accio("rrr", stacks);
		else
			while (stacks->stack_b->content != stacks->max)
				accio("rrb", stacks);
	}
	while (stacks->sizes.size_a > 3)
		divided_algo(stacks);
	algo_3(stacks);
	back_divided(stacks);
	return_to_a(stacks);
}

static void	sort_to_b(t_data *stacks)
{
	int		i;
	int		moves;
	t_stack	*tmp1;
	t_stack	*tmp2;

	i = 0;
	tmp1 = stacks->stack_a->next;
	tmp2 = last_elem_stack(stacks->stack_a);
	moves = test_moves(stacks, stacks->stack_a->content);
	stacks->a_index = find_index(stacks->stack_a, stacks->stack_a->content);
	stacks->b_index = find_place(stacks->stack_b, stacks->stack_a->content);
	while (i < moves && tmp1)
	{
		test_sort_b(stacks, &moves, tmp1, tmp2);
		tmp1 = tmp1->next;
		tmp2 = tmp2->prev;
		i ++;
	}
	place_stacks_elems(stacks->a_index, stacks->b_index, stacks);
	stacks->sizes.size_a = stack_size(stacks->stack_a);
	stacks->sizes.size_b = stack_size(stacks->stack_b);
}

void	test_sort_b(t_data *stacks, int *moves, t_stack *tmp1, t_stack *tmp2)
{
	if (test_moves(stacks, tmp1->content) < *moves)
	{
		stacks->a_index = find_index(stacks->stack_a, tmp1->content);
		stacks->b_index = find_place(stacks->stack_b, tmp1->content);
		*moves = test_moves(stacks, tmp1->content);
	}
	if (test_moves(stacks, tmp2->content) < *moves)
	{
		stacks->a_index = find_index(stacks->stack_a, tmp2->content);
		stacks->b_index = find_place(stacks->stack_b, tmp2->content);
		*moves = test_moves(stacks, tmp2->content);
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
	stacks->max = max_stack(&stacks->stack_b);
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
		{
			accio("pa", stacks);
		}
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
		accio("rra", stacks);
}
