/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:44:42 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/04 19:47:58 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_to_b(t_data *stacks, t_sizes *sizes);
static int	test_mouves(t_data *stacks, int nbr);
static void	make_mouve(t_data *stacks, int mouve_count);
//static void	return_to_a(t_data *stacks, t_sizes *sizes);

/*----------------------------------------------------------------------------*/

void	turk_algo(t_data *stacks)
{
	accio("pb", stacks);
	accio("pb", stacks);
	stacks->sizes.size_a = stack_size(stacks->stack_a);
	stacks->sizes.size_b = stack_size(stacks->stack_b);
	while (stacks->sizes.size_a > 3 && !is_sort(&stacks->stack_a))
		sort_to_b(stacks, &stacks->sizes);
	algo_3(stacks);
/*
	return_to_a(stacks, &stacks->sizes);
*/
}

static void	sort_to_b(t_data *stacks, t_sizes *sizes)
{
	int		i;
	t_stack	*tmp;

	i = test_mouves(stacks, stacks->stack_a->content);
	tmp = stacks->stack_a;
	while (tmp)
	{
		if (test_mouves(stacks, tmp->content) < i)
			i = test_mouves(stacks, tmp->content);
		tmp = tmp->next;
	}
	printf("i final = %d\n", i);
	make_mouve(stacks, i);
	sizes->size_a --;
	sizes->size_b ++;
}

static int	test_mouves(t_data *stacks, int nbr)
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

static void	make_mouve(t_data *stacks, int mouve_count)
{
	if (mouve_count)
		accio("pb", stacks);
}

/*
static void	return_to_a(t_data *stacks, t_sizes *sizes)
{
	stacks += 0;
	sizes += 0;
}
*/