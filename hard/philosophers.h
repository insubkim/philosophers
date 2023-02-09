/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:11:47 by inskim            #+#    #+#             */
/*   Updated: 2023/02/06 18:20:24 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# define MALLOC_ERROR 0
# define MUTEX_LOCK_ERROR 1
# define b_ERROR 2
# define c_ERROR 3
# define ARG_ERROR 4


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <limits.h>

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
int set_arg(int arg[], int argc, char *argv[]);
int	handle_error(int error_reason);
t_queue	*init_queue(void);
void	enqueue(t_queue *queue, t_node *node);
t_node	*make_node(void *data);
size_t  ft_strlen(const char *s);
t_philo_info    *set_philo_info(int arg[]);
pthread_t *run_philo(t_philo_info *info, int num);
int run_scheduler(t_philo_info *info, int num);

int   check_death(t_philo_info *info, int num);



long long   micro_get_time(void);//del before eval

#endif