/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:51:18 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/02 18:59:12 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_myatoi(const char *str)
{
	long	result;
	int		sign;

	if (!str || str[0] == '\0')
		ft_error();
	sign = 1;
	result = 0;
	// if (*str != '-' && *str != '+' && !ft_isdigit(*str))
	// 	ft_error();
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!ft_isdigit(*str))
		ft_error();
	if (*str == '0' && *(str + 1))
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			ft_error();
		str++;
	}
	if (*str != '\0') // "123abc"
		ft_error();
	return (sign * result);
}

char	*join_args(char **argv)
{
	int		i;
	char	*args_string;
	char	*tmp;

	i = 1;
	args_string = ft_strdup("");
	if (!args_string)
		return (NULL);
	while (argv[i])
	{
		if (argv[i][0] == '\0')
			ft_error();
		tmp = ft_strjoin(args_string, argv[i]);
		free(args_string);
		args_string = tmp;
		tmp = ft_strjoin(args_string, " ");
		free(args_string);
		args_string = tmp;
		i++;
	}
	return (args_string);
}

void	is_duplicate(int *num_array, int arr_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < arr_size)
	{
		j = 1;
		while (i + j < arr_size)
		{
			if (num_array[i] == num_array[i + j])
				ft_error();
			j++;
		}
		i++;
	}
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
	num_array = (int *)malloc(sizeof(int) * (count + 1));
	if (!num_array)
		return (NULL);
	i = 0;
	while (i < count)
	{
		num_array[i] = ft_myatoi(split_args[i]);
		free(split_args[i]);
		i++;
	}
	free(split_args);
	*size = count;
	is_duplicate(num_array, count);
	return (num_array);
}
