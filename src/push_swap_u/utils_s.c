/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:52:39 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/12 14:23:21 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	stack_size(t_stack_node *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s)
	{
		s = s->next;
		len++;
	}
	return (len);
}

t_stack_node	*stack_last(t_stack_node *s)
{
	t_stack_node	*last;

	if (!s)
		return (NULL);
	while (s)
	{
		last = s;
		s = s->next;
	}
	return (last);
}

int	check_sorted(t_stack_node *s)
{
	if (!s)
		return (1);
	while (s->next)
	{
		if (s->nbr > s->next->nbr)
			return (0);
		s = s->next;
	}
	return (1);
}

t_stack_node	*find_min(t_stack_node *s)
{
	long			min;
	t_stack_node	*min_node;

	if (!s)
		return (NULL);
	min = LONG_MAX;
	while (s)
	{
		if (s->nbr < min)
		{
			min = s->nbr;
			min_node = s;
		}
		s = s->next;
	}
	return (min_node);
}

t_stack_node	*find_max(t_stack_node *s)
{
	long			max;
	t_stack_node	*max_node;

	if (!s)
		return (NULL);
	max = LONG_MIN;
	while (s)
	{
		if (s->nbr > max)
		{
			max = s->nbr;
			max_node = s;
		}
		s = s->next;
	}
	return (max_node);
}
