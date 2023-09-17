/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instrucs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:30:20 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/17 11:49:24 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

static int	accio_instrucs(char *instruction, t_data *stacks);

/*----------------------------------------------------------------------------*/

int	exec_intrucs(t_instrucs *instructions, t_data *stacks)
{
	while (instructions)
	{
		if (!accio_instrucs(instructions->content, stacks))
			return (0);
		instructions = instructions->next;
	}
	return (1);
}

static int	accio_instrucs(char *instruction, t_data *stacks)
{
	if (!ft_strcmp(instruction, "pa")
		|| !ft_strcmp(instruction, "pb")
		|| !ft_strcmp(instruction, "sa")
		|| !ft_strcmp(instruction, "sb")
		|| !ft_strcmp(instruction, "ss")
		|| !ft_strcmp(instruction, "ra")
		|| !ft_strcmp(instruction, "rb")
		|| !ft_strcmp(instruction, "rr")
		|| !ft_strcmp(instruction, "rra")
		|| !ft_strcmp(instruction, "rrb")
		|| !ft_strcmp(instruction, "rrr"))
	{
		accio(instruction, stacks);
		return (1);
	}
	return (0);
}
