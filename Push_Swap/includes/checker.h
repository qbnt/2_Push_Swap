/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:46:56 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/13 13:57:16 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
/*----------------------------------------------------------------------------*/

/***Inludes***/

# include"libft.h"
# include<stdio.h>

/**Structs**/

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_sizes
{
	int				size_a;
	int				size_b;
}	t_sizes;

typedef struct s_data
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_sizes			sizes;
	int				a_index;
	int				b_index;
	int				size_divided;
	int				min;
	int				max;
}	t_data;

/***Fonctions***/

/*accio.c*/
void	accio(char *op, t_data *stacks);

/*moves.c*/
void	swap(t_stack **stk);
void	push(t_stack **from, t_stack **to);
void	rotate(t_stack **stk);
void	rrotate(t_stack **stk);

/*utiles1.c*/

#endif