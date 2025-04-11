/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:31:41 by slakhrou          #+#    #+#             */
/*   Updated: 2025/04/09 21:59:33 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap(t_stack	**lst)
{
	t_stack	*node1;
	t_stack	*node2;

	if (!lst || !*lst || (*lst)->next == NULL)
		return ;
	node1 = *lst;
	node2 = node1->next;
	node1->next = node2->next;
	if (node1->next)
		node1->next->previous = node1;
	node2->next = node1;
	node2->previous = NULL;
	*lst = node2;
}

void	sa(t_stack	**a, bool	print)
{
	swap(a);
	if (!print)
		write(1, "sa\n", 3);
}

void	sb(t_stack	**b, bool	print)
{
	swap(b);
	if (!print)
		write(1, "sb\n", 3);
}

void	ss(t_stack	**b, t_stack	**a, bool	print)
{
	swap(a);
	swap(b);
	if (print)
		write(1, "ss\n", 3);
}
