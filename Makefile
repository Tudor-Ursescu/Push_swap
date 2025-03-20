# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tursescu <tursescu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/30 10:58:04 by tursescu          #+#    #+#              #
#    Updated: 2025/03/20 14:38:13 by tursescu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I$(LIBFT_DIR)
LIBFT_DIR = ./Libft
LIBS = -L$(LIBFT_DIR) -lft
# Source files for pipex
PUSHSWAP_SRCS =	src/main.c src/push_swap_utils.c \
				src/swap.c src/rotate.c src/reverse_rotate.c \
				src/push.c src/mini_sort.c src/set_stack.c \
				src/stack_utils.c src/sort.c src/check_input.c \
				src/push_swap_atoi.c src/input_utils.c
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