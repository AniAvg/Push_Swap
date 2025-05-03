/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:53:52 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/03 13:46:45 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	execute_instruction(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		return (ft_swap(a, 'a'), 1);
	else if ((ft_strcmp(line, "sb\n") == 0))
		return (ft_swap(b, 'b'), 1);
	else if ((ft_strcmp(line, "ss\n") == 0))
		return (ft_swap_ab(a, b), 1);
	else if ((ft_strcmp(line, "pa\n") == 0))
		return (ft_push(a, b, 'a'), 1);
	else if ((ft_strcmp(line, "pb\n") == 0))
		return (ft_push(a, b, 'b'), 1);
	else if ((ft_strcmp(line, "ra\n") == 0))
		return (ft_rotate(a, 'a'), 1);
	else if ((ft_strcmp(line, "rb\n") == 0))
		return (ft_rotate(b, 'b'), 1);
	else if ((ft_strcmp(line, "rr\n") == 0))
		return (ft_rotate_ab(a, b), 1);
	else if ((ft_strcmp(line, "rra\n") == 0))
		return (ft_rev_rotate(a, 'a'), 1);
	else if ((ft_strcmp(line, "rrb\n") == 0))
		return (ft_rev_rotate(b, 'b'), 1);
	else if ((ft_strcmp(line, "rrr\n") == 0))
		return (ft_rev_rotate_ab(a, b), 1);
	return (0);
}
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*line;

	if (argc <= 1)
		return (0);
	return (0);
}