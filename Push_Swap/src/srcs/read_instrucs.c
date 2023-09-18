/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instrucs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:39:08 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/18 11:22:02 by qbanet           ###   ########.fr       */
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
	instruction = get_next_line(0);
	while (instruction)
	{
		tmp = instrucs_new(instruction);
		instrucs_add_back(&instructions, tmp);
		free(instruction);
		instruction = get_next_line(0);
	}
	free(instruction);
	return (instructions);
}
