/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:02:13 by slakhrou          #+#    #+#             */
/*   Updated: 2025/04/12 00:37:34 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_min(t_stack	*lst)
{
	t_stack	*ptr_min;
	long	min;

	if (!lst)
		return (NULL);
	min = LONG_MAX;
	while (lst)
	{
		if (lst->data < min)
		{
			min = lst->data;
			ptr_min = lst;
		}
		lst = lst->next;
	}
	return (ptr_min);
}

t_stack	*get_cheapest(t_stack	*lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (lst->cheapest)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	push_to_b(t_stack	**a, t_stack	**b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}

void	push_to_a(t_stack	**a, t_stack	**b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	pa(a, b);
}

void	min_on_top(t_stack	**a)
{
	while ((*a)->data != find_min(*a)->data)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}
