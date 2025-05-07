/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:09:09 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/07 17:13:51 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
