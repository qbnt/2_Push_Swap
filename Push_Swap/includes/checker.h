/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:46:56 by qbanet            #+#    #+#             */
/*   Updated: 2023/09/17 11:21:52 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
/*----------------------------------------------------------------------------*/

/***Inludes***/

# include"libft.h"
# include"push_swap.h"
# include<stdio.h>

/**Structs**/

typedef struct s_instrucs
{
	struct s_instrucs	*next;
	char				*content;
}	t_instrucs;

/***Fonctions***/

/*read_instrucs.c*/
t_instrucs	*read_instrucs(void);

/*exec_instrucs.c*/
int			exec_intrucs(t_instrucs *instructions, t_data *stacks);

/*utiles.c*/
void		instrucs_add_back(t_instrucs **lst, t_instrucs *n);
t_instrucs	*instrucs_new(char *content);

#endif