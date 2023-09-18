/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_instrucs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:39:08 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/18 20:38:47 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

static int	check_instruc(char *instruction);

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
		if (!check_instruc(instruction))
		{
			ft_printf("Error\n");
			tmp = instrucs_new("banane");
			free(instruction);
			return (tmp);
		}
		tmp = instrucs_new(instruction);
		instrucs_add_back(&instructions, tmp);
		free(instruction);
		instruction = get_next_line(0);
	}
	free(instruction);
	return (instructions);
}

static int	check_instruc(char *instruction)
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
		return (1);
	}
	else
		return (0);
}
