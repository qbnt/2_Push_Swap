/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:44:42 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/07 15:12:12 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_to_b(t_data *stacks);
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
	if (!is_sort(&stacks->stack_a))
		algo_3(stacks);
	return_to_a(stacks, &stacks->sizes);
	printf("\n");
	ft_printstk(stacks->stack_a);
}

static void	sort_to_b(t_data *stacks)
{
	int		moves;
	int		i;
	t_stack	*tmp1;
	t_stack	*tmp2;

	ft_printstk(stacks->stack_a);
	printf("\n");
	ft_printstk(stacks->stack_b);
	printf("\n");

	moves = test_moves(stacks, stacks->stack_a->content);
	tmp1 = stacks->stack_a;
	tmp2 = last_elem_stack(stacks->stack_a);
	i = 0;
	while (i <= moves)
	{
		test_sort_b(stacks, &moves, tmp1, tmp2);
		tmp1 = tmp1->next;
		tmp2 = tmp2->prev;
		i ++;
	}
	printf("____moves = % d\n", moves);
	TEST ;
	make_move(stacks);
	stacks->sizes.size_a --;
	stacks->sizes.size_b ++;
	TEST ;
	TEST ;
	printf("\n");
}

void	test_sort_b(t_data *stacks, int *moves, t_stack *tmp1, t_stack *tmp2)
{
//	printf("moves = %d---------\n", *moves);
//	printf("test up = %d-------\n", test_moves(stacks, tmp1->content));
	if (test_moves(stacks, tmp1->content) <= *moves)
	{
		*moves = test_moves(stacks, tmp1->content);
		stacks->a_index = find_index(stacks->stack_a, tmp1->content);
		stacks->b_index = find_place(stacks->stack_b, tmp1->content);
//		printf("half up-----------------------------------------\n");
	}
//	printf("test down = %d-------\n", test_moves(stacks, tmp2->content));
	if (test_moves(stacks, tmp2->content) <= *moves)
	{
		*moves = test_moves(stacks, tmp2->content);
		stacks->a_index = find_index(stacks->stack_a, tmp2->content);
		stacks->b_index = find_place(stacks->stack_b, tmp2->content);
//		printf("half down---------------------------------------\n");
	}
//	else
//		printf("oups\n");
//	printf("\nindex a = %d, index b = %d\n\n", stacks->a_index,
//		stacks->b_index);
}

static void	make_move(t_data *stacks)
{
	place_stacks_elems(stacks->a_index, stacks->b_index, stacks);
	return (accio("pb", stacks));
}

static void	return_to_a(t_data *stacks, t_sizes *sizes)
{
	while (sizes->size_b)
	{
		accio("pa", stacks);
		stacks->sizes.size_a ++;
		stacks->sizes.size_b --;
	}
}
