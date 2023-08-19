/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:24:25 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/19 20:38:32 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/

/*Décale d’une position vers le bas tous les élements de la pile a. Le dernier
élément devient le premier.*/
void	move_rra(t_data *stacks)
{
	t_list	*last;
	t_list	*prev_last;

	if (!stacks->stack_a || !stacks->stack_a->next)
		return ;
	last = stacks->stack_a;
	prev_last = NULL;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	last->next = stacks->stack_a;
	stacks->stack_a = last;
	if (prev_last)
		prev_last->next = NULL;
}

/*Décale d’une position vers le bas tous les élements de la pile b. Le dernier
élément devient le premier.*/
void	move_rrb(t_data *stacks)
{
	t_list	*last;
	t_list	*prev_last;

	if (!stacks->stack_b || !stacks->stack_b->next)
		return ;
	last = stacks->stack_b;
	prev_last = NULL;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	last->next = stacks->stack_b;
	stacks->stack_b = last;
	if (prev_last)
		prev_last->next = NULL;
}

/*rra et rrb en même temps*/
void	move_rrr(t_data *stacks)
{
	move_rra(stacks);
	move_rrb(stacks);
}
