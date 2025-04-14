/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:32:22 by anavagya          #+#    #+#             */
/*   Updated: 2025/04/14 12:32:25 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	fill_stack(t_stack *a, char **argv)
{
	int	i;
	int	*num_array;

	i = 0;
	num_array = validate_args(argv);
	if (!num_array)
	{
		free(num_array);
		ft_error();
	}
	while (num_array[i])
	{
		ft_lstadd(a, ft_lstnew(num_array[i]));
		i++;
	}
}

int	is_sorted(t_stack *a)
{
	int	nb;

	if (!a)
		return (0);
	nb = a -> num;
	while (a)
	{
		if (a -> num < nb)
			return (0);
		nb = a -> num;
		a = a -> next;
	}
	return (1);
}
