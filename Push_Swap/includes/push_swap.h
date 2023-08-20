/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:17:06 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/20 16:35:54 by qbanet           ###   ########.fr       */
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
void	move_sa(t_list **lst_a);
void	move_sb(t_list **lst_b);
void	move_ss(t_data *stacks);
void	move_pa(t_data *stacks);
void	move_pb(t_data *stacks);

/*move_2.c*/
void	move_ra(t_list **lst_a);
void	move_rb(t_list **lst_b);
void	move_rr(t_data *stacks);

/*move_3.c*/
void	move_rra(t_list **lst_a);
void	move_rrb(t_list **lst_b);
void	move_rrr(t_data *stacks);

/*move_utiles.c*/
t_list	*stack_new(int *content);
void	stack_add_front(t_list **lst, t_list *new_node);
void	stack_add_back(t_list **lst, t_list *new_node);
t_list	*stack_last(t_list *lst);

/*push_swap.c*/
void	push_swap(t_data *stacks);

/*algo_3.c*/
void	algo_3(t_list **lst);

/*algo_5.c*/
void	algo_5(t_data *stacks);

/*main_algo.c*/
void	main_algo(t_data *stacks);

/*error.c*/
void	error(void);

/*utiles_1.c*/
int		strisnum(char *str);
void	ft_printlst(t_list *lst);
void	free_all(t_data *stacks);
int		verif_input(char **args);
void	free_split(char **elems);

/*utiles_2.c*/
int		cmp_2_nodes_a(t_data *stacks);
int		cmp_2_nodes_b(t_data *stacks);
int		cmp_2_nodes_ab(t_data *stacks);
void	ft_swap(int *a, int *b);

/******************************************************************************/

#endif