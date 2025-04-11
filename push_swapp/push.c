/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 05:15:01 by slakhrou          #+#    #+#             */
/*   Updated: 2025/03/26 05:15:01 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack	**dest, t_stack	**src)
{
	t_stack	*top_node;

	if (!*src || !src)
		return ;
	top_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->previous = NULL;
	top_node->previous = NULL;
	if (!*dest)
	{
		*dest = top_node;
		top_node->next = NULL;
	}
	top_node->next = *dest;
	top_node->next->previous = top_node;
	*dest = top_node;
}

void	pa(t_stack	**a, t_stack	**b, bool	print)
{
	push(a, b);
	if (!print)
		write(1, "pa\n", 3);
}

void	pb(t_stack	**b, t_stack	**a, bool	print)
{
	push(b, a);
	if (!print)
		write(1, "pb\n", 3);
}

void	check_in_top(t_stack	**lst, t_stack	*top_node, char c)
{
	while (*lst != top_node)
	{
		if (c == 'a')
		{
			if (top_node->above_median)
				ra(lst, false);
			else
				rra(lst, false);
		}
		else if (c == 'b')
		{
			if (top_node->above_median)
				rb(lst, false);
			else
				rrb(lst, false);
		}
	}
}
