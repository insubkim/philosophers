# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inskim <inskim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 20:39:41 by inskim            #+#    #+#              #
#    Updated: 2023/02/03 22:59:09 by inskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CC = cc

CFLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address

SRCS = main.c time.c
OBJS = $(SRCS:.c=.o)
HEADER = philosophers.h

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make