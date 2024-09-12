/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:16:10 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/12 14:16:59 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_stack(t_stack_node **a, t_stack_node **b)
{
	size_t	len_a;

	len_a = stack_size(*a);
	if (len_a-- > 3 && !check_sorted(*a))
		pb(b, a, 42);
	if (len_a-- > 3 && !check_sorted(*a))
		pb(b, a, 42);
	while (len_a-- > 3 && !check_sorted(*a))
	{
		init_na(*a, *b);
		move_ab(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nb(*a,*b);
		move_ba(a, b);
	}
	index_s(*a);
	min_top(a);
}
