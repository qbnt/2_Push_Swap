/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:46:35 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/08 12:14:44 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*stack_to_array(t_stack *stack);
static int	get_pivoit_five(t_stack *stack);

/******************************************************************************/

void	algo_5(t_data *stacks)
{
	int		i;
	int		pivot;

	pivot = get_pivoit_five(stacks->stack_a);
	i = 0;
	while (i++ < 5)
	{
		if ((stacks->stack_a)->content < pivot)
			accio("pb", stacks);
		else
			accio("ra", stacks);
	}
	algo_3(stacks);
	if (stacks->stack_b->content
		< stacks->stack_b->next->content)
		accio("sb", stacks);
	accio("pa", stacks);
	accio("pa", stacks);
}

static int	*stack_to_array(t_stack *stack)
{
	int		i;
	int		*array;

	array = malloc(sizeof(int) * (5 + 1));
	i = 0;
	while (stack)
	{
		array[i++] = stack->content;
		stack = stack->next;
	}
	return (array);
}

static int	get_pivoit_five(t_stack *stack)
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
