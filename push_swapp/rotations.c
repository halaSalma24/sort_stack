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
	t_stack	*top;
	t_stack	*new_top;
	t_stack	*last;

	if (!lst || !*lst || (*lst)->next == NULL)
		return ;
	top = *lst;
	new_top = top->next;
	new_top->previous = NULL;
	*lst = new_top;
	last = ft_last(*lst);
	last->next = top;
	top->previous = last;
	top->next = NULL;
}

void	ra(t_stack	**a, bool	print)
{
	rotate(a);
	if (!print)
		write(1, "ra\n", 3);
}

void	rb(t_stack	**b, bool	print)
{
	rotate(b);
	if (!print)
		write(1, "rb\n", 3);
}

void	rr(t_stack	**a, t_stack	**b, bool	print)
{
	rotate(a);
	rotate(b);
	if (!print)
		write(1, "rr\n", 3);
}

void	rotate_both(t_stack	**a, t_stack	**b, t_stack	*cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
	{
		rr(a, b, false);
	}
	current_index(*a);
	current_index(*b);
}
