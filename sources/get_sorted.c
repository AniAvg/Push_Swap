#include "push_swap.h"

int	get_sorted(int *sorted, int size, int value)
{
	int	i;

	i = 0;
	while (sorted[i])
	{
		if (sorted[i] == value)
			return (i);
	}
	return (-1);
}

