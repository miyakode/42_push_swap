# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xxxxxxxx <xxxxxxxx@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/19 12:40:58 by xxxxxxxx          #+#    #+#              #
#    Updated: 2024/10/11 14:16:18 by xxxxxxxx         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL= /bin/sh
NAME = push_swap
SRCS = push_swap.c \
	create_list.c\
	cal_sort.c \
	ps_operation.c \
	opcall.c \
	ps_utils.c \
	ps_utils2.c \
	coor_compress.c \
	over6_sort.c \
	qsort_partition.c
OBJS = $(SRCS:.c=.o)
BONUS = checker
BONUS_SRCS = checker.c \
	create_lst_checker.c \
	coor_compress_checker.c \
	get_input.c \
	operation_checker.c \
	opcall_checker.c \
	checker_utils.c \
	checker_utils2.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
TEST_SRCS = test_op.c \
	ps_testprint.c
TEST_OBJS = $(TEST_SRCS:.c=.o)
LIBFT = libft
LIBFT_A= libft.a
LIBS = -Llibft -lft
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude -Ilibft -Ips_test
VPATH = src bonus ps_test

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(BONUS_OBJS)
	make bonus -C $(LIBFT)
	$(CC) $(FLAGS) $(BONUS_OBJS) $(LIBS) -o $(BONUS)

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(TEST_OBJS)
	make clean -C $(LIBFT)

fclean: clean
	rm -f $(NAME) $(BONUS)
	make fclean -C $(LIBFT)

re: fclean all

test: CFLAGS+= -D TEST
test: $(TEST_OBJS)
test: OBJS += $(TEST_OBJS)
test: all

test_bonus: CFLAGS+= -D TEST_BONUS
test_bonus: $(TEST_OBJS)
test_bonus: BONUS_OBJS += $(TEST_OBJS)
test_bonus: bonus

debug: CFLAGS += -g
debug: fclean test

debug_bonus: CFLAGS += -g
debug_bonus: fclean bonus

.PHONY: all clean fclean re bonus debug debugadebug_bonus test
