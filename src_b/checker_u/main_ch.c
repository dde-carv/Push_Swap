/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_ch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:01:08 by dde-carv          #+#    #+#             */
/*   Updated: 2024/08/05 14:40:01 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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
		free_errors(a, b);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char		*next_line;
	int		len;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	init_sa(&a, argv + 1);
	len = stack_size(a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		command_cmp(&a, &b, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (check_sorted(a) && stack_last(a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
	return (0);
}
