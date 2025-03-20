/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:23:39 by tursescu          #+#    #+#             */
/*   Updated: 2025/03/20 14:36:16 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	arg_is_number(char *av)
{
	int	i;

	i = 0;
	if (av[i + 1] != '\0' && is_sign(av[i]))
		i++;
	while (av[i] != '\0' && is_digit(av[i]))
		i++;
	if (av[i] != '\0' && !is_digit(av[i]))
		return (0);
	return (1);
}

int	has_doubles(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && ft_compare(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	good_input(char **av)
{
	int			i;
	int			zero_count;
	long long	n;

	i = 1;
	zero_count = 0;
	while (av[i])
	{
		n = push_swap_atoi(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (0);
		if (!arg_is_number(av[i]))
			return (0);
		zero_count += nb_is_zero(av[i]);
		i++;
	}
	if (zero_count > 1)
		return (0);
	if (has_doubles(av))
		return (0);
	return (1);
}

int	has_only_spaces(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] != 32)
			return (0);
		i++;
	}
	return (1);
}
