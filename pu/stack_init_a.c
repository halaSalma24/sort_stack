/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:34:23 by slakhrou          #+#    #+#             */
/*   Updated: 2025/03/26 00:34:23 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack	*lst)
{
	int		i;
	int		median;

	i = 0;
	if (!lst)
		return ;
	median = ft_lstsize(lst) / 2;
	while (lst)
	{
		lst->index = i;
		if (i <= median)
			lst->above_median = true;
		else
			lst->above_median = false;
		lst = lst->next;
		++i;
	}
}

static void	set_target(t_stack	*a, t_stack	*b)
{
	t_stack	*target_node;
	t_stack	*curr_b;
	long	best_index;

	while (a)
	{
		best_index = LONG_MIN;
		curr_b = b;
		while (curr_b)
		{
			if (curr_b->data < a->data && curr_b->data > best_index)
			{
				best_index = curr_b->data;
				target_node = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (best_index == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static void	set_cost(t_stack	*a, t_stack	*b)
{
	int		len_a;
	int		len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_stack	*a)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!a)
		return ;
	cheapest_value = LONG_MAX;
	while (a)
	{
		if (a->push_cost < cheapest_value)
		{
			cheapest_value = a->push_cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->cheapest = true;
}

void	stack_init_a(t_stack	*a, t_stack	*b)
{
	current_index(a);
	current_index(b);
	set_target(a, b);
	set_cost(a, b);
	set_cheapest(a);
}
