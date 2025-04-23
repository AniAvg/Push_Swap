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

int	arr_len(int *arr)
{
	int	size;

	if (!arr)
		return (NULL);
	size = 0;
	while (arr[size])
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

	if (!arr || size < 0)
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
	j = 0;
	if (!arr)
		return (NULL);
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (arr[i] < arr[j])
			{
				tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

void	fill_stack(t_stack *a, char **argv)
{
	int	i;
	int	j;
	int	*unsorted;
	int	*sorted;

	unsorted = validate_args(argv);
	if (!unsorted)
		ft_error();
	sorted = dup_array(unsorted, arr_len(unsorted));
	if (!sorted)
	{
		free(unsorted);
		ft_error();
	}
	if (!is_sorted(sorted, arr_len(sorted)))
		sort_array(sorted, arr_len(sorted));
	i = 0;
	j = 0;
	while (i < arr_len(sorted))
	{
		j = 0;
		while (j < arr_len(sorted))
		{
			if (unsorted[i] == sorted[j])
			{
				ft_lstadd(a, ft_lstnew(j));
				break ;
			}
			j++;
		}
		i++;
	}
	free(sorted);
	free(unsorted);
}
