/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 18:44:42 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/04 14:28:54 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_to_b(t_data *stacks, t_sizes *sizes);
static int	test_mouve(t_data *stacks, int nbr);
static int	place_to(t_stack **stk_to, t_sizes *sizes, int nbr_to_place);
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
/*
	algo_3(stacks);
	return_to_a(stacks, &stacks->sizes);
*/
}

static void	sort_to_b(t_data *stacks, t_sizes *sizes)
{
	int		i;
	t_stack	*tmp;

	i = test_mouve(stacks, stacks->stack_a->content);
	i += 0;
	tmp = stacks->stack_a;
	while (tmp)
	{
		tmp = tmp->next;
	}
	sizes->size_a --;
	sizes->size_b ++;
}

static int	test_mouve(t_data *stacks, int nbr)
{
	int	i;

	i = 0;
	if (nbr > stacks->stack_b->content &&)
	return (i);
}

static int	place_to(t_stack **stk_to, t_sizes *sizes, int nbr_to_place)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	sizes += 0;
	if (nbr_to_place > (*stk_to)->content
		&& nbr_to_place < (last_elem_stack(*stk_to))->content)
		i = 0;
	else if (nbr_to_place > max_stack(stk_to)
		|| nbr_to_place < min_stack(stk_to))
		i = find_index(*stk_to, max_stack(stk_to));
	else
	{
		tmp = (*stk_to)->next;
		while ((tmp->content > nbr_to_place || tmp->content < nbr_to_place)
			&& tmp)
		{
			printf("nbr = %d\n", nbr_to_place);
			printf("nbr_cheacked = %d\n", tmp->content);
			i ++;
			tmp = tmp->next;
		}
	}
	return (i);
}

/*
static void	return_to_a(t_data *stacks, t_sizes *sizes)
{
	stacks += 0;
	sizes += 0;
}
*/