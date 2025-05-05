/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:51:18 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/05 17:32:34 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_free(char **arr)
{
	int	i;

	i = 0;
	if (!arr || !*arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int is_valid_number(char *num)
{
	int i = 0;
	if(*num == '+' || *num == '-')
		num++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]) || ft_strlen(num) > 10)
			return (0);
		i++;	
	}
	return (1);
}

int is_valid_arg(char **spilted)
{
	int i;

	if (!spilted || !(*spilted))
		return 0;
	i = 0;
	while (spilted[i])
	{
		if (!is_valid_number(spilted[i]))
			return (0);
		i++;
	}
	return (1);
}

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
	if (!is_valid_arg(split_args))
	{
		ft_free(split_args);
		ft_error();
	}
	num_array = (int *)malloc(sizeof(int) * (count + 1));// +1
	if (!num_array)
		return (ft_free(split_args), NULL);
	i = -1;
	while (++i < count)
		num_array[i] = ft_myatoi(split_args[i]);
	*size = count;
	if (!is_duplicate(num_array, count))
	{
		ft_free(split_args);
		free_with_error(num_array);
	}
	ft_free(split_args);
	return (num_array);
}
