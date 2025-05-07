/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 12:53:52 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/07 17:41:07 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_stack_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next)
	{
		if (stack->index > stack->next->index)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	execute_instruction(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp(line, "sa\n", 3) == 0)
		return (ft_swap(a, 'a'), 1);
	else if ((ft_strncmp(line, "sb\n", 3) == 0))
		return (ft_swap(b, 'b'), 1);
	else if ((ft_strncmp(line, "ss\n", 3) == 0))
		return (ft_swap_ab(a, b), 1);
	else if ((ft_strncmp(line, "pa\n", 3) == 0))
		return (ft_push(a, b, 'a'), 1);
	else if ((ft_strncmp(line, "pb\n", 3) == 0))
		return (ft_push(a, b, 'b'), 1);
	else if ((ft_strncmp(line, "ra\n", 3) == 0))
		return (ft_rotate(a, 'a'), 1);
	else if ((ft_strncmp(line, "rb\n", 3) == 0))
		return (ft_rotate(b, 'b'), 1);
	else if ((ft_strncmp(line, "rr\n", 3) == 0))
		return (ft_rotate_ab(a, b), 1);
	else if ((ft_strncmp(line, "rra\n", 4) == 0))
		return (ft_rev_rotate(a, 'a'), 1);
	else if ((ft_strncmp(line, "rrb\n", 4) == 0))
		return (ft_rev_rotate(b, 'b'), 1);
	else if ((ft_strncmp(line, "rrr\n", 4) == 0))
		return (ft_rev_rotate_ab(a, b), 1);
	return (0);
}

static int	read_instruction(t_stack **a, t_stack **b)
{
	char	*line;

	*b = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
		{
			if (!(*b))
				return (1);
			ft_printf("KO\n");
			return (0);
		}
		if (!execute_instruction(line, a, b))
		{
			write(2, "Error\n", 6);
			free(line);
			return (0);
		}
		free(line);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		return (0);
	fill_stack(&a, argv);
	ft_stackclear(&a);
	if (!read_instruction(&a, &b))
	{
		ft_stackclear(&a);
		ft_stackclear(&b);
		return (1);
	}
	if (is_stack_sorted(a) && b == NULL)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_stackclear(&a);
	ft_stackclear(&b);
	return (0);
}
