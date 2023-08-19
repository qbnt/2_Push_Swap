/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:17:06 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/19 14:03:16 by qbanet           ###   ########.fr       */
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
void	move_sa(t_data *stacks);
void	move_sb(t_data *stacks);
void	move_ss(t_data *stacks);
void	move_pa(t_data *stacks);
void	move_pb(t_data *stacks);

/*move_2.c*/
void	move_ra(t_data *stacks);
void	move_rb(t_data *stacks);
void	move_rr(t_data *stacks);

/*move_3.c*/
void	move_rra(t_data *stacks);
void	move_rrb(t_data *stacks);
void	move_rrr(t_data *stacks);

/*parsing.c*/
t_list	*pars_argv(char **args, t_data *stacks);
void	set_node(t_list **list, char *elem);

/*push_swap.c*/
void	push_swap(t_data *stacks);

/*error.c*/
void	error(t_list *list, t_data *stacks);

/*utiles.c*/
int		strisnum(char *str);
void	ft_printlst(t_list *lst);
void	provisoire_free(t_data *stacks);

/******************************************************************************/

#endif