/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:18:52 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/05 11:08:50 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	end_free(t_data *stacks);

/******************************************************************************/

int	main(int argc, char **argv)
{
	t_data	*stacks;

	stacks = ft_calloc(1, sizeof(t_data));
	if (argc < 2)
		return (1);
	else if (argc == 2)
		parsing_argv2(argv, stacks);
	else if (argc > 2)
		parsing_argv_else(argv, stacks);
	push_swap(stacks);
	end_free(stacks);
	return (0);
}

static void	end_free(t_data *stacks)
{
	t_stack	*tmp;

	if (stacks->stack_a)
	{
		while (stacks->stack_a)
		{
			tmp = stacks->stack_a;
			stacks->stack_a = tmp->next;
			free(tmp);
		}
	}
	if (stacks->stack_b)
	{
		while (stacks->stack_b)
		{
			tmp = stacks->stack_b;
			stacks->stack_b = tmp->next;
			free(tmp);
		}
	}
	free(stacks);
}
