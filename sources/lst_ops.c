/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anavagya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:10:26 by anavagya          #+#    #+#             */
/*   Updated: 2025/04/18 11:10:29 by anavagya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *lst;
	if (!tmp)
	{
		*lst = new;
		return ;
	}
	else
		tmp = tmp -> next;
	tmp -> next = new;
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->index = content;
	new_node->next = NULL;
	return (new_node);
}

t_stack	*ft_lstlast(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	ft_lstsize(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	ft_lstclear(t_stack **lst, void (*del)(void *))
{
	t_stack	*current;

	while (lst && *lst)
	{
		current = (*lst)->next;
		del((*lst)->index);
		free(*lst);
		*lst = current;
	}
	lst = NULL;
}
