/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:11:47 by inskim            #+#    #+#             */
/*   Updated: 2023/02/04 01:34:48 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define MALLOC_ERROR 0

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

    //philos struct have
    /*
    id
    left mutex
    right mutex
    last ate time
    is eating
    */
typedef struct s_node
{
        void            *data;
        struct s_node   *next;
        struct s_node   *back;
}       t_node;

typedef struct s_queue
{
        t_node  *front;
        t_node  *rear;
}       t_queue;

typedef struct s_philo_info
{
    int             id;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *mutex1;
    pthread_mutex_t *mutex2;
    pthread_mutex_t *write_mutex;
    int             is_eating;
    long long       last_ate_time;
    long long       time_to_die;
    long long       time_to_eat;
    long long       time_to_sleep;
    int             must_eat_number;
    long long       start_time;
    
}   t_philo_info;

long long   get_time(void);
void	handle_error(int error_reason);
t_queue	*init_queue(void);
void	enqueue(t_queue *queue, t_node *node);
t_node	*dequeue(t_queue *queue);//del
t_node	*make_node(void *data);
pthread_mutex_t *make_mutex(int num);
void	free_linked_list(t_node *node);




long long   micro_get_time(void);//del before eval

#endif