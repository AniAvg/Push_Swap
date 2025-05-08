/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_revrotate_ops_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:23:41 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/08 13:47:05 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_rotate(t_stack **stack)
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
}

void	ft_rotate_ab(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
}

void	ft_rev_rotate(t_stack **stack)
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
}

void	ft_rev_rotate_ab(t_stack **a, t_stack **b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
}
