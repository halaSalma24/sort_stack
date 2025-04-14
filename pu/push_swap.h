/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slakhrou <slakhrou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 00:35:04 by slakhrou          #+#    #+#             */
/*   Updated: 2025/03/26 00:35:04 by slakhrou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				push_cost;
	bool			cheapest;
	bool			above_median;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*previous;
}				t_stack;

int		ft_atoi(char	*str, t_stack	**a);
void	print_error(t_stack	**a);
char	**ft_split(char const *s, char c);
void	check_clones(t_stack	**a, int nb, char	**strs);
void	check_valid(char	*str, t_stack	**a);
void	check_space(char	*str, t_stack	**a);
bool	check_sorted(t_stack	*a);

int		ft_lstsize(t_stack	*lst);
void	free_stack(t_stack	**stack);
t_stack	*ft_last(t_stack	*a);
void	ft_lst_add_back(t_stack	**a, int nb);

void	pa(t_stack	**a, t_stack	**b);
void	pb(t_stack	**b, t_stack	**a);
void	sa(t_stack	**a);
void	sb(t_stack	**b);
void	ss(t_stack	**b, t_stack	**a);
void	ra(t_stack	**a);
void	rb(t_stack	**b);
void	rr(t_stack	**a, t_stack	**b);
void	rotate_both(t_stack	**a, t_stack	**b, t_stack	*cheapest);
void	rra(t_stack	**a);
void	rrb(t_stack	**b);
void	rrr(t_stack	**a, t_stack	**b);
void	rev_rotate_both(t_stack	**a, t_stack	**b, t_stack	*cheapest);

t_stack	*find_min(t_stack	*lst);
t_stack	*get_cheapest(t_stack	*lst);
t_stack	*find_max(t_stack	*lst);
void	sorting(t_stack	**a, t_stack	**b);
void	sort_three(t_stack	**a);
void	sort_stack(t_stack	**a, t_stack	**b);

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
void	set_cheapest(t_stack	*a);
void	current_index(t_stack	*lst);
void	push_to_b(t_stack	**a, t_stack	**b);
void	stack_init_b(t_stack	*a, t_stack	*b);
void	stack_init_a(t_stack	*a, t_stack	*b);
void	push_to_a(t_stack	**a, t_stack	**b);
void	min_on_top(t_stack	**a);
#endif
