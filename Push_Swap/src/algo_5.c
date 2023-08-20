/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:46:35 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/20 16:29:54 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_list *stack);
static int	get_pivoit_five(t_list *stack);

/******************************************************************************/

void	algo_5(t_data *stacks)
{
	int		i;
	int		pivot;

	pivot = get_pivoit_five(stacks->stack_a);
	i = 0;
	while (i++ < 5)
	{
		if (*(int *)(stacks->stack_a)->content < pivot)
			move_pb(stacks);
		else
			move_ra(&stacks->stack_a);
	}
	algo_3(&stacks->stack_a);
	if (stacks->stack_b->content < stacks->stack_b->next->content)
		move_sb(&stacks->stack_b);
	move_pa(stacks);
	move_pa(stacks);
}

static int	*stack_to_array(t_list *stack)
{
	int		i;
	int		*array;

	array = malloc(sizeof(int) * (5 + 1));
	i = 0;
	while (stack)
	{
		array[i++] = *(int *)stack->content;
		stack = stack->next;
	}
	return (array);
}

static int	get_pivoit_five(t_list *stack)
{
	int		pivot;
	int		iv[2];
	int		*array;
	int		tmp;

	array = stack_to_array(stack);
	iv[0] = 0;
	while (iv[0] < 4)
	{
		iv[1] = iv[0] + 1;
		while (iv[1] < 5)
		{
			if (array[iv[0]] < array[iv[1]])
			{
				tmp = array[iv[0]];
				array[iv[0]] = array[iv[1]];
				array[iv[1]] = tmp;
			}
			++iv[1];
		}
		++iv[0];
	}
	pivot = array[2];
	free(array);
	return (pivot);
}

