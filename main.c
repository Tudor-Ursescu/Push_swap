/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:04:03 by tursescu          #+#    #+#             */
/*   Updated: 2024/08/22 12:52:31 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_list **stack_a, t_list **stack_b, int stack_size)
{
	if (stack_size == 2)
		sa(stack_a);
	else if (stack_size == 3)
		three_arg_sort(stack_a);
	else if (stack_size == 4)
		four_arg_sort(stack_a, stack_b);
	else if (stack_size == 5)
		five_arg_sort(stack_a, stack_b);
	else if (stack_size > 5)
		sort(stack_a, stack_b);
}

static void	check_if_failed(char **new_av, char ***split_av)
{
	if (!new_av)
	{
		free_matrix(*split_av);
		exit_error(NULL, NULL);
	}
}

static void	handle_split(int *ac, char ***av, char ***split_av, int *checker)
{
	int		i;
	int		split_ac;
	char	**new_av;

	i = 0;
	*split_av = ft_split((*av)[1], ' ');
	if (!(*split_av))
		exit_error(NULL, NULL);
	split_ac = 0;
	while ((*split_av)[split_ac])
		split_ac++;
	new_av = malloc(sizeof(char *) * (split_ac + 2));
	check_if_failed(new_av, split_av);
	new_av[0] = (*av)[0];
	while (i < split_ac)
	{
		new_av[i + 1] = (*split_av)[i];
		i++;
	}
	new_av[i + 1] = NULL;
	*checker = 1;
	*av = new_av;
	*ac = split_ac + 1;
}

static void	ft_free(char **av, char **split_av, int checker, int n)
{
	if (n)
	{
		if (checker)
		{
			free(av);
			free_matrix(split_av);
		}
		exit_error(NULL, NULL);
	}
	else
	{
		if (checker)
		{
			free(av);
			free_matrix(split_av);
		}
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		stack_size;
	char	**split_av;
	int		checker;

	checker = 0;
	stack_a = NULL;
	stack_b = NULL;
	split_av = NULL;
	if (ac == 1 || (ac == 2 && has_only_spaces(av[1])))
		return (0);
	else if (ac == 2)
		handle_split(&ac, &av, &split_av, &checker);
	if (!good_input(av))
		ft_free(av, split_av, checker, 1);
	stack_a = set_stack(ac, av);
	stack_size = get_stack_size(stack_a);
	set_index(stack_a);
	if (!is_sorted(stack_a))
		push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	ft_free(av, split_av, checker, 0);
	return (0);
}
