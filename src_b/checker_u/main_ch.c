/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:01:08 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/19 11:23:28 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	free_error_check(t_stack_node **a, t_stack_node **b, char *command)
{
	free_stack(a);
	free_stack(b);
	free(command);
	ft_printf("Error\n");
	exit(1);
}

static void	command_cmp(t_stack_node **a, t_stack_node **b, char *command)
{
	if (!ft_strncmp(command, "pa\n", ft_strlen(command)))
		pa(a, b, 0);
	else if (!ft_strncmp(command, "pb\n", ft_strlen(command)))
		pb(b, a, 0);
	else if (!ft_strncmp(command, "sa\n", ft_strlen(command)))
		sa(a, 0);
	else if (!ft_strncmp(command, "sb\n", ft_strlen(command)))
		sb(b, 0);
	else if (!ft_strncmp(command, "ss\n", ft_strlen(command)))
		ss(a, b, 0);
	else if (!ft_strncmp(command, "ra\n", ft_strlen(command)))
		ra(a, 0);
	else if (!ft_strncmp(command, "rb\n", ft_strlen(command)))
		rb(b, 0);
	else if (!ft_strncmp(command, "rr\n", ft_strlen(command)))
		rr(a, b, 0);
	else if (!ft_strncmp(command, "rra\n", ft_strlen(command)))
		rra(a, 0);
	else if (!ft_strncmp(command, "rrb\n", ft_strlen(command)))
		rrb(b, 0);
	else if (!ft_strncmp(command, "rrr\n", ft_strlen(command)))
		rrr(a, b, 0);
	else
		free_error_check(a, b, command);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			*next_line;
	int				len;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	init_sa(&a, &b, argv + 1);
	len = stack_size(a);
	next_line = get_next_line(0);
	while (next_line)
	{
		command_cmp(&a, &b, next_line);
		free(next_line);
		next_line = get_next_line(0);
	}
	if (check_sorted(a) && stack_size(a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stack(&a), free_stack(&b), free(next_line), 0);
}
