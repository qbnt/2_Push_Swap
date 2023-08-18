/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:17:06 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/18 17:01:15 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/******************************************************************************/
/***inludes***/
# include"libft.h"
# include"push_swap_structs.h"
# include<stdio.h>

/***Fonctions***/

/*move_1.c*/
void	move_sa(t_piles *piles);
void	move_sb(t_piles *piles);
void	move_ss(t_piles *piles);
void	move_pa(t_piles *piles);
void	move_pb(t_piles *piles);

/*move_2.c*/
void	move_ra(t_piles *piles);
void	move_rb(t_piles *piles);
void	move_rr(t_piles *piles);

/*move_3.c*/
void	move_rra(t_piles *piles);
void	move_rrb(t_piles *piles);
void	move_rrr(t_piles *piles);

/*parsing.c*/
t_list	*pars_argv2(char *args);
t_list	*pars_argvs(char **args);
void	set_node(t_list *list, char *elem);

/*push_swap.c*/
void	push_swap(t_piles *piles);

/*error.c*/
void	error(t_list *list);

/*utiles.c*/
int		strisnum(char *str);

/******************************************************************************/

#endif