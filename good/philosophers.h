/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:11:47 by inskim            #+#    #+#             */
/*   Updated: 2023/01/30 21:10:16 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H


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
typedef struct s_philo_info
{
    int             id;
    pthread_mutex_t *left_fork;
    int             left_fork_owner;
    pthread_mutex_t *right_fork;
    int             right_fork_owner;
    pthread_mutex_t *write_mutex;
    int             is_eating;
    long long       last_ate_time;
    long long       time_to_die;
    long long       time_to_eat;
    long long      time_to_sleep;
    int             must_eat_number;
    long long       start_time;
    
}   t_philo_info;

long long   get_time(void);
long long   micro_get_time(void);//del before eval

#endif