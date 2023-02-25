# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inskim <inskim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 20:39:41 by inskim            #+#    #+#              #
#    Updated: 2023/02/25 16:45:11 by inskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=thread

SRC = check_end_bonus.c create_all_ate_bonus.c create_philo_bonus.c handle_error_bonus.c main_bonus.c set_arg_bonus.c set_philo_info_bonus.c time_bonus.c
OBJ = $(SRC:.c=.o)
HEADER = philosophers_bonus.h

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
