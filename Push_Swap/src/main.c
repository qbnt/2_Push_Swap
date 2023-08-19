/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:18:52 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/19 14:01:51 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/******************************************************************************/

int	main(int argc, char **argv)
{
	t_data	*stacks;
	char	**args;
	int		i;

	i = 0;
	stacks = ft_calloc(1, sizeof(t_data));
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		stacks->stack_a = pars_argv(args, stacks);
		while (args[i])
		{
			free(args[i]);
			i ++;
		}
		free(args);
	}
	else if (argc > 2)
		stacks->stack_a = pars_argv(argv + 1, stacks);
	if (stacks->stack_a)
		ft_printlst(stacks->stack_a);
	push_swap(stacks);
	provisoire_free(stacks);
	return (0);
}
