/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:18:52 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/23 18:41:55 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/******************************************************************************/

int	main(int argc, char **argv)
{
	t_data	*stacks;

	stacks = ft_calloc(1, sizeof(t_data));
	if (argc == 2)
		parsing_argv2(argv, stacks);
	else if (argc > 2)
		parsing_argv_else(argv, stacks);
	push_swap(stacks);
/*
	if (stacks->stack_a)
	{
		ft_printf("\nStack A :\n");
		ft_printstk(stacks->stack_a);
	}
	if (stacks->stack_b)
	{
		ft_printf("\nStack B :\n");
		ft_printstk(stacks->stack_b);
	}
*/
	return (0);
}
