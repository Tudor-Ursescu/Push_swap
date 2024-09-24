# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 10:58:04 by tursescu          #+#    #+#              #
#    Updated: 2024/08/28 11:11:33 by tursescu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I$(LIBFT_DIR)
LIBFT_DIR = ./Libft
LIBS = -L$(LIBFT_DIR) -lft
# Source files for pipex
PUSHSWAP_SRCS =	main.c push_swap_utils.c \
				swap.c rotate.c reverse_rotate.c \
				push.c mini_sort.c set_stack.c \
				stack_utils.c sort.c check_input.c \
				push_swap_atoi.c input_utils.c
PUSHSWAP_OBJS = $(PUSHSWAP_SRCS:.c=.o)
# 'all' target
all: $(NAME)
$(NAME): $(PUSHSWAP_OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(PUSHSWAP_OBJS) $(LIBS) -o $(NAME)
# Pattern rule for object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
# 'clean' rule
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(PUSHSWAP_OBJS)
# 'fclean' rule
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
# 're' rule
re: fclean all
# Declare phony targets
.PHONY: all libft clean fclean re