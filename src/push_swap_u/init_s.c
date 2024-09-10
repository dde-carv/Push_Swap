/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:25:16 by dde-carv          #+#    #+#             */
/*   Updated: 2024/08/05 14:45:39 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static long	ft_atol(const char *str)
{
	int	len;
	int	neg;
	long	nb;

	len = 0;
	neg = 1;
	nb = 0;
	while (str[len] == 12 || str[len] == 10 || str[len] == 13
		|| str[len] == 9 || str[len] == 11 || str[len] == 32)
		len++;
	if (str[len] == 43)
		len++;
	else if (str[len] == 45)
	{
		neg *= -1;
		len++;
	}
	while (ft_isdigit(str[len]))
	{
		nb = (nb * 10) + (str[len] - 48);
		len++;
	}
	nb = nb * neg;
	return (nb);
}

static void	append_node(t_stack_node **s, int n)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!s)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = n;
	if(!(*s))
	{
		*s = node;
		node->prev = NULL;
	}
	else
	{
		last_node = stack_last(*s);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	init_sa(t_stack_node **a, t_stack_node **b, char **argv)
{
	long	n;
	int	len;

	len = 0;
	while (argv[len])
	{
		if (syntax_error(argv[len]))
			free_errors(a, b);
		n = ft_atol(argv[len]);
		if (n < INT_MIN || n > INT_MAX)
			free_errors(a, b);
		if (duplic_error(*a, (int)n))
			free_errors(a, b);
		append_node(a, (int)n);
		len++;
	}
}

t_stack_node	*get_cheap(t_stack_node *s)
{
	if (!s)
		return (NULL);
	while (s)
	{
		if (s->cheapest)
			return (s);
		s = s->next;
	}
	return (NULL);
}

void	push_init(t_stack_node **s, t_stack_node *up_node, char s_name)
{
	while (*s != up_node)
	{
		if (s_name == 'a')
		{
			if (up_node->above_median)
				ra(s, 42);
			else
				rra(s, 42);
		}
		else if (s_name == 'b')
		{
			if (up_node->above_median)
				rb(s, 42);
			else
				rrb(s, 42);
		}
	}
}