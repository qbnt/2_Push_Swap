/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:18:38 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/19 20:30:34 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/

/*Décale d’une position vers le haut tous les élements de la pile a. Le premier
élément devient le dernier.*/
void	move_ra(t_data *stacks)
{
	t_list	*first;
	t_list	*last;

	if (!stacks->stack_a || !stacks->stack_a->next)
		return ;
	first = stacks->stack_a;
	stacks->stack_a = first->next;
	last = stacks->stack_a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

/*Décale d’une position vers le haut tous les élements de la pile b. Le premier
élément devient le dernier.*/
void	move_rb(t_data *stacks)
{
	t_list	*first;
	t_list	*last;

	if (!stacks->stack_b || !stacks->stack_b->next)
		return ;
	first = stacks->stack_b;
	stacks->stack_b = first->next;
	last = stacks->stack_b;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

/*ra et rb en même temps*/
void	move_rr(t_data *stacks)
{
	move_ra(stacks);
	move_rb(stacks);
}
