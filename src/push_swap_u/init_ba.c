/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 12:23:46 by dde-carv          #+#    #+#             */
/*   Updated: 2024/07/20 17:55:08 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	target_b(t_stack_node *a, t_stack_node *b)
{
	long		best_match;
	t_stack_node	*index_a;
	t_stack_node	*target;

	while (b)
	{
		best_match = LONG_MAX;
		index_a = a;
		while (index_a)
		{
			if (index_a->nbr > b->nbr && index_a->nbr < best_match)
			{
				best_match = index_a->nbr;
				target = index_a;
			}
			index_a = index_a->next;
		}
		if (best_match == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	init_nb(t_stack_node *a, t_stack_node *b)
{
	index_s(a);
	index_s(b);
	target_b(a, b);
}