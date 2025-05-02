#include "push_swap.h"

void	ft_sort_three(t_stack **a)
{
	int	max_index;

	max_index = get_max_index(*a);
	if ((*a)->index == max_index)
		ft_rotate(a, 'a'); // 2 0 1
	if ((*a)->next->index == max_index) 
		ft_rev_rotate(a, 'a');
	if ((*a)->index > (*a)->next->index)
		ft_swap(a, 'a');
}
 
void	ft_sort_four(t_stack **a, t_stack **b)
{
	int	max_index;
	int	pos;

	max_index = get_max_index(*a);
	pos = get_position(*a, max_index);
	while (pos != 0)
	{
		ft_rotate(a, 'a');
		pos = get_position(*a, max_index);
	}
	ft_push(a, b, 'b');
	ft_sort_three(a);
	ft_push(a, b, 'a');
	ft_rotate(a, 'a');
}

void	ft_sort_five(t_stack **a, t_stack **b)
{
	int	pos;
	int	max_index;

	max_index = get_max_index(*a);
	pos = get_position(*a, max_index);
	while (pos != 0)
	{
		ft_rotate(a, 'a');
		pos = get_position(*a, max_index);
	}
	ft_push(a, b, 'b');
	ft_sort_four(a, b);
	ft_push(a, b, 'a');
	ft_rotate(a, 'a');
}
