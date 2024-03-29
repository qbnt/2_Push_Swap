/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:13:45 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/18 13:13:39 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*pars_argv(char **args);
static void		set_node(t_stack **list, char *elem);
static int		has_duplicate(char **elems);

/******************************************************************************/

void	parsing_argv2(char **argv, t_data *stacks)
{
	char	**args;

	args = ft_split(argv[1], ' ');
	if (!*argv)
	{
		free_split(args);
		free(stacks);
		exit(EXIT_FAILURE);
	}
	else if (!verif_input(args) || has_duplicate(args)
		|| verif_atoi((const char **)args))
	{
		free_split(args);
		free(stacks);
		error();
	}
	stacks->stack_a = pars_argv(args);
	stacks->sizes.size_b = 0;
	stacks->sizes.size_a = stack_size(stacks->stack_a);
	free_split(args);
}

void	parsing_argv_else(char **argv, t_data *stacks)
{
	if (!verif_input(argv + 1) || has_duplicate(argv + 1)
		|| verif_atoi((const char **)argv + 1))
	{
		free(stacks);
		error();
	}
	stacks->stack_a = pars_argv(argv + 1);
	stacks->sizes.size_a = stack_size(stacks->stack_a);
	stacks->sizes.size_b = 0;
}

static t_stack	*pars_argv(char **args)
{
	t_stack	*parsed_list;
	int		i;

	i = 0;
	parsed_list = NULL;
	while (args[i])
	{
		set_node(&parsed_list, args[i]);
		i ++;
	}
	return (parsed_list);
}

static void	set_node(t_stack **list, char *elem)
{
	int		val;

	val = ft_atoi(elem);
	*list = insert_back_stack(list, val);
}

static int	has_duplicate(char **elems)
{
	int	i;
	int	j;

	i = 0;
	while (elems[i])
	{
		j = i + 1;
		while (elems[j])
		{
			if (ft_atol(elems[i]) == ft_atol(elems[j]))
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}
