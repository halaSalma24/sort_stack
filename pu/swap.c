/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:31:41 by slakhrou          #+#    #+#             */
/*   Updated: 2025/04/11 23:31:14 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap(t_stack	**lst)
{
	if (!*lst || (*lst)->next == NULL)
		return ;
	*lst = (*lst)->next;
	(*lst)->previous->previous = *lst;
	(*lst)->previous->next = (*lst)->next;
	if ((*lst)->next)
		(*lst)->next->previous = (*lst)->previous;
	(*lst)->next = (*lst)->previous;
	(*lst)->previous = NULL;
}

void	sa(t_stack	**a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack	**b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack	**b, t_stack	**a)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
