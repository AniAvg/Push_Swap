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

# include "libft.h"
# include <unistd.h> // read(), write()
# include <stdlib.h> // malloc(), free(), exit()
# include <limits.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}	t_stack;

void	ft_error(void);
int		ft_myatoi(const char *str);
char	*join_args(char **argv);
void	is_duplicate(long *num_array);
int		*validate_args(char **argv);

void	ft_lstadd(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content);

void	fill_stack(t_stack *a, char **argv);
int		is_sorted(t_stack *a);

#endif
