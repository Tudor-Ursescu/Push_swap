/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:47:02 by tursescu          #+#    #+#             */
/*   Updated: 2025/03/20 14:36:47 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_list *stack)
{
	int	buff;

	if (stack == NULL || stack->next == NULL)
		return ;
	buff = stack->data;
	stack->data = stack->next->data;
	stack->next->data = buff;
	buff = stack->index;
	stack->index = stack->next->index;
	stack->next->index = buff;
}

void	sa(t_list **stack_a)
{
	swap(*stack_a);
	ft_printf("sa\n");
}

void	sb(t_list **stack_b)
{
	swap(*stack_b);
	ft_printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_printf("ss\n");
}
