/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instrucs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:30:20 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/19 09:27:05 by qbanet           ###   ########.fr       */
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
		if (!accio_instrucs(instructions->content, stacks))
			return (0);
		else
			instructions = instructions->next;
	}
	return (1);
}

static int	accio_instrucs(char *instruction, t_data *stacks)
{
	if (!ft_strncmp(instruction, "pa\n", 2)
		|| !ft_strncmp(instruction, "pb", 2)
		|| !ft_strncmp(instruction, "sa\n", 2)
		|| !ft_strncmp(instruction, "sb\n", 2)
		|| !ft_strncmp(instruction, "ss\n", 2)
		|| !ft_strncmp(instruction, "ra\n", 2)
		|| !ft_strncmp(instruction, "rb\n", 2)
		|| !ft_strncmp(instruction, "rr\n", 2)
		|| !ft_strncmp(instruction, "rra\n", 2)
		|| !ft_strncmp(instruction, "rrb\n", 2)
		|| !ft_strncmp(instruction, "rrr\n", 2))
	{
		acciom(instruction, stacks);
		return (1);
	}
	return (0);
}

static void	acciom(char *op, t_data *stacks)
{
	if ((!ft_strcmp(op, "ra\n") || !ft_strcmp(op, "rr\n"))
		&& stack_size(stacks->stack_a) > 1)
		rotate(&stacks->stack_a);
	if ((!ft_strcmp(op, "rb\n") || !ft_strcmp(op, "rr\n"))
		&& stack_size(stacks->stack_b) > 1)
		rotate(&stacks->stack_b);
	if ((!ft_strcmp(op, "rra\n") || !ft_strcmp(op, "rrr\n"))
		&& stack_size(stacks->stack_a) > 1)
		rrotate(&stacks->stack_a);
	if ((!ft_strcmp(op, "rrb\n") || !ft_strcmp(op, "rrr\n"))
		&& stack_size(stacks->stack_b) > 1)
		rrotate(&stacks->stack_b);
	if ((!ft_strcmp(op, "pa\n"))
		&& stack_size(stacks->stack_b))
		push(&stacks->stack_b, &stacks->stack_a);
	if ((!ft_strcmp(op, "pb\n"))
		&& stack_size(stacks->stack_a))
		push(&stacks->stack_a, &stacks->stack_b);
	if ((!ft_strcmp(op, "sa\n") || !ft_strcmp(op, "ss\n"))
		&& stack_size(stacks->stack_a) > 1)
		swap(&stacks->stack_a);
	if ((!ft_strcmp(op, "sb\n") || !ft_strcmp(op, "ss\n"))
		&& stack_size(stacks->stack_b) > 1)
		swap(&stacks->stack_b);
}
