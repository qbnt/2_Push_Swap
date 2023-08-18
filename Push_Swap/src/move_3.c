/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:24:25 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/18 16:49:07 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/

/*Décale d’une position vers le bas tous les élements de la pile a. Le dernier
élément devient le premier.*/
void	move_rra(t_piles *piles)
{
	piles += 0;
}

/*Décale d’une position vers le bas tous les élements de la pile b. Le dernier
élément devient le premier.*/
void	move_rrb(t_piles *piles)
{
	piles += 0;
}

/*rra et rrb en même temps*/
void	move_rrr(t_piles *piles)
{
	move_rra(piles);
	move_rrb(piles);
}