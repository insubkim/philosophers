# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inskim <inskim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 20:39:41 by inskim            #+#    #+#              #
#    Updated: 2023/02/13 20:17:22 by inskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

CC = cc

CFLAGS = -Wall -Werror -Wextra
SRC = create_philo.c main.c set_arg.c time.c check_end.c handle_error.c set_philo_info.c
OBJ = $(SRC:.c=.o)
HEADER = philosophers.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) 

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) 

clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean
	make

.phony: all clean fclean re
