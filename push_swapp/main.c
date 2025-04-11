/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 02:31:24 by slakhrou          #+#    #+#             */
/*   Updated: 2025/03/28 02:31:24 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_string(char	**argv, t_stack	**a)
{
	check_space(*argv, a);
	check_valid(*argv, a);
}

static void	parsing(char	**argv, t_stack	**a)
{
	int		i;
	int		nb;
	int		j;
	char	**strs;

	j = 1;
	while (argv[j])
	{
		parse_string(&argv[j], a);
		strs = ft_split(*(argv + j), ' ');
		if (!strs)
			return ;
		i = 0;
		while (strs[i])
		{
			nb = ft_atoi(strs[i], a);
			//printf("%d\n",nb);
			check_clones(a, nb, strs + i);
			ft_lst_add_back(a, nb);
			free(strs[i]);
			strs[i] = NULL;
			i++;
		}
		free(strs);
		j++;
	}
}

 void f()
 {
	system("leaks push_swap");
 }

void print(t_stack	*a)
{
	if (!a)
		printf("null");
	while (a)
	{
		printf("%d \n", a->data);
		a = a->next;
	}
}
int	main(int argc, char	**argv)
{
	//atexit(f);
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc >= 2)
	{
		parsing(argv, &a);
		sorting(&a, &b);
		free_stack(&a);
		//free_stack(&b);
	}
	return (0);
}
