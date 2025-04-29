/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:52:27 by anavagya          #+#    #+#             */
/*   Updated: 2025/04/29 12:20:32 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_index(t_stack *a)
{
	int	max_index;

	if (!a)
		return (-1);
	max_index = a->index;
	while (a)
	{
		if (a->index > max_index)
			max_index = a->index;
		a = a->next;
	}
	return (max_index);
}

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
		return (0);
	while (1)
	{
		if (i * i >= nb)
		{
			if (i * i == nb)
				return (i);
			else
				return (i - 1);
		}
		i++;
	}
	return (0);
}

void	chunck_sort(t_stack **a, t_stack **b)
{
	int	n;
	int	counter;
	//int	max_index;
	counter = 0;
	n = ft_sqrt(ft_stacksize(*a)) * 3 / 2;
	//max_index = get_max_index(a);
	while (*a)
	{
		if ((*a)->index <= counter)
		{
			ft_push(a, b, 'b');
			ft_rotate(b, 'b');
			counter++;
		}
		else if ((*a)->index <= counter + n)
		{
			ft_push(a, b, 'b');
			counter++;
		}
		else
			ft_rotate(a, 'a');
	}
	push_back_to_a(a, b);
}
