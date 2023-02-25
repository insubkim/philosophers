# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inskim <inskim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 20:39:41 by inskim            #+#    #+#              #
#    Updated: 2023/02/25 16:44:03 by inskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra 

SRC = check_end.c circle_queue.c create_philo.c free_info.c handle_error.c main.c run_scheduler.c set_arg.c set_philo_info.c set_schedule_info.c time.c
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
