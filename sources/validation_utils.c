/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 17:50:36 by anavagya          #+#    #+#             */
/*   Updated: 2025/04/08 17:50:38 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_myatoi(const char *str)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	if (*str != '-' && *str != '+' && !ft_isdigit(*str))
		ft_error();
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '0' && *(str +1))
		str++;
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			ft_error();
		str++;
	}
	return (sign * result);
}

int	args_len(char **argv)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (argv[i])
	{
		len += ft_strlen(argv[i]) + 1;
		i++;
	}
	return (len);
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
		tmp = ft_strjoin(args_string, argv[i]);
		free(args_string);
		args_string = tmp;
		if (argv[i + 1])
		{
			tmp = ft_strjoin(args_string, " ");
			free(args_string);
			args_string = tmp;
		}
		i++;
	}
	return (args_string);
}

void	is_duplicate(long *num_array)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 1;
	count = 0;
	while (num_array[count])
		count++;
	while (num_array[i])
	{
		while (i + j < count)
		{
			if (num_array[i] == num_array[i + j])
				ft_error();
			j++;
		}
		i++;
	}
}
