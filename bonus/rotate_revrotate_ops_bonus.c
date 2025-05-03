/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_revrotate_ops_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:23:41 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/03 13:41:21 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_rotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	last = ft_stacklast(*stack);
	last->next = tmp;
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
}

void	ft_rotate_ab(t_stack **a, t_stack **b)
{
	ft_rotate(a, SILENT);
	ft_rotate(b, SILENT);
	ft_printf("rr\n");
}

void	ft_rev_rotate(t_stack **stack, char c)
{
	t_stack	*prev_last;
	t_stack	*last;

	while (!(*stack) || !(*stack)->next)
		return ;
	prev_last = *stack;
	while (prev_last->next && prev_last->next->next)
		prev_last = prev_last->next;
	last = prev_last->next;
	prev_last->next = NULL;
	last->next = *stack;
	*stack = last;
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
}

void	ft_rev_rotate_ab(t_stack **a, t_stack **b)
{
	ft_rev_rotate(a, SILENT);
	ft_rev_rotate(b, SILENT);
	ft_printf("rrr\n");
}
