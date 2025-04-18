/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:16:08 by anavagya          #+#    #+#             */
/*   Updated: 2025/04/05 11:20:30 by anavagya         ###   ########.fr       */
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
	int				num;
	struct s_stack	*next;
}	t_stack;
//validation.c
int		ft_myatoi(const char *str);
char	*join_args(char **argv);
void	is_duplicate(long *num_array);
int		*validate_args(char **argv);
//lst_ops.c
void	ft_lstadd(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *stack);
t_stack	*ft_lstbeforelast(t_stack *stack);
// utils.c
void	ft_error(void);
void	fill_stack(t_stack *a, char **argv);
int		is_sorted(t_stack *a);
// push_swap_ops.c
void	ft_swap(t_stack **stack, char c);
void	ft_swap_ab(t_stack **a, t_stack **b);
void	ft_push(t_stack **a, t_stack **b, char c);
// rotate_revrotate_ops.c
void	ft_rotate(t_stack **stack, char c);
void	ft_rotate_ab(t_stack **a, t_stack **b);
void	ft_rev_rotate(t_stack **stack, char c);
void	ft_rrr(t_stack **a, t_stack **b);

#endif
