# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xxxxxxxx <xxxxxxxx@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 15:41:33 by xxxxxxxx          #+#    #+#              #
#    Updated: 2024/10/06 00:33:22 by xxxxxxxx         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = $(wildcard ft_is*.c) $(wildcard ft_to*.c) $(wildcard ft_str*.c) \
	$(wildcard ft_put*.c) $(wildcard ft_mem*.c) \
	ft_bzero.c ft_atoi.c ft_calloc.c ft_substr.c ft_split.c ft_itoa.c \
	get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
BONUS_S = $(wildcard ft_lst*.c)
BONUS_O = $(BONUS_S:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar -rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) -c $(CFLAGS) $<
	
clean:
	$(RM) $(OBJS) $(BONUS_O)

fclean: clean
	$(RM) $(NAME)
	
re: fclean all

bonus: $(OBJS) $(BONUS_O)
	ar -rc $(NAME) $(OBJS) $(BONUS_O)

test: CFLAGS += -g
test: fclean bonus

.PHONY:	all clean fclean re bonus
