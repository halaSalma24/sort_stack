/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 02:19:45 by slakhrou          #+#    #+#             */
/*   Updated: 2025/03/30 02:19:45 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_stack	**lst)
{
	t_stack	*last;

	if (!*lst || (*lst)->next == NULL)
		return ;
	last = ft_last(*lst);
	last->previous->next = NULL;
	last->next = *lst;
	last->previous = NULL;
	*lst = last;
	last->next->previous = last;
}

void	rra(t_stack	**a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack	**b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack	**a, t_stack	**b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

void	rev_rotate_both(t_stack	**a, t_stack	**b, t_stack	*cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
	{
		rrr(a, b);
	}
	current_index(*a);
	current_index(*b);
}
