/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:04:59 by tursescu          #+#    #+#             */
/*   Updated: 2024/08/21 14:44:13 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*set_stack(int ac, char **av)
{
	t_list		*stack_a;
	int			i;
	int			n;

	n = 0;
	stack_a = NULL;
	i = 1;
	while (i < ac)
	{
		n = ft_atoi(av[i]);
		if (i == 1)
			stack_a = stack_new((int)n);
		else
			stack_append_end(&stack_a, stack_new((int)n));
		i++;
	}
	return (stack_a);
}

static t_list	**create_array(t_list *stack, int size)
{
	t_list	**node_array;
	t_list	*current;
	int		i;

	current = stack;
	node_array = (t_list **)malloc (sizeof(t_list *) * size);
	if (node_array == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		node_array[i] = current;
		current = current->next;
		i++;
	}
	return (node_array);
}

static void	sort_array(t_list **node_array, int size)
{
	t_list	*temp;
	int		i;
	int		j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (node_array[j]->data > node_array[j + 1]->data)
			{
				temp = node_array[j];
				node_array[j] = node_array[j + 1];
				node_array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	set_index(t_list *stack)
{
	t_list	**node_array;
	int		size;
	int		i;

	if (stack == NULL)
		return ;
	size = get_stack_size(stack);
	node_array = create_array(stack, size);
	sort_array(node_array, size);
	i = 0;
	while (i < size)
	{
		node_array[i]->index = i;
		i++;
	}
	free(node_array);
}
