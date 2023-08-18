/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:13:45 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/18 17:00:06 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/

t_list	*pars_argv2(char *args)
{
	t_list	*parsed_list;
	char	**list;

	parsed_list = ft_calloc(1, sizeof(t_list));
	list = ft_split(args, ' ');
	while (list)
	{
		set_node(parsed_list, *list);
		free(*list);
		list ++;
	}
	free(*list);
	free(list);
	return (parsed_list);
}

t_list	*pars_argvs(char **args)
{
	t_list	*parsed_list;

	parsed_list = ft_calloc(1, sizeof(t_list));
	while (args)
	{
		set_node(parsed_list, *args);
		args ++;
	}
	return (parsed_list);
}

void	set_node(t_list *list, char *elem)
{
	t_list	*new_node;
	int		*val;

	val = malloc(sizeof(int));
	*val = ft_atoi(elem);
	if (!strisnum(elem))
		error(list);
	new_node = ft_lstnew(val);
	if (!list->next)
		ft_lstadd_back(&list, new_node);
	else
		list = new_node;
}
