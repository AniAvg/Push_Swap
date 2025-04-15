#include "push_swap.h"

void	ft_swap(t_stack **stack, int a)
{
	t_stack	*tmp;

	if (!(*stack) || !(*stack) -> next)
		return ;
	tmp = *stack; // tmp 1
	*stack = (*stack) -> next; // stack 2
	(*stack) -> next = tmp; // 2rdin tvecinq arajin@
	(*stack) = 
	if (a == 1)
		ft_printf("sa\n");
	if (a == 2)
		ft_printf("sb\\n");
}