/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:23:57 by dde-carv          #+#    #+#             */
/*   Updated: 2024/07/25 12:28:31 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	index_s(t_stack_node *s)
{
	size_t	len;
	size_t	mid;

	len = 0;
	if (!s)
		return ;
	mid = stack_size(s) / 2;
	while (s)
	{
		s->index = len;
		if (len <= mid)
			s->above_median = 1;
		else
			s->above_median = 0;
	s = s->next;
	len++;
	}
}

static void	target_a(t_stack_node *a, t_stack_node *b)
{
	long		best_match;
	t_stack_node	*index_b;
	t_stack_node	*target;

	while (a)
	{
		best_match = LONG_MIN;
		index_b = b;
		while (index_b)
		{
			if (index_b->nbr < a->nbr && index_b->nbr > best_match)
			{
				best_match = index_b->nbr;
				target = index_b;
			}
			index_b = index_b->next;
		}
		if (best_match == LONG_MIN)
			a->target_node = find_max(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

static void	cost_anal_a(t_stack_node *a, t_stack_node *b)
{
	size_t	len_a;
	size_t	len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if(!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - a->target_node->index;
		a = a->next;
	}
}

void	set_cheap(t_stack_node *s)
{
	long		cheap_value;
	t_stack_node	*cheap_node;

	if (!s)
		return ;
	cheap_value = LONG_MAX;
	while (s)
	{
		if (s->push_cost < cheap_value)
		{
			cheap_value = s->push_cost;
			cheap_node = s;
		}
		s = s->next;
	}
	cheap_node->cheapest = 1;
}

void	init_na(t_stack_node *a, t_stack_node *b)
{
	index_s(a);
	index_s(b);
	target_a(a, b);
	cost_anal_a(a, b);
	set_cheap(a);
}