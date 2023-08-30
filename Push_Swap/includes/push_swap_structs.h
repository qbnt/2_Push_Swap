/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:08:10 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/30 11:05:36 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STRUCTS_H
# define PUSH_SWAP_STRUCTS_H

# include"libft.h"

/******************************************************************************/

typedef struct s_stack
{
	int				content;
	int				stack_size;
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
	t_sizes			*sizes;
	int				nb_elems;
}	t_data;

#endif