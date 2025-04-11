/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 01:48:36 by slakhrou          #+#    #+#             */
/*   Updated: 2025/03/30 01:48:36 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack	**stack)
{
	t_stack		*ptr;
	t_stack		*tmp;

	if (!stack || !*stack)
		return ;
	ptr = *stack;
	while (ptr)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	*stack = NULL;
}

int	ft_lstsize(t_stack	*lst)
{
	t_stack	*ptr;
	int		len;

	if (!lst)
		return (0);
	len = 0;
	ptr = lst;
	while (ptr)
	{
		len++;
		ptr = ptr ->next;
	}
	return (len);
}

t_stack	*ft_last(t_stack	*a)
{
	t_stack	*ptr;

	if (!a)
		return (NULL);
	ptr = a;
	while (ptr -> next)
	{
		ptr = ptr -> next;
	}
	return (ptr);
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new;

	new = (t_stack *) malloc (sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> data = content;
	new -> next = NULL;
	return (new);
}

void	ft_lst_add_back(t_stack	**a, int nb)
{
	t_stack		*node;
	t_stack		*last_node;

	if (!a)
		return ;
	node = ft_lstnew(nb);
	if (*a == NULL)
	{
		*a = node;
		node->previous = NULL;
	}
	else
	{
		last_node = ft_last(*a);
		last_node->next = node;
		node->previous = last_node;
	}
}
