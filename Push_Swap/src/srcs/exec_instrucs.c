/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instrucs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:30:20 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/18 11:32:01 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

static int	accio_instrucs(char *instruction, t_data *stacks);
static void	acciom(char *op, t_data *stacks);

/*----------------------------------------------------------------------------*/

int	exec_intrucs(t_instrucs *instructions, t_data *stacks)
{
	while (instructions)
	{
		accio_instrucs(instructions->content, stacks);
		instructions = instructions->next;
	}
	return (1);
}

static int	accio_instrucs(char *instruction, t_data *stacks)
{
	if (!ft_strcmp(instruction, "pa\n")
		|| !ft_strcmp(instruction, "pb\n")
		|| !ft_strcmp(instruction, "sa\n")
		|| !ft_strcmp(instruction, "sb\n")
		|| !ft_strcmp(instruction, "ss\n")
		|| !ft_strcmp(instruction, "ra\n")
		|| !ft_strcmp(instruction, "rb\n")
		|| !ft_strcmp(instruction, "rr\n")
		|| !ft_strcmp(instruction, "rra\n")
		|| !ft_strcmp(instruction, "rrb\n")
		|| !ft_strcmp(instruction, "rrr\n"))
	{
		acciom(instruction, stacks);
		free(instruction);
		return (1);
	}
	return (0);
}

static void	acciom(char *op, t_data *stacks)
{
	if (!ft_strcmp(op, "ra\n") || !ft_strcmp(op, "rr\n"))
		rotate(&stacks->stack_a);
	if (!ft_strcmp(op, "rb\n") || !ft_strcmp(op, "rr\n"))
		rotate(&stacks->stack_b);
	if (!ft_strcmp(op, "rra\n") || !ft_strcmp(op, "rrr\n"))
		rrotate(&stacks->stack_a);
	if (!ft_strcmp(op, "rrb\n") || !ft_strcmp(op, "rrr\n"))
		rrotate(&stacks->stack_b);
	if (!ft_strcmp(op, "pa\n"))
		push(&stacks->stack_b, &stacks->stack_a);
	if (!ft_strcmp(op, "pb\n"))
		push(&stacks->stack_a, &stacks->stack_b);
	if (!ft_strcmp(op, "sa\n") || !ft_strcmp(op, "ss\n"))
		swap(&stacks->stack_a);
	if (!ft_strcmp(op, "sb\n") || !ft_strcmp(op, "ss\n"))
		swap(&stacks->stack_b);
}
