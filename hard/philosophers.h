/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:11:47 by inskim            #+#    #+#             */
/*   Updated: 2023/02/11 18:31:45 by insub            ###   ########.fr       */
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
    pthread_mutex_t *scheduler;
    int             done;
    int             is_eating;
    long long       last_ate_time;
    long long       time_to_die;
    long long       time_to_eat;
    long long       time_to_sleep;
    int             must_eat_number;
    int             eat_num;
    long long       start_time;
}   t_philo_info;

typedef struct s_schedule_info
{
    t_philo_info    *info;
    int             num;
}   t_schedule_info;

long long   get_time(void);
int set_arg(int arg[], int argc, char *argv[]);
int	handle_error(t_philo_info *info, int num);
size_t  ft_strlen(const char *s);
t_philo_info    *set_philo_info(int arg[]);
pthread_t *run_philo(t_philo_info *info, int num);
int   check_death(t_philo_info *info, int num);
long long   micro_get_time(void);
pthread_t   *create_philo(t_philo_info *info, int num);
void    *free_info(t_philo_info *info, int num);

#endif