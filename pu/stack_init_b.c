/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:49:09 by slakhrou          #+#    #+#             */
/*   Updated: 2025/04/11 18:37:26 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_stack	*a, t_stack	*b)
{
	t_stack	*curr_a;
	t_stack	*target_node;
	long	best_index;

	while (b)
	{
		best_index = LONG_MAX;
		curr_a = a;
		while (curr_a)
		{
			if (curr_a->data > b->data && curr_a->data < best_index)
			{
				best_index = curr_a->data;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	stack_init_b(t_stack	*a, t_stack	*b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}
