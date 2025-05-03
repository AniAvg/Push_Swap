/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:31:30 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/03 11:43:22 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_with_error(int *arr)
{
	free(arr);
	ft_error();
}

void	fill_stack(t_stack **a, char **argv)
{
	int	i;
	int	j;
	int	arr_size;
	int	*unsorted;
	int	*sorted;

	unsorted = validate_args(argv, &arr_size);
	if (!unsorted || arr_size <= 0)
		free_with_error(unsorted);
	sorted = dup_array(unsorted, arr_size);
	if (!sorted)
		free_with_error(unsorted);
	if (!is_sorted(sorted, arr_size))
		sort_array(sorted, arr_size);
	else
		return ;
	i = 0;
	while (i < arr_size)
	{
		j = get_the_index(sorted, arr_size, unsorted[i]);
		ft_stackadd(a, ft_stacknew(j));
		i++;
	}
	free(sorted);
	free(unsorted);
}
