/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:11:47 by inskim            #+#    #+#             */
/*   Updated: 2023/01/28 00:15:10 by inskim           ###   ########.fr       */
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
    pthread_mutex_t *right_fork;
    pthread_mutex_t *write_mutex;
    int             is_eating;
    long long       last_ate_time;
    int         time_to_die;
    int         time_to_eat;
    int         time_to_sleep;
    int         must_eat_number;
    long long   start_time;
    
}   t_philo_info;

long long   get_time(void);

#endif