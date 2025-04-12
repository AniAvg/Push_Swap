#include "push_swap.h"

void	fill_stack(t_stack *a, int *num_array, char **argv)
{
	int	i;

	i = 0;
	num_array = validate_args(argv);
	if (!num_array)
	{
		free(num_array);
		ft_error();
	}
	while (num_array[i])
	{
		ft_lstadd(a, ft_lstnew(num_array[i]));
		i++;
	}
}

int	is_sorted(t_stack *a)
{
	t_stack	tmp;
	
	
}
