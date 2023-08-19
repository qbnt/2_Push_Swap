/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:18:38 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/20 00:22:13 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/

/*Décale d’une position vers le haut tous les élements de la pile a. Le premier
élément devient le dernier.*/
void	move_ra(t_list **lst_a)
{
	t_list	*first;
	t_list	*last;

	if (!*lst_a || !(*lst_a)->next)
		return ;
	first = *lst_a;
	*lst_a = first->next;
	last = *lst_a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	ft_printf("ra\n");
}

/*Décale d’une position vers le haut tous les élements de la pile b. Le premier
élément devient le dernier.*/
void	move_rb(t_list **lst_b)
{
	t_list	*first;
	t_list	*last;

	if (!*lst_b || !(*lst_b)->next)
		return ;
	first = *lst_b;
	*lst_b = first->next;
	last = *lst_b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	ft_printf("rb\n");
}

/*ra et rb en même temps*/
void	move_rr(t_data *stacks)
{
	move_ra(&stacks->stack_a);
	move_rb(&stacks->stack_a);
}
