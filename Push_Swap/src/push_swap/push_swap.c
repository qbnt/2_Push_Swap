/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:46:26 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/14 15:06:38 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/

void	push_swap(t_data *stacks)
{
	if (is_sort(&stacks->stack_a))
		return ;
	else if (stacks->sizes.size_a == 2
		&& stacks->stack_a->content
		> stacks->stack_a->next->content)
		return (accio("sa", stacks));
	else if (stacks->sizes.size_a == 3)
		return (algo_3(stacks));
	stacks->size_divided = (stack_size(stacks->stack_a) / 100) * 9;
	if (stacks->size_divided < 3)
		stacks->size_divided = 3;
	stacks->max = max_stack(&stacks->stack_a);
	stacks->min = min_stack(&stacks->stack_a);
	return (turk_algo(stacks));
}

int	verif_atoi(const char **args)
{
	int			i;
	long long	test;

	i = 0;
	while (args[i])
	{
		test = ft_atol(args[i]);
		if (test < _INT_MIN || test > _INT_MAX)
			return (1);
		i ++;
	}
	return (0);
}