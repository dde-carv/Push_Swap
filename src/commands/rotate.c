/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:02:41 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/12 13:57:15 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rotate(t_stack_node **s)
{
	t_stack_node	*last_node;

	if (!*s || !(*s)->next)
		return ;
	last_node = stack_last(*s);
	last_node->next = *s;
	*s = (*s)->next;
	(*s)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, int toprint)
{
	rotate(a);
	if (toprint)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, int toprint)
{
	rotate(b);
	if (toprint)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, int toprint)
{
	rotate(a);
	rotate(b);
	if (toprint)
		ft_printf("rr\n");
}
