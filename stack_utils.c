/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:46:55 by tursescu          #+#    #+#             */
/*   Updated: 2024/08/19 16:44:15 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_list *stack)
{
	int		size;

	if (!stack)
		return (0);
	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_list	*stack_bottom(t_list *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_list	*stack_second_last(t_list *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_append_end(t_list **stack, t_list *new)
{
	t_list	*end;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	end = stack_bottom(*stack);
	end->next = new;
}

t_list	*stack_new(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}
