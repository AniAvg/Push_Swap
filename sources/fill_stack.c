/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 11:31:30 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/06 14:27:59 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_with_error(char **str, void *arr)
{
	ft_free(str);
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
		free_with_error(NULL, unsorted);
	sorted = dup_array(unsorted, arr_size);
	if (!sorted)
		free_with_error(NULL, unsorted);
	if (!is_sorted(sorted, arr_size))
		sort_array(sorted, arr_size);
	else
		return (free(sorted), free(unsorted));
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
