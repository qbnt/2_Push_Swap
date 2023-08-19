/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:18:52 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/19 16:01:41 by qbanet           ###   ########.fr       */
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
	push_swap(stacks);
	sort_3(stacks);


/******utils******/
	if (stacks->stack_a)
		ft_printlst(stacks->stack_a);
	provisoire_free(stacks);
	return (0);
}
