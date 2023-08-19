/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:58:05 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/20 00:19:55 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/

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
