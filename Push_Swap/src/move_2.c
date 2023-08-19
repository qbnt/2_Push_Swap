/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:18:38 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/19 12:49:45 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/

/*Décale d’une position vers le haut tous les élements de la pile a. Le premier
élément devient le dernier.*/
void	move_ra(t_data *stacks)
{
	stacks += 0;
}

/*Décale d’une position vers le haut tous les élements de la pile b. Le premier
élément devient le dernier.*/
void	move_rb(t_data *stacks)
{
	stacks += 0;
}

/*ra et rb en même temps*/
void	move_rr(t_data *stacks)
{
	move_ra(stacks);
	move_rb(stacks);
}
