/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:46:19 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/23 15:40:08 by qbanet           ###   ########.fr       */
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
