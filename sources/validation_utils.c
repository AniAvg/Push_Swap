/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:43:42 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/06 15:03:57 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	ft_while(const char **str, long *result, int sign)
// {
// 	while (ft_isdigit(**str))
// 	{
// 		*result = *result * 10 + (**str - '0');
// 		if (*result * sign > INT_MAX || *result * sign < INT_MIN)
// 			ft_error();
// 		(*str)++;
// 	}
// }
///////////////
int	ft_myatoi(const char *str)
{
	int	i;
	long	result;
	int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - '0';
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return 0;
		i++;
	}
	return (sign * result);
}
////////////////
// int	ft_myatoi(const char *str)
// {
// 	long	result;
// 	int		sign;

// 	if (!str || str[0] == '\0')
// 		ft_error();
// 	sign = 1;
// 	result = 0;
// 	if (*str == '+' || *str == '-')
// 	{
// 		if (*str == '-')
// 			sign = -1;
// 		str++;
// 	}
// 	if (!ft_isdigit(*str))
// 		ft_error();
// 	if (*str == '0' && *(str + 1))
// 		str++;
// 	ft_while(&str, &result, sign);
// 	if (*str != '\0')
// 		ft_error();
// 	return (sign * result);
// }

int	ft_is_only_space(const char *str)
{
	if (!str)
		return (1);
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			return (0);
		str++;
	}
	return (1);
}

char	*join_args(char **argv)
{
	int		i;
	char	*args_string;
	char	*tmp;

	i = 1;
	args_string = ft_strdup("");
	if (!args_string)
		return (free(args_string), NULL);
	while (argv[i])
	{
		if (argv[i][0] == '\0' || ft_is_only_space(argv[i]))
			free_with_error(NULL, args_string);
		tmp = ft_strjoin(args_string, argv[i]);
		free(args_string);
		args_string = tmp;
		tmp = ft_strjoin(args_string, " ");
		free(args_string);
		args_string = tmp;
		i++;
	}
	if (ft_is_only_space(args_string) || args_string[0] == '\0')
		free_with_error(NULL, args_string);
	return (args_string);
}

int	is_duplicate(int *num_array, int arr_size)
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
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_int_limit(int *num_array)
{
	int	i;

	i = 0;
	while (num_array[i])
	{
		if (num_array[i] > 2147483647)
			return (0);
		i++;
	}
	return (1);
}
