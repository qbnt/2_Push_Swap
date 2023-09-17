/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:17:06 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/17 10:57:13 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*----------------------------------------------------------------------------*/
/***inludes***/
# include"libft.h"
# include"push_swap_structs.h"
# include"push_swap_defines.h"
# include<stdio.h>

/***Fonctions***/

void	end_free(t_data *stacks);

/*parsing.c*/
void	parsing_argv2(char **argv, t_data *stacks);
void	parsing_argv_else(char **argv, t_data *stacks);

/*accio.c*/
void	accio(char *op, t_data *stacks);

/*moves.c*/
void	swap(t_stack **stk);
void	push(t_stack **from, t_stack **to);
void	rotate(t_stack **stk);
void	rrotate(t_stack **stk);

/*push_swap.c*/
void	push_swap(t_data *stacks);
int		verif_atoi(const char **args);

/*algo_3.c*/
void	algo_3(t_data *stacks);

/*algo_5.c*/
void	algo_5(t_data *stacks);

/*turk_algo.c*/
void	turk_algo(t_data *stacks);
int		test_moves(t_data *stacks, int nbr);

/*turk_algo_utiles.c*/
int		find_place(t_stack *stk, int nbr);
void	place_stacks_elems(int a_index, int b_index, t_data *stacks);
void	test_sort_b(t_data *stacks, int *moves, t_stack *tmp1, t_stack *tmp2);

/*error.c*/
void	error(void);

/*utiles_1.c*/
int		strisnum(char *str);
void	ft_printstk(t_stack *stk);
int		verif_input(char **args);
void	free_split(char **elems);
int		is_sort(t_stack **stk);

/*utiles_2.c*/
t_stack	*set_empty_stack(void);
int		is_empty_stack(t_stack *stk);
int		stack_size(t_stack *stk);
t_stack	*insert_back_stack(t_stack **stk, int val);
t_stack	*last_elem_stack(t_stack *stk);

/*utiles_3.c*/
int		find_index(t_stack *stk, int content);
int		max_stack(t_stack **stk);
int		min_stack(t_stack **stk);
void	divided_algo(t_data *stacks);
void	prepare_back(t_data *stacks);

/*----------------------------------------------------------------------------*/

#endif
