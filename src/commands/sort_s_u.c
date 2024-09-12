/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_s_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:04:40 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/12 14:15:54 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate_ab(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (*b != cheap->target_node && *a != cheap)
		rr(a, b, 42);
	index_s(*a);
	index_s(*b);
}

static void	rev_rot_ab(t_stack_node **a, t_stack_node **b, t_stack_node *cheap)
{
	while (*b != cheap->target_node && *a != cheap)
		rrr(a, b, 42);
	index_s(*a);
	index_s(*b);
}

void	move_ab(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheap_node;

	cheap_node = get_cheap(*a);
	if (cheap_node->above_median && cheap_node->target_node->above_median)
		rotate_ab(a, b, cheap_node);
	else if (!(cheap_node->above_median)
		&& !(cheap_node->target_node->above_median))
		rev_rot_ab(a, b, cheap_node);
	push_init(a, cheap_node, 'a');
	push_init(b, cheap_node->target_node, 'b');
	pb(b, a, 42);
}

void	move_ba(t_stack_node **a, t_stack_node **b)
{
	push_init(a, (*b)->target_node, 'a');
	pa(a, b, 42);
}

void	min_top(t_stack_node **a)
{
	while ((*a)->nbr != find_min(*a)->nbr)
	{
		if (find_min(*a)->above_median)
			ra(a, 42);
		else
			rra(a, 42);
	}
}
