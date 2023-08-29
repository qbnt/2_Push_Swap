/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:46:19 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/29 15:28:23 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/******************************************************************************/

void	free_split(char **elems)
{
	int	i;

	i = 0;
	while (elems[i])
	{
		free(elems[i]);
		i ++;
	}
	free(elems);
}

int	verif_input(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!strisnum(args[i]))
			return (0);
		i ++;
	}
	return (1);
}

int	strisnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i ++;
	}
	return (TRUE);
}

void	ft_printstk(t_stack *stk)
{
	int	i;

	i = 0;
	while (stk->next)
	{
		ft_printf("Elem %d = %d\n", i++, stk->content);
		stk = stk->next;
	}
	ft_printf("Elem %d = %d\n", i++, stk->content);
}

int	is_sort(t_stack **stk)
{
	t_stack	*tmp;

	tmp = *stk;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
