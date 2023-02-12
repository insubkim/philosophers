# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inskim <inskim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 20:39:41 by inskim            #+#    #+#              #
#    Updated: 2023/01/27 23:27:58 by inskim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = $(addprefix philo/, check_end.c circle_queue.c create_philo.c free_info.c handle_error.c main.c run_scheduler.c set_arg.c set_philo_info.c set_schedule_info.c time.c)
OBJ = $(SRC:.c=.o)
HEADER = philosophers.h
BONUS_SRC = a
BONUS_OBJ = $(BONUS_SRC:.c=.o)
BONUS_HEADER = philosophers_bonus.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): | MAKE_MAN

bonus: | MAKE_BONUS

MAKE_MAN: $(OBJ) 
	touch MAKE_MAN
	rm -f MAKE_BONUS
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lpthread

MAKE_BONUS: $(BONUS_OBJ) $(BONUS_HEADER)
	touch MAKE_BONUS
	rm -f MAKE_MAN
	$(CC) $(CFLAGS) -o $(NAME) $(BONUS_OBJ)

clean:
	rm -f $(OBJ)
	rm -f $(BONUS_OBJ)
	rm -f MAKE_BONUS MAKE_MAN

fclean: clean
	rm -f $(NAME)

re: fclean
	make

.phony: all clean fclean re bonus
