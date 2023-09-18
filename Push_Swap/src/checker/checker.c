/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:44:33 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/18 09:57:06 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

static void	check_sort(t_data *stacks);

/*----------------------------------------------------------------------------*/

int	main(int argc, char **argv)
{
	t_instrucs	*instructions;
	t_data		*stacks;

	if (argc < 2)
		return (0);
	stacks = ft_calloc(1, sizeof(t_data));
	if (argc == 2)
		parsing_argv2(argv, stacks);
	else if (argc > 2)
		parsing_argv_else(argv, stacks);
	instructions = read_instrucs();
	if (!exec_intrucs(instructions, stacks))
		ft_printf("ERROR\n");
	else
	{
		ft_printstk(stacks->stack_a);
		check_sort(stacks);
	}
	end_free(stacks);
	return (0);
}

static void	check_sort(t_data *stacks)
{
	if (is_sort(&stacks->stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
