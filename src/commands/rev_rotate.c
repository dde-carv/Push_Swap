/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:17:13 by dde-carv          #+#    #+#             */
/*   Updated: 2024/08/05 12:49:35 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rev_rotate(t_stack_node **s)
{
	t_stack_node	*last;

	if(!*s || !(*s)->next)
		return ;
	last = stack_last(*s);
	last->prev->next = NULL;
	last->next = *s;
	last->prev = NULL;
	*s = last;
	last->next->prev = last;
}

void	rra(t_stack_node **a, int toprint)
{
	rev_rotate(a);
	if (toprint)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, int toprint)
{
	rev_rotate(b);
	if (toprint)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, int toprint)
{
	rev_rotate(a);
	rev_rotate(b);
	if (toprint)
		ft_printf("rrr\n");
}