/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:09:35 by dde-carv          #+#    #+#             */
/*   Updated: 2024/08/05 12:50:43 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*big_node;

	big_node = find_max(*a);
	if (big_node == *a)
		ra(a, 42);
	else if ((*a)->next == big_node)
		rra(a, 42);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, 42);
}