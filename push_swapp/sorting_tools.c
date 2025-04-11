/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 22:02:13 by slakhrou          #+#    #+#             */
/*   Updated: 2025/04/11 16:07:30 by slakhrou         ###   ########.fr       */
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
	t_stack	*ptr;
	t_stack	*cheapest;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr)
	{
		if (ptr->cheapest == true)
			cheapest = ptr;
		ptr = ptr->next;
	}
	return (cheapest);
}

void	push_to_b(t_stack	**a, t_stack	**b)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest->above_median && cheapest->target_node->above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->above_median) && !(cheapest->target_node->above_median))
		rev_rotate_both(a, b, cheapest);
	check_in_top(a, cheapest, 'a');
	check_in_top(b, cheapest->target_node, 'b');
	pb(b, a, false);
}

void	push_to_a(t_stack	**a, t_stack	**b)
{
	check_in_top(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

void	min_on_top(t_stack	**a)
{
	while ((*a)->data != find_min(*a)->data)
	{
		if (find_min(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
