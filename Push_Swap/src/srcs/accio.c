/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:17:15 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/18 13:33:11 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*----------------------------------------------------------------------------*/

void	accio(char *op, t_data *stacks)
{
	if (!ft_strcmp(op, "ra") || !ft_strcmp(op, "rr"))
		rotate(&stacks->stack_a);
	if (!ft_strcmp(op, "rb") || !ft_strcmp(op, "rr"))
		rotate(&stacks->stack_b);
	if (!ft_strcmp(op, "rra") || !ft_strcmp(op, "rrr"))
		rrotate(&stacks->stack_a);
	if (!ft_strcmp(op, "rrb") || !ft_strcmp(op, "rrr"))
		rrotate(&stacks->stack_b);
	if (!ft_strcmp(op, "pa"))
		push(&stacks->stack_b, &stacks->stack_a);
	if (!ft_strcmp(op, "pb"))
		push(&stacks->stack_a, &stacks->stack_b);
	if (!ft_strcmp(op, "sa") || !ft_strcmp(op, "ss"))
		swap(&stacks->stack_a);
	if (!ft_strcmp(op, "sb") || !ft_strcmp(op, "ss"))
		swap(&stacks->stack_b);
	ft_printf("%s\n", op);
}
