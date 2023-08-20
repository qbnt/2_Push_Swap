/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 15:24:25 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/20 15:38:38 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/******************************************************************************/

t_list	*stack_new(int *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return (0);
	lst->next = 0;
	lst->prev = 0;
	lst->content = content;
	return (lst);
}

void	stack_add_front(t_list **lst, t_list *new_node)
{
	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	new_node->next = *lst;
	(*lst)->prev = new_node;
	*lst = new_node;
}

void	stack_add_back(t_list **lst, t_list *new_node)
{
	t_list	*last;

	if (!*lst)
	{
		*lst = new_node;
		return ;
	}
	last = stack_last(*lst);
	(*lst)->next = last;
	new_node->prev = last;
}

t_list	*stack_last(t_list *lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}
