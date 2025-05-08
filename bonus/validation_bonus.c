/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:08:21 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/08 16:22:20 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"


int	is_int_limit(char *num, int sign)
{
	char	*int_min;
	char	*int_max;

	int_min = "2147483648";
	int_max = "2147483647";
	if (sign == 0)
	{
		if (ft_strlen(num) > 10)
			return (0);
		if (ft_strlen(num) < 10)
			return (1);
		return (ft_strncmp(num, int_min, 11) <= 0);
	}
	else
	{
		if (*num == '+')
			num++;
		if (ft_strlen(num) > 10)
			return (0);
		if (ft_strlen(num) < 10)
			return (1);
		return (ft_strncmp(num, int_max, 10) <= 0);
	}
}

int	is_valid_number(char *num)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (*num == '+')
	{
		sign = 1;
		num++;
	}
	if (*num == '-')
	{
		sign = 0;
		num++;
	}
	if (ft_strlen(num) == 0)
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]) || ft_strlen(num) > 10)
			return (0);
		i++;
	}
	return (is_int_limit(num, sign));
}

int	is_valid_arg(char **spilted)
{
	int	i;

	if (!spilted || !(*spilted))
		return (0);
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
		free_with_error(split_args, NULL);
	num_array = (int *)malloc(sizeof(int) * (count + 1));
	if (!num_array)
		return (ft_free(split_args), NULL);
	i = -1;
	while (++i < count)
		num_array[i] = ft_atoi(split_args[i]);
	*size = count;
	if (!is_duplicate(num_array, count))
		free_with_error(split_args, num_array);
	ft_free(split_args);
	return (num_array);
}
