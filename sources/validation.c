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

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

long	ft_atol(const char *str)
{
	long	result = 0;
	int		sign = 1;

	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int is_duplicate(int *arr, int len, int num) // kam el ogt strncmp
{
    int i;
    
    i = 0;
    while (i < len)
    {
        if (arr[i] == num)
            return (1);
        i++;
    }
    return (0);
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
	char    *tmp;

	i = 1;
	len = args_len(argv);
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

void	esim(char **argv)
{
	int		i;
	long    num;
	char	*args_string;
	char	**split_args;

	i = 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
	args_string = join_args(argv);
	split_args = ft_split(args_string, ' ');
	ftee(args_string);

	while (split_args[i])
	{
		if (!is_number(split_args[i]))
			ft_error();
		num = ft_atol(split_args[i]);
		if (num < -2147483 || num > 2147483647)
			ft_error();
		if (is_duplicate(numbers, i, num)
			ft_error();
		i++;
	}
	i = 0;
	
	//to be continued
}

/*
void	validate_args(char **argv)
{
	int		i = 0;
	char	*args_string = join_args(argv);
	char	**split_args = ft_split(args_string, ' ');
	int		*numbers;
	int		count = 0;

	while (split_args[count])
		count++;

	numbers = malloc(sizeof(int) * count);
	if (!numbers)
		ft_error();

	while (i < count)
	{
		if (!is_number(split_args[i]))
			ft_error();
		long num = ft_atol(split_args[i]);
		if (num < INT_MIN || num > INT_MAX)
			ft_error();
		if (is_duplicate(numbers, i, (int)num))
			ft_error();
		numbers[i] = (int)num;
		i++;
	}
	ftee(args_string);
	free(numbers);
}/*
