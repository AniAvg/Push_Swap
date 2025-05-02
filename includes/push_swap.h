/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <anavagya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:16:08 by anavagya          #+#    #+#             */
/*   Updated: 2025/05/02 18:55:00 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define SILENT 'x'

# include "libft.h"
# include <unistd.h> // read(), write()
# include <stdlib.h> // malloc(), free(), exit()
# include <limits.h>

typedef struct s_stack
{
	int				index;
	struct s_stack	*next;
}	t_stack;
// validation.c
int		ft_myatoi(const char *str);
char	*join_args(char **argv);
void	is_duplicate(int *num_array, int size);
int		*validate_args(char **argv, int *size);
// stack_ops.c
void	ft_stackadd(t_stack **stack, t_stack *new);
t_stack	*ft_stacknew(int content);
t_stack	*ft_stacklast(t_stack *stack);
int		ft_stacksize(t_stack *stack);
void	ft_stackclear(t_stack **stack);
// utils.c
void	ft_error(void);
int		get_the_index(int *arr, int size, int value);
int		*dup_array(int *arr, int size);
int		is_sorted(int *arr, int size);
int		*sort_array(int *arr, int n);
void	fill_stack(t_stack **a, char **argv);
// push_swap_ops.c
void	ft_swap(t_stack **stack, char c);
void	ft_swap_ab(t_stack **a, t_stack **b);
void	ft_push(t_stack **a, t_stack **b, char c);
// rotate_revrotate_ops.c
void	ft_rotate(t_stack **stack, char c);
void	ft_rotate_ab(t_stack **a, t_stack **b);
void	ft_rev_rotate(t_stack **stack, char c);
void	ft_rrr(t_stack **a, t_stack **b);
// sort.c
int		get_max_index(t_stack *a);
int		ft_sqrt(int nb);
void	chunck_sort(t_stack **a, t_stack **b);
// final_sort.c
int		get_position(t_stack *stack, int index);
void	move_to_top(t_stack **stack, int index, char c);
void	push_back_to_a(t_stack **a, t_stack **b);
void	sorting(t_stack **a, t_stack **b);
//simple_sort.c
void	ft_sort_three(t_stack **a);
void	ft_sort_four(t_stack **a, t_stack **b);
void	ft_sort_five(t_stack **a, t_stack **b);
// push_swap.c

#endif
