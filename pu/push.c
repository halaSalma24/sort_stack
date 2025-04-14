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

	if (!*src)
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
	else
	{
		top_node->next = *dest;
		top_node->next->previous = top_node;
		*dest = top_node;
	}
}

void	pa(t_stack	**a, t_stack	**b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack	**b, t_stack	**a)
{
	push(b, a);
	write(1, "pb\n", 3);
}

void	prep_for_push(t_stack **stack,
						t_stack *top_node,
						char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}
