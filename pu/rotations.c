/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 02:20:03 by slakhrou          #+#    #+#             */
/*   Updated: 2025/03/30 02:20:03 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack	**lst)
{
	t_stack	*last;

	if (!*lst || (*lst)->next == NULL)
		return ;
	last = ft_last(*lst);
	last->next = *lst;
	*lst = (*lst)->next;
	(*lst)->previous = NULL;
	last->next->previous = last;
	last->next->next = NULL;
}

void	ra(t_stack	**a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack	**b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack	**a, t_stack	**b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}

void	rotate_both(t_stack	**a, t_stack	**b, t_stack	*cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
	{
		rr(a, b);
	}
	current_index(*a);
	current_index(*b);
}
