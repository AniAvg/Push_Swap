/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:51:18 by anavagya          #+#    #+#             */
/*   Updated: 2025/04/05 13:51:20 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*validate_args(char **argv)
{
	int		count;
	long	*num_array;
	char	*args_string;
	char	**split_args;

	count = 0;
	args_string = join_args(argv);
	split_args = ft_split(args_string, ' ');
	ftee(args_string);
	while (split_args[count])
		count++;
	num_array = (long *)malloc(sizeof(long) * (count + 1));
	if (!num_array)
		return (NULL);
	count = 0;
	while (split_args[count])
	{
		num_array[count] = ft_myatoi(split_args[count]);
		count++;
	}
	num_array[count] = '\0';
	free(args_string);
	is_duplicate(num_array);
	return (num_array);
}
