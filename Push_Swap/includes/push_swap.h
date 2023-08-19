/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:17:06 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/19 20:50:38 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/******************************************************************************/
/***inludes***/
# include"libft.h"
# include"push_swap_structs.h"
# include"push_swap_defines.h"
# include<stdio.h>

/***Fonctions***/

/*parsing.c*/
void	parsing_argv2(char **argv, t_data *stacks);
void	parsing_argv_else(char **argv, t_data *stacks);

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

/*push_swap.c*/
void	push_swap(t_data *stacks);

/*algo_1.c*/
void	sort_3(t_data *stacks);

/*error.c*/
void	error(void);

/*utiles_1.c*/
int		strisnum(char *str);
void	ft_printlst(t_list *lst);
void	provisoire_free(t_data *stacks);
int		verif_input(char **args);
void	free_split(char **elems);

/*utiles_2.c*/
int		cmp_2_nodes_a(t_data *stacks);
int		cmp_2_nodes_b(t_data *stacks);
int		cmp_2_nodes_ab(t_data *stacks);

/******************************************************************************/

#endif