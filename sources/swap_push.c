/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 17:28:10 by anavagya          #+#    #+#             */
/*   Updated: 2025/04/15 17:28:39 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack, char c)
{
	t_stack	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	if (c == 'a')
		ft_printf("sa\n");
	if (c == 'b')
		ft_printf("sb\n");
}

void	ft_swap_ab(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*a) || !(*b) || !(*a)->next || !(*b)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	ft_printf("ss\n");
}

void	ft_push(t_stack **a, t_stack **b, char c)
{
	t_stack	*tmp;

	if (c == 'a')
	{
		if (!(*b))
			return ;
		tmp = (*b);
		*b = (*b)->next;
		tmp->next = (*a); 
		*a = tmp;
		ft_printf("pa\n");
	}
	if (c == 'b')
	{
		if (!(*a))
			return ;
		tmp = (*a);
		*a = (*a)->next;
		tmp->next = (*b);
		tmp = (*b);
		*b = tmp;
		ft_printf("pb\n");
	}
}
