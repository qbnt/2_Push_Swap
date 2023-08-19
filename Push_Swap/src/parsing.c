/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:13:45 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/19 16:02:05 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*pars_argv(char **args);
static void		set_node(t_list **list, char *elem);

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
	else if (!verif_input(args))
	{
		free_split(args);
		free(stacks);
		error();
	}
	stacks->stack_a = pars_argv(args);
	free_split(args);
}

void	parsing_argv_else(char **argv, t_data *stacks)
{
	if (!verif_input(argv + 1))
	{
		free(stacks);
		error();
	}
	stacks->stack_a = pars_argv(argv + 1);
}

static t_list	*pars_argv(char **args)
{
	t_list	*parsed_list;
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

static void	set_node(t_list **list, char *elem)
{
	t_list	*new_node;
	int		*val;

	val = malloc(sizeof(int));
	*val = ft_atoi(elem);
	new_node = ft_lstnew(val);
	if (!(*list))
		*list = new_node;
	else
		ft_lstadd_back(list, new_node);
}
