#include "push_swap.h"

void	ft_sort_three(t_stack **a)
{
	int	max;

	max = get_max_index(*a);
	if ((*a)->index == max)
		ft_rotate(a, 'a');
	else if ((*a)->next->index == max)
		ft_rev_rotate(a, 'a');
	if ((*a)->index > (*a)->next->index)
		ft_swap(a, 'a');
}

// void	ft_sort_four(t_stack **a, t_stack **b)
// {
	
// }
