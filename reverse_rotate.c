/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 08:59:12 by tursescu          #+#    #+#             */
/*   Updated: 2024/08/14 17:41:26 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*end;
	t_list	*second_last;

	end = stack_bottom(*stack);
	temp = *stack;
	second_last = stack_second_last(*stack);
	*stack = end;
	(*stack)->next = temp;
	second_last->next = NULL;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
