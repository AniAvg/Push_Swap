/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 17:28:04 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/08 13:43:11 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	ft_swap_ab(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
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
	}
	if (c == 'b')
	{
		if (!(*a))
			return ;
		tmp = (*a);
		*a = (*a)->next;
		tmp->next = (*b);
		*b = tmp;
	}
}
