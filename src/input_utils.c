/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 12:33:01 by tursescu          #+#    #+#             */
/*   Updated: 2025/03/20 14:35:04 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sign(char c)
{
	return ((c == '+') || (c == '-'));
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_compare(const char *s1, const char *s2)
{
	int	x;
	int	y;

	x = ft_atoi(s1);
	y = ft_atoi(s2);
	return (x - y);
}
