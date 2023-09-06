/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:44:42 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/06 11:58:01 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_to_b(t_data *stacks);
static int	test_moves(t_data *stacks, int nbr);
static void	make_move(t_data *stacks);
static void	return_to_a(t_data *stacks, t_sizes *sizes);

/*----------------------------------------------------------------------------*/

void	turk_algo(t_data *stacks)
{
	accio("pb", stacks);
	accio("pb", stacks);
	TEST ;
	stacks->sizes.size_a = stack_size(stacks->stack_a);
	stacks->sizes.size_b = stack_size(stacks->stack_b);
	while (stacks->sizes.size_a > 3)
		sort_to_b(stacks);
	algo_3(stacks);
	return_to_a(stacks, &stacks->sizes);
}

static void	sort_to_b(t_data *stacks)
{
	int		moves;
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		i;

	moves = test_moves(stacks, stacks->stack_a->content);
	i = 0;
	tmp1 = stacks->stack_a->next;
	tmp2 = last_elem_stack(stacks->stack_a);
	while (i < moves)
	{
		if (test_moves(stacks, tmp1->content) < moves)
		{
			moves = test_moves(stacks, tmp1->content);
			stacks->a_index = ;
			stacks->b_index = ;
		}
		if (test_moves(stacks, tmp2->content) < moves)
		{
			moves = test_moves(stacks, tmp2->content);
			stacks->a_index = ;
			stacks->b_index = ;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp2->prev;
		i++;
	}
	printf("a index = %d et b index = %d\n", stacks->a_index, stacks->b_index);
	make_move(stacks);
	stacks->sizes.size_a --;
	stacks->sizes.size_b ++;
	TEST ;
}

static int	test_moves(t_data *stacks, int nbr)
{
	int	moves_a;
	int	moves_b;

	moves_a = 0;
	if (find_index(stacks->stack_a, nbr) < stacks->sizes.size_a / 2)
		moves_a = find_index(stacks->stack_a, nbr);
	else
		moves_a = stacks->sizes.size_a - find_index(stacks->stack_a, nbr);
	if (find_place(stacks->stack_b, nbr) < stacks->sizes.size_b / 2)
		moves_b = find_place(stacks, nbr);
	else
		moves_b = stacks->sizes.size_b - find_place(stacks, nbr);
	return (moves_a + moves_b);
}

static void	make_move(t_data *stacks)
{
	place_stacks_elems(stacks->a_index, stacks->b_index, stacks);
	return (accio("pb", stacks));
}

static void	return_to_a(t_data *stacks, t_sizes *sizes)
{
	while (sizes->size_b)
		accio("pa", stacks);
	stacks->sizes.size_a ++;
	stacks->sizes.size_b --;
}
