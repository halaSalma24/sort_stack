/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 00:52:47 by slakhrou          #+#    #+#             */
/*   Updated: 2025/03/30 00:52:47 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_space(char	*str, t_stack	**a)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		print_error(a);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '\0')
		print_error(a);
}

void	check_valid(char	*str, t_stack	**a)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' '
			|| str[i] == '-' || str[i] == '+')
			i++;
		else
			print_error(a);
	}
}

void	check_clones(t_stack	**a, int nb, char	**strs)
{
	t_stack	*ptr;
	int		i;

	if (!a || !*a)
		return ;
	ptr = *a;
	i = 0;
	while (ptr)
	{
		if (ptr->data == nb)
		{
			while (strs[i])
			{
				free(strs[i]);
				strs[i] = NULL;
				i++;
			}
			print_error(a);
		}
		ptr = ptr->next;
	}
}

bool	check_sorted(t_stack	*a)
{
	if (!a)
		return (false);
	while (a->next)
	{
		if (a->data > a->next->data)
			return (false);
		a = a ->next;
	}
	return (true);
}
