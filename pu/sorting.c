/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 02:22:31 by slakhrou          #+#    #+#             */
/*   Updated: 2025/03/30 02:22:31 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack	**a)
{
	t_stack	*max_value;

	max_value = find_max(*a);
	if (max_value == *a)
		ra(a);
	else if ((*a)->next == max_value)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	sort_stack(t_stack	**a, t_stack	**b)
{
	int	size_a;

	size_a = ft_lstsize(*a);
	if (size_a-- > 3 && !check_sorted(*a))
		pb(b, a);
	if (size_a-- > 3 && !check_sorted(*a))
		pb(b, a);
	while (size_a-- > 3 && !check_sorted(*a))
	{
		stack_init_a(*a, *b);
		push_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		stack_init_b(*a, *b);
		push_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}

void	sorting(t_stack	**a, t_stack	**b)
{
	if (!check_sorted(*a))
	{
		if (ft_lstsize(*a) == 2)
			sa(a);
		else if (ft_lstsize(*a) == 3)
			sort_three(a);
		else
			sort_stack(a, b);
	}
}
