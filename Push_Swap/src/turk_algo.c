/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:44:42 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/05 12:12:31 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_to_b(t_data *stacks, t_sizes *sizes);
static int	test_moves(t_data *stacks, int nbr);
static void	make_move(t_data *stacks, int move_count);
static void	return_to_a(t_data *stacks, t_sizes *sizes);

/*----------------------------------------------------------------------------*/

void	turk_algo(t_data *stacks)
{
	accio("pb", stacks);
	accio("pb", stacks);
	stacks->sizes.size_a = stack_size(stacks->stack_a);
	stacks->sizes.size_b = stack_size(stacks->stack_b);
	while (stacks->sizes.size_a > 3 || !is_sort(&stacks->stack_a))
		sort_to_b(stacks, &stacks->sizes);
	if (stacks->sizes.size_a == 3 && !is_sort(&stacks->stack_a))
		algo_3(stacks);
	return_to_a(stacks, &stacks->sizes);
}

static void	sort_to_b(t_data *stacks, t_sizes *sizes)
{
	int		moves;
	t_stack	*tmp;
	int		i;

	moves = test_moves(stacks, stacks->stack_a->content);
	i = 1;
	tmp = stacks->stack_a->next;
	while (tmp && i < moves)
	{
		if (test_moves(stacks, tmp->content) < moves)
			moves = test_moves(stacks, tmp->content);
		tmp = tmp->next;
		i++;
	}
	make_move(stacks, moves);
	sizes->size_a --;
	sizes->size_b ++;
}

static int	test_moves(t_data *stacks, int nbr)
{
	int	i;

	i = 1;
	if (find_index(stacks->stack_a, nbr) < stacks->sizes.size_a / 2)
		i += find_index(stacks->stack_a, nbr);
	else
		i += find_index(stacks->stack_a, nbr) - stacks->sizes.size_a / 2;
	i += find_place(stacks, nbr);
	return (i);
}

static void	make_move(t_data *stacks, int move_count)
{
	int	i;

	i = 0;
	while (i < move_count)
	{
		i++;
	}
	return (accio("pb", stacks));
}

static void	return_to_a(t_data *stacks, t_sizes *sizes)
{
	while (sizes->size_b--)
		accio("pa", stacks);
}