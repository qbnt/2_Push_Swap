/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:18:52 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/19 21:16:28 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/******************************************************************************/

int	main(int argc, char **argv)
{
	t_data	*stacks;

	stacks = ft_calloc(1, sizeof(t_data));

/******parsing******/
	if (argc == 2)
		parsing_argv2(argv, stacks);
	else if (argc > 2)
		parsing_argv_else(argv, stacks);

/******algo******/
	sort_3(stacks);
	push_swap(stacks);

/******utils******/
	if (stacks->stack_a)
	{
		ft_printf("Stack A :\n");
		ft_printlst(stacks->stack_a);
	}
	if (stacks->stack_b)
	{
		ft_printf("\nStack B :\n");
		ft_printlst(stacks->stack_b);
	}
	provisoire_free(stacks);
	return (0);
}
