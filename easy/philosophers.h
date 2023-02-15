/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:11:47 by inskim            #+#    #+#             */
/*   Updated: 2023/02/15 21:51:24 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_philo_info
{
    int             id;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
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
size_t  ft_strlen(const char *s);
t_philo_info    *set_philo_info(int arg[]);
pthread_t *run_philo(t_philo_info *info, int num);
int   check_death(t_philo_info *info, int num);
long long   micro_get_time(void);
void    ft_usleep(long long t);
pthread_t   *create_philo(t_philo_info *info, int num);

#endif