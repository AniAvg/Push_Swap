/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:52:20 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/02 18:55:46 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_position(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

void	move_to_top(t_stack **stack, int index, char c)
{
	int	pos;
	int	size;

	size = ft_stacksize(*stack);
	pos = get_position(*stack, index);
	if (pos <= size / 2)
	{
		while ((*stack)->index != index)
			ft_rotate(stack, c);
	}
	else
	{
		while ((*stack)->index != index)
			ft_rev_rotate(stack, c);
	}
}

void	push_back_to_a(t_stack **a, t_stack **b)
{
	int	max_index;

	while (*b)
	{
		max_index = get_max_index(*b);
		move_to_top(b, max_index, 'b');
		ft_push(a, b, 'a');
	}
}

void	sorting(t_stack **a, t_stack **b)
{
	int	size;
	
	size = ft_stacksize(*a);
	if (size == 2)
		ft_swap(a, 'a');
	else if (size == 3)
		ft_sort_three(a);
	else if (size == 4)
		ft_sort_four(a, b);
	else if (size == 5)
		ft_sort_five(a, b);
	else
		chunck_sort(a, b);
}
