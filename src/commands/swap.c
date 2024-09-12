/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:17:36 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/12 14:18:33 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node **a, int toprint)
{
	swap(a);
	if (toprint)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, int toprint)
{
	swap(b);
	if (toprint)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, int toprint)
{
	swap(a);
	swap(b);
	if (toprint)
		ft_printf("sb\n");
}
