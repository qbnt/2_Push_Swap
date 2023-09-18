/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:26:27 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/18 13:32:52 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*----------------------------------------------------------------------------*/

t_stack	*set_empty_stack(void)
{
	t_stack	*new_stack;

	new_stack = ft_calloc(1, sizeof(new_stack));
	return (new_stack);
}

int	is_empty_stack(t_stack *stk)
{
	if (!stk)
		return (1);
	return (0);
}

int	stack_size(t_stack *stk)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = stk;
	while (tmp)
	{
		size ++;
		tmp = tmp->next;
	}
	return (size);
}

t_stack	*insert_back_stack(t_stack **stk, int val)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = malloc(sizeof(t_stack));
	new_node->content = val;
	new_node->next = NULL;
	if (is_empty_stack(*stk))
	{
		new_node->prev = NULL;
		*stk = new_node;
	}
	else
	{
		last = *stk;
		while (last->next)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}
	return (*stk);
}

t_stack	*last_elem_stack(t_stack *stk)
{
	t_stack	*last;

	last = stk;
	while (last->next)
		last = last->next;
	return (last);
}
