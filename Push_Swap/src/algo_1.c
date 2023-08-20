/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:58:05 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/20 11:28:16 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/

void	algo_4_10(t_data *stacks)
{
	stacks += 0;
	printf("4-10\n");
}

void	algo_11_100(t_data *stacks)
{
	stacks += 0;
	printf("11-100\n");
}

void	algo_101(t_data *stacks)
{
	stacks += 0;
	printf("101\n");
}

void	sort_3(t_list **lst)
{
	if (!lst || !(*lst) || !(*lst)->next)
		return ;

	if (*(int *)(*lst)->content > *(int *)(*lst)->next->content)
		move_sa(lst);

	if (*(int *)(*lst)->next->content > *(int *)(*lst)->next->next->content)
		move_sa(&(*lst)->next);

	if (*(int *)(*lst)->content > *(int *)(*lst)->next->content)
		move_sa(lst);
}
