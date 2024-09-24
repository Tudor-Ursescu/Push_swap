/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 10:55:08 by tursescu          #+#    #+#             */
/*   Updated: 2024/09/16 12:06:24 by tursescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "Libft/libft.h"

typedef struct s_list
{
	int				data;
	int				index;
	struct s_list	*next;
}					t_list;

//Handle errors
void		exit_error(t_list **stack_a, t_list **stack_b);
int			good_input(char **av);
int			has_doubles(char **av);
int			arg_is_number(char *av);
int			nb_is_zero(char *av);
int			ft_compare(const char *s1, const char *s2);
int			is_digit(char c);
int			is_sign(char c);
int			has_only_spaces(char *av);
//Stack initiation
t_list		*set_stack(int ac, char **av);
void		set_index(t_list *stack);
//Stack utils
void		free_stack(t_list **stack);
void		free_matrix(char **str);
void		stack_append_end(t_list **stack, t_list *new);
int			get_stack_size(t_list *stack);
t_list		*stack_bottom(t_list *stack);
t_list		*stack_second_last(t_list *stack);
t_list		*stack_new(int value);
long long	push_swap_atoi(const char *str);
//Commands
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);
void		rrr(t_list **stack_a, t_list **stack_b);
//Algorithms
void		three_arg_sort(t_list **stack);
void		four_arg_sort(t_list **stack_a, t_list **stack_b);
void		five_arg_sort(t_list **stack_a, t_list **stack_b);
void		sort(t_list **stack_a, t_list **stack_b);
int			is_sorted(t_list *stack);
#endif