/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:05:41 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/20 16:29:12 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/*Intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il
n’y en a qu’un ou aucun.*/
void	move_sa(t_list **lst_a)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!*lst_a || !(*lst_a)->next)
		return ;
	first = *lst_a;
	second = (*lst_a)->next;
	third = second->next;
	*lst_a = second;
	second->next = first;
	first->next = third;
	ft_printf("sa\n");
}

/*Intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il
n’y en a qu’un ou aucun.*/
void	move_sb(t_list **lst_b)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!*lst_b || !(*lst_b)->next)
		return ;
	first = *lst_b;
	second = (*lst_b)->next;
	third = second->next;
	*lst_b = second;
	second->next = first;
	first->next = third;
	ft_printf("sb\n");
}

/*sa et sb en même temps.*/
void	move_ss(t_data *stacks)
{
	move_sa(&stacks->stack_a);
	move_sb(&stacks->stack_b);
	
}

/*Prend le premier élément au sommet de b et le met sur a. Ne fait rien si b
est vide.*/
void	move_pa(t_data *stacks)
{
	t_list	*first_b;

	if (!stacks->stack_b)
		return ;
	first_b = stacks->stack_b;
	stacks->stack_b = first_b->next;
	first_b->next = stacks->stack_a;
	stacks->stack_a = first_b;
	ft_printf("pa\n");
}

/*Prend le premier élément au sommet de a et le met sur b. Ne fait rien si a
est vide.*/
void	move_pb(t_data *stacks)
{
	t_list	*first_a;

	if (!stacks->stack_a)
		return ;
	first_a = stacks->stack_a;
	stacks->stack_a = first_a->next;
	first_a->next = stacks->stack_b;
	stacks->stack_b = first_a;
	ft_printf("pb\n");
}
