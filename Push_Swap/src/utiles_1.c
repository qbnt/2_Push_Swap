/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 13:46:19 by qbanet            #+#    #+#             */
/*   Updated: 2023/08/19 15:52:24 by qbanet           ###   ########.fr       */
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

void	ft_printlst(t_list *lst)
{
	int	i;

	i = 0;
	while (lst->next)
	{
		ft_printf("Elem %d = %d\n", i++, *(int *)lst->content);
		lst = lst->next;
	}
	ft_printf("Elem %d = %d\n", i++, *(int *)lst->content);
}

void	provisoire_free(t_data *stacks)
{
	t_list	*tmp;

	while (stacks->stack_a)
	{
		tmp = stacks->stack_a;
		stacks->stack_a = stacks->stack_a->next;
		if (tmp->content)
			free(tmp->content);
		free(tmp);
	}
	free(stacks);
}
