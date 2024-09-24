/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 14:55:42 by tursescu          #+#    #+#             */
/*   Updated: 2024/08/14 17:40:30 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **src, t_list **dest)
{
	t_list	*temp;

	if (*src == NULL)
		return ;
	temp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = temp;
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}
