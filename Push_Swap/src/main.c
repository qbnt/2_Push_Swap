/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:18:52 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/18 16:50:09 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/******************************************************************************/

int	main(int argc, char **argv)
{
	t_piles	piles;

	piles.pile_a = NULL;
	if (argc == 2)
		piles.pile_a = pars_argv2(argv[1]);
	else if (argc > 2)
		piles.pile_a = pars_argvs(argv + 1);
	push_swap(&piles);
	return (EXIT_FAILURE);
}
