/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:43:10 by dde-carv          #+#    #+#             */
/*   Updated: 2024/07/25 12:35:12 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdio.h>

static void print_list(t_stack_node *s)
{
    size_t i = 0;
    while (s != NULL)
    {
        printf("Node %ld: %d\n", i, s->nbr);
	s = s->next;
        i++;
    }
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;


	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_sa(&a, argv + 1);
	print_list(a);
	if (!check_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else
			sort_stack(&a, &b);
	}
	print_list(a);
	free_stack(&a);
	return (0);
}
