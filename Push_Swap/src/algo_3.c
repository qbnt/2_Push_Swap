/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:58:05 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/20 16:29:47 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	case_a(t_list **lst);
static void	case_b(t_list **lst);

/******************************************************************************/

void	algo_3(t_list **lst)
{
	if (*(int *)(*lst)->content < *(int *)(*lst)->next->content && \
		*(int *)(*lst)->next->content > *(int *)(*lst)->next->next->content && \
		*(int *)(*lst)->content > *(int *)(*lst)->next->next->content)
		return (move_rra(lst));
	if (*(int *)(*lst)->content > *(int *)(*lst)->next->content && \
		*(int *)(*lst)->next->content < *(int *)(*lst)->next->next->content && \
		*(int *)(*lst)->content < *(int *)(*lst)->next->next->content)
		return (move_sa(lst));
	if (*(int *)(*lst)->content > *(int *)(*lst)->next->content && \
		*(int *)(*lst)->next->content < *(int *)(*lst)->next->next->content && \
		*(int *)(*lst)->content > *(int *)(*lst)->next->next->content)
		return (move_ra(lst));
	if (*(int *)(*lst)->content > *(int *)(*lst)->next->content && \
		*(int *)(*lst)->next->content > *(int *)(*lst)->next->next->content)
		return (case_a(lst));
	if (*(int *)(*lst)->content < *(int *)(*lst)->next->content && \
		*(int *)(*lst)->next->content > *(int *)(*lst)->next->next->content && \
		*(int *)(*lst)->content < *(int *)(*lst)->next->next->content)
		return (case_b(lst));
}

static void	case_a(t_list **lst)
{
	move_ra(lst);
	move_sa(lst);
}

static void	case_b(t_list **lst)
{
	move_sa(lst);
	move_ra(lst);
}
