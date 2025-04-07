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

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[0] == '+' || str[0] == '-')
			i++;
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	args_len(char **argv)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (argv[i])
	{
		len += ft_strlen(argv[i]);
		i++;
	}
	return (len);
}

char	*join_args(char **argv)
{
	int		i;
	int		len;
	char	*args_string;

	i = 0;
	len = args_len(argv);
	args_string = (char *)malloc(sizeof(char) * len + 1);
	if (!args_string)
		return (NULL);
	while (argv[i])
	{
		args_string = ft_strjoin(argv[i], " ");
		if (argv[i + 1])
			args_string = ft_strjoin(args_string, argv[i + 1]);
		i++;
	}
	return (args_string);
}

void	esim(char **argv) //heto anuny poxel
{
	int		i;
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
		i++;
	}

	//sharunakeli

}
