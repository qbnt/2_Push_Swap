/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:16:54 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/19 09:23:31 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

/*----------------------------------------------------------------------------*/

void	instrucs_add_back(t_instrucs **lst, t_instrucs *n)
{
	t_instrucs	*temp;

	if (!*lst)
	{
		*lst = n;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = n;
}

t_instrucs	*instrucs_new(char *content)
{
	t_instrucs	*oui;

	oui = malloc(sizeof(t_instrucs));
	if (!oui)
		return (NULL);
	oui->content = ft_strdup(content);
	oui->next = NULL;
	return (oui);
}

t_instrucs	*last_elem_instrucs(t_instrucs *stk)
{
	t_instrucs	*last;

	last = stk;
	while (last->next)
		last = last->next;
	return (last);
}
