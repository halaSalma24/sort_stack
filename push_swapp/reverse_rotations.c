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
	t_stack	*top;
	t_stack	*last;

	if (!lst || !*lst || (*lst)->next == NULL)
		return ;
	top = *lst;
	last = ft_last(*lst);
	last->previous->next = NULL;
	last->next = top;
	last->previous = NULL;
	last->next->previous = last;
	*lst = last;
}

void	rra(t_stack	**a, bool	print)
{
	reverse_rotate(a);
	if (!print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack	**b, bool	print)
{
	reverse_rotate(b);
	if (!print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack	**a, t_stack	**b, bool	print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		write(1, "rrr\n", 4);
}

void	rev_rotate_both(t_stack	**a, t_stack	**b, t_stack	*cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
	{
		rrr(a, b, false);
	}
	current_index(*a);
	current_index(*b);
}
