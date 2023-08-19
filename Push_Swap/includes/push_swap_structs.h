/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_structs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:08:10 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/19 12:51:51 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_STRUCTS_H
# define PUSH_SWAP_STRUCTS_H

# include"libft.h"

/******************************************************************************/

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		nb_elems;
}	t_data;

#endif