/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 16:03:36 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/19 20:54:39 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/

int	cmp_2_nodes_a(t_data *stacks)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		dif;

	if (!stacks->stack_a || !stacks->stack_a->next)
		return (0);
	tmp1 = stacks->stack_a;
	tmp2 = stacks->stack_a->next;
	dif = *(int *)tmp1->content - *(int *)tmp2->content;
	ft_printf("dif = %d\n", dif);
	return (dif);
}

int	cmp_2_nodes_b(t_data *stacks)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		dif;

	if (!stacks->stack_b || !stacks->stack_b->next)
		return (0);
	tmp1 = stacks->stack_b;
	tmp2 = stacks->stack_b->next;
	dif = *(int *)tmp1->content - *(int *)tmp2->content;
	ft_printf("dif = %d\n", dif);
	return (dif);
}

int	cmp_2_nodes_ab(t_data *stacks)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		dif;

	if (!stacks->stack_a || !stacks->stack_b)
		return (0);
	tmp1 = stacks->stack_a;
	tmp2 = stacks->stack_b;
	dif = *(int *)tmp1->content - *(int *)tmp2->content;
	ft_printf("dif = %d\n", dif);
	return (dif);
}
