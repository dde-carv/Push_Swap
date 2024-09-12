/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-carv <dde-carv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:11:56 by dde-carv          #+#    #+#             */
/*   Updated: 2024/09/12 14:14:23 by dde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	int					above_median;
	int					cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int				syntax_error(char *n);
int				duplic_error(t_stack_node *a, int n);
void			free_stack(t_stack_node **s);
void			free_errors(t_stack_node **a, t_stack_node **b);
void			index_s(t_stack_node *s);
void			set_cheap(t_stack_node *s);
void			init_na(t_stack_node *a, t_stack_node *b);
void			init_nb(t_stack_node *a, t_stack_node *b);
void			init_sa(t_stack_node **a, t_stack_node **b, char **argv);
t_stack_node	*get_cheap(t_stack_node *s);
void			push_init(t_stack_node **s, t_stack_node *up_node, char s_name);
void			pa(t_stack_node **a, t_stack_node **b, int toprint);
void			pb(t_stack_node **b, t_stack_node **a, int toprint);
void			rra(t_stack_node **a, int toprint);
void			rrb(t_stack_node **b, int toprint);
void			rrr(t_stack_node **a, t_stack_node **b, int toprint);
void			ra(t_stack_node **a, int toprint);
void			rb(t_stack_node **b, int toprint);
void			rr(t_stack_node **a, t_stack_node **b, int toprint);
void			sort_stack(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);
void			sa(t_stack_node **a, int toprint);
void			sb(t_stack_node **b, int toprint);
void			ss(t_stack_node **a, t_stack_node **b, int toprint);
int				stack_size(t_stack_node *s);
t_stack_node	*stack_last(t_stack_node *s);
int				check_sorted(t_stack_node *s);
t_stack_node	*find_min(t_stack_node *s);
t_stack_node	*find_max(t_stack_node *s);
void			move_ab(t_stack_node **a, t_stack_node **b);
void			move_ba(t_stack_node **a, t_stack_node **b);
void			min_top(t_stack_node **a);

#endif
