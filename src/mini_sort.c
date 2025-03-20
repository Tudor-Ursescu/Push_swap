/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 10:36:17 by tursescu          #+#    #+#             */
/*   Updated: 2025/03/20 14:36:24 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_min(t_list **stack)
{
	int		i;
	int		min_val;
	int		index;
	t_list	*temp;

	temp = *stack;
	i = 0;
	index = 0;
	min_val = temp->data;
	while (temp != NULL)
	{
		if (min_val > temp->data)
		{
			min_val = temp->data;
			index = i;
		}
		i++;
		temp = temp->next;
	}
	return (index);
}

void	three_arg_sort(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
}

void	four_arg_sort(t_list **stack_a, t_list **stack_b)
{
	if (find_min(stack_a) == 1)
		sa(stack_a);
	else if (find_min(stack_a) == 2)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (find_min(stack_a) == 3)
		rra(stack_a);
	pb(stack_a, stack_b);
	three_arg_sort(stack_a);
	pa(stack_a, stack_b);
}

void	five_arg_sort(t_list **stack_a, t_list **stack_b)
{
	if (find_min(stack_a) == 1)
		sa(stack_a);
	else if (find_min(stack_a) == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (find_min(stack_a) == 3)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (find_min(stack_a) == 4)
		rra(stack_a);
	pb(stack_a, stack_b);
	four_arg_sort(stack_a, stack_b);
	pa(stack_a, stack_b);
}
