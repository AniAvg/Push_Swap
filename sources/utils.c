/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:32:22 by anavagya          #+#    #+#             */
/*   Updated: 2025/04/29 15:19:39 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	arr_len(int *arr)
{
	int	size;

	if (!arr)
		return (0);
	size = 0;
	while (arr[size] != 0)
		size++;
	return (size);
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
			if (arr[j] < arr[j + 1])
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

void	fill_stack(t_stack **a, char **argv)
{
	int	i;
	int	arr_size;
	int	*unsorted;
	int	*sorted;

	unsorted = validate_args(argv, &arr_size);
	if (!unsorted)
		ft_error();
	if (arr_size <= 0)
	{
		free(unsorted);
		ft_error();
	}
	sorted = dup_array(unsorted, arr_size);
	if (!sorted)
	{
		free(unsorted);
		ft_error();
	}
	if (!is_sorted(sorted, arr_size))
		sort_array(sorted, arr_size);
	else
		return ;
	i = 0;
	while (i < arr_size)
	{
		ft_stackadd(a, ft_stacknew(i));
		i++;
	}
	// while (i < arr_size)
	// {
	// 	if (unsorted[i] == sorted[i])
	// 	{
	// 		ft_stackadd(a, ft_stacknew(i));
	// 		break ;
	// 	}
	// 	i++;
	// }
	free(sorted);
	free(unsorted);
}
