/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 17:24:02 by dde-carv          #+#    #+#             */
/*   Updated: 2024/07/30 14:11:15 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	syntax_error(char *n)
{
	int	len;

	len = 1;
	if (!(n[0] == 43 || n[0] == 45 || (n[0] >= 48 && n[0] <= 57)))
		return (1);
	if ((n[0] == 43 || n[0] == 45) && !(n[len] >= 48 && n[len] <= 57))
		return (1);
	while (n[len])
	{
		if (!(n[len] >= 48 && n[len] <= 57))
			return (1);
		len++;
	}
	return (0);
}

int	duplic_error(t_stack_node *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nbr == n)
			return (1);
		a = a->next;
	}
 	return (0);
}

void	free_stack(t_stack_node **s)
{
	t_stack_node	*tmp;
	t_stack_node	*current;
	
	if (!s)
		return ;
	current = *s;
	while (current)
	{
		tmp = current->next;
		current->nbr = 0;
		free(current);
		current = tmp;
	}
	*s = NULL;
}

void	free_errors(t_stack_node **a)
{
	free_stack(a);
	ft_printf("Error\n");
	exit(1);
}
