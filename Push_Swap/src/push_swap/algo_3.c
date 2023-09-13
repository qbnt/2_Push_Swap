/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:58:05 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/10 11:16:59 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_a(t_data *stacks);
static void	case_b(t_data *stacks);

/******************************************************************************/

void	algo_3(t_data *stacks)
{
	if (stacks->stack_a->content < stacks->stack_a->next->content && \
	stacks->stack_a->next->content > stacks->stack_a->next->next->content && \
	stacks->stack_a->content > stacks->stack_a->next->next->content)
		return (accio("rra", stacks));
	if (stacks->stack_a->content > stacks->stack_a->next->content && \
	stacks->stack_a->next->content < stacks->stack_a->next->next->content && \
	stacks->stack_a->content < stacks->stack_a->next->next->content)
		return (accio("sa", stacks));
	if (stacks->stack_a->content > stacks->stack_a->next->content && \
	stacks->stack_a->next->content < stacks->stack_a->next->next->content && \
	stacks->stack_a->content > stacks->stack_a->next->next->content)
		return (accio("ra", stacks));
	if (stacks->stack_a->content > stacks->stack_a->next->content && \
	stacks->stack_a->next->content > stacks->stack_a->next->next->content)
		return (case_a(stacks));
	if (stacks->stack_a->content < stacks->stack_a->next->content && \
	stacks->stack_a->next->content > stacks->stack_a->next->next->content && \
	stacks->stack_a->content < stacks->stack_a->next->next->content)
		return (case_b(stacks));
}

static void	case_a(t_data *stacks)
{
	accio("ra", stacks);
	accio("sa", stacks);
}

static void	case_b(t_data *stacks)
{
	accio("sa", stacks);
	accio("ra", stacks);
}
