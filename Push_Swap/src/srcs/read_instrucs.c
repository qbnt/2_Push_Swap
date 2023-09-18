/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instrucs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:39:08 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/18 10:21:06 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

/*----------------------------------------------------------------------------*/

t_instrucs	*read_instrucs(void)
{
	char		*instruction;
	t_instrucs	*instructions;
	t_instrucs	*tmp;

	instructions = NULL;
	while (1)
	{
		instruction = get_next_line(0);
		if (instruction == NULL)
			break ;
		tmp = instrucs_new(instruction);
		instrucs_add_back(&instructions, tmp);
		free(instruction);
	}
	return (instructions);
}
