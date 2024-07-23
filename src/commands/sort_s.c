/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:16:10 by dde-carv          #+#    #+#             */
/*   Updated: 2024/07/20 17:55:08 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_ab(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rr(a, b);
	index_s(*a);
	index_s(*b);
}

static void	rev_rotate_ab(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
	while (*b != cheapest->target_node && *a != cheapest)
		rrr(a, b);
	index_s(*a);
	index_s(*b);
}

static void	move_ab(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheap_node;
	
	cheap_node = get_cheap(*a);
	if (cheap_node->above_median && cheap_node->target_node->above_median)
		rotate_ab(a, b, cheap_node);
	else if (!(cheap_node->above_median) && !(cheap_node->target_node->above_median))
		rev_rotate_ab(a, b, cheap_node);
	push_init(a, cheap_node, 'a');
	push_init(b, cheap_node->target_node, 'b');
	pb(b, a);
}

static void	move_ba(t_stack_node **a, t_stack_node **b)
{
	push_init(a, (*b)->target_node, 'a');
	pa(a, b);
}

static void	min_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a);
		else
			rra(a);
	}
}

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	size_t	len_a;

	len_a = stack_size(*a);
	if (len_a-- > 3 && !check_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !check_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !check_sorted(*a))
	{
		init_na(*a, *b);
		move_ab(a, b);
	}
	sort_three(a);
	while(*b)
	{
		init_nb(*a,*b);
		move_ba(a, b);
	}
	index_s(*a);
	min_top(a);
}