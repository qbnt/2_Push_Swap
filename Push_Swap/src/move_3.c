/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:24:25 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/20 15:56:20 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/

/*Décale d’une position vers le bas tous les élements de la pile a. Le dernier
élément devient le premier.*/
void	move_rra(t_list **lst_a)
{
	t_list	*last;
	t_list	*prev_last;

	if (!*lst_a || !(*lst_a)->next)
		return ;
	last = *lst_a;
	prev_last = NULL;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	last->next = *lst_a;
	*lst_a = last;
	if (prev_last)
		prev_last->next = NULL;
	ft_printf("rra\n");
}

/*Décale d’une position vers le bas tous les élements de la pile b. Le dernier
élément devient le premier.*/
void	move_rrb(t_list **lst_b)
{
	t_list	*last;
	t_list	*prev_last;

	if (!*lst_b || !(*lst_b)->next)
		return ;
	last = *lst_b;
	prev_last = NULL;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	last->next = *lst_b;
	*lst_b = last;
	if (prev_last)
		prev_last->next = NULL;
	ft_printf("rrb\n");
}

/*rra et rrb en même temps*/
void	move_rrr(t_data *stacks)
{
	move_rra(&stacks->stack_a);
	move_rrb(&stacks->stack_b);
}
