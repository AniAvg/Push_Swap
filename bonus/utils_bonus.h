/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:10:11 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/03 13:10:32 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	get_the_index(int *arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int	*dup_array(int *arr, int size)
{
	int	i;
	int	*duplicate;

	i = 0;
	if (!arr || size < 0)
		return (NULL);
	duplicate = (int *)malloc(sizeof(int) * size);
	if (!duplicate)
		return (NULL);
	i = 0;
	while (i < size)
	{
		duplicate[i] = arr[i];
		i++;
	}
	return (duplicate);
}

int	is_sorted(int *arr, int size)
{
	int	i;

	if (!arr || size <= 0)
		return (0);
	if (size == 1)
		return (1);
	i = 0;
	while (i < size -1)
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	*sort_array(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	if (!arr || n <= 0)
		return (NULL);
	while (i < n)
	{
		j = 0;
		while (j < n - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}
