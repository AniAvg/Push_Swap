/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:08:21 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/03 13:09:32 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	*validate_args(char **argv, int *size)
{
	int		i;
	int		count;
	int		*num_array;
	char	*args_string;
	char	**split_args;

	count = 0;
	args_string = join_args(argv);
	split_args = ft_split(args_string, ' ');
	free(args_string);
	while (split_args[count])
		count++;
	num_array = (int *)malloc(sizeof(int) * (count + 1));
	if (!num_array)
		return (NULL);
	i = -1;
	while (++i < count)
	{
		num_array[i] = ft_myatoi(split_args[i]);
		free(split_args[i]);
	}
	free(split_args);
	*size = count;
	is_duplicate(num_array, count);
	return (num_array);
}
