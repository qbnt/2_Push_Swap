/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 14:27:08 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/07 17:03:33 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*----------------------------------------------------------------------------*/

void	swap(t_stack **stk)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stk || !(*stk)->next)
		return ;
	first = *stk;
	second = (*stk)->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stk = second;
}

void	push(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (*from == NULL)
		return ;
	tmp = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	if (*to)
		(*to)->prev = tmp;
	tmp->next = *to;
	*to = tmp;
	(*to)->prev = NULL;
}

void	rotate(t_stack **stk)
{
	t_stack	*tmp;

	if (!*stk || !(*stk)->next)
		return ;
	tmp = *stk;
	*stk = (*stk)->next;
	tmp->next = NULL;
	tmp->prev = last_elem_stack(*stk);
	tmp->prev->next = tmp;
	(*stk)->prev = NULL;
}

void	rrotate(t_stack **stk)
{
	t_stack	*tmp;

	if (!*stk || !(*stk))
		return ;
	tmp = last_elem_stack(*stk);
	tmp->prev->next = NULL;
	tmp->next = *stk;
	tmp->next->prev = tmp;
	tmp->prev = NULL;
	*stk = tmp;
}
