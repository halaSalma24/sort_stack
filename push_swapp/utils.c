/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 23:56:11 by slakhrou          #+#    #+#             */
/*   Updated: 2025/03/29 23:56:11 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(t_stack	**a)
{
	write(2, "Error\n", 6);
	free_stack(a);
	exit(EXIT_FAILURE);
}

static int	ft_int_len(int nb)
{
	int	len;

	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

static int	handle_sign(const char *str, int	*i, t_stack	**a)
{
	int	sign;

	sign = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
		if (!(str[*i] >= '0' && str[*i] <= '9'))
			print_error(a);
	}
	return (sign);
}

int	ft_atoi(char	*str, t_stack	**a)
{
	int		i;
	int		sign;
	long	number;

	i = 0;
	sign = 1;
	number = 0;
	if (str == NULL)
		return (0);
	while (str[i] && (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r')))
		i++;
	sign = handle_sign(str, &i, a);
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + (str[i] - '0');
		i++;
	}
	number *= sign;
	if (number > INT_MAX || number < INT_MIN || str[i] == '-'
		|| str[i] == '+' || (ft_int_len(number) > 10 && number > 0)
		|| (ft_int_len(number) > 11 && number < 0))
		print_error(a);
	return (number);
}

t_stack	*find_max(t_stack	*lst)
{
	t_stack	*ptr_max;
	long	max;

	if (!lst)
		return (NULL);
	max = LONG_MIN;
	while (lst)
	{
		if (lst->data > max)
		{
			max = lst->data;
			ptr_max = lst;
		}
		lst = lst->next;
	}
	return (ptr_max);
}
