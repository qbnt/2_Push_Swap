/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:13:45 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/19 14:02:28 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/

t_list	*pars_argv(char **args, t_data *stacks)
{
	t_list	*parsed_list;
	int		i;

	i = 0;
	parsed_list = NULL;
	while (args[i])
	{
		if (!strisnum(args[i]))
		{
			i = 0;
			while (args[i])
			{
				free(args[i]);
				i ++;
			}
			free(args);
			error(parsed_list, stacks);
		}
		set_node(&parsed_list, args[i]);
		i ++;
	}
	return (parsed_list);
}

void	set_node(t_list **list, char *elem)
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
