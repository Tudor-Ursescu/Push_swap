/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 09:31:13 by tursescu          #+#    #+#             */
/*   Updated: 2025/03/20 14:36:42 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	max_bits(t_list **stack)
{
	t_list	*temp;
	int		max;
	int		max_bits;

	max_bits = 0;
	max = (*stack)->data;
	temp = (*stack)->next;
	while (temp != NULL)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	sort(t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	j;
	int	max;
	int	size;

	i = 0;
	size = get_stack_size(*stack_a);
	max = max_bits(stack_a);
	while (i < max)
	{
		j = 0;
		while (j < size)
		{
			if (((*stack_a)->index >> i) & 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (*stack_b != NULL)
			pa(stack_a, stack_b);
		if (is_sorted(*stack_a))
			break ;
		i++;
	}
}

int	is_sorted(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}
