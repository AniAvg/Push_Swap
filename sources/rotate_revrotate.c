/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_revrotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:26:50 by anavagya          #+#    #+#             */
/*   Updated: 2025/04/15 17:27:11 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	last = ft_lstlast(*stack);
	last->next = tmp;
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
}

void	ft_rotate_ab(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!(*a) || !(*b) || !(*a)->next || !(*b)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	last = ft_lstlast(*a);
	last->next = tmp;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	last = ft_lstlast(*b);
	last->next = tmp;
	ft_printf("rr\n");
}

void	ft_rev_rotate(t_stack **stack, char c)
{
	t_stack	*tmp;

	while ((*stack)->next && (*stack)->next->next)
		stack = stack->next;
	// uf el haves chka
		
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
}