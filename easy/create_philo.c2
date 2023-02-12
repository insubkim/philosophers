/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:35:11 by insub             #+#    #+#             */
/*   Updated: 2023/02/13 02:19:10 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    *run(void *data)
{
    t_philo_info    *info;

    info = (t_philo_info *)data;
    while (1)
    {
        //eat
        pthread_mutex_lock(info->left_fork);
        pthread_mutex_lock(info->write_mutex);
        printf("%llu\t%d has taken a fork\n", get_time() - info->start_time, info->id);
        pthread_mutex_unlock(info->write_mutex);
        
        pthread_mutex_lock(info->right_fork);
        
        pthread_mutex_lock(info->write_mutex);
        info->is_eating = 1;
        printf("%llu\t%d has taken a fork\n", get_time() - info->start_time, info->id);
        printf("%llu\t%d is eating\n", get_time() - info->start_time, info->id);
        pthread_mutex_unlock(info->write_mutex);
        
        usleep(info->time_to_eat * 1000);
        
        pthread_mutex_lock(info->write_mutex);
        info->is_eating = 0;
        info->last_ate_time = get_time();
        pthread_mutex_unlock(info->write_mutex);
        
        pthread_mutex_unlock(info->left_fork);
        pthread_mutex_unlock(info->right_fork);
        //sleep
        pthread_mutex_lock(info->write_mutex);
        printf("%llu\t%d is sleeping\n", get_time() - info->start_time, info->id);
        pthread_mutex_unlock(info->write_mutex);
        
        usleep(info->time_to_sleep * 1000);
        
        //think
        pthread_mutex_lock(info->write_mutex);
        printf("%llu\t%d is thinking\n", get_time() - info->start_time, info->id);
        pthread_mutex_unlock(info->write_mutex);
        
    }
}

void    *run_reverse_fork(void *data)
{
    t_philo_info    *info;

    info = (t_philo_info    *)data;
    while (1)
    {
        //eat
        pthread_mutex_lock(info->right_fork);
        pthread_mutex_lock(info->write_mutex);
        printf("%llu\t%d has taken a fork\n", get_time() - info->start_time, info->id);
        pthread_mutex_unlock(info->write_mutex);
        pthread_mutex_lock(info->left_fork);
        pthread_mutex_lock(info->write_mutex);
        info->is_eating = 1;
        printf("%llu\t%d has taken a fork\n", get_time() - info->start_time, info->id);
        printf("%llu\t%d is eating\n", get_time() - info->start_time, info->id);
        pthread_mutex_unlock(info->write_mutex);
        usleep(info->time_to_eat * 1000);
        
        pthread_mutex_lock(info->write_mutex);
        info->last_ate_time = get_time();
        info->is_eating = 0;
        pthread_mutex_unlock(info->write_mutex);
        
        pthread_mutex_unlock(info->right_fork);
        pthread_mutex_unlock(info->left_fork);
        //sleep
        pthread_mutex_lock(info->write_mutex);
        printf("%llu\t%d is sleeping\n", get_time() - info->start_time, info->id);
        pthread_mutex_unlock(info->write_mutex);
        usleep(info->time_to_sleep * 1000);
        //think
        pthread_mutex_lock(info->write_mutex);
        printf("%llu\t%d is thinking\n", get_time() - info->start_time, info->id);
        pthread_mutex_unlock(info->write_mutex);
        
    }
}



pthread_t *run_even_philo(t_philo_info *info, int num)
{
    int i;
    pthread_t   *p;

    p = (pthread_t *)malloc(sizeof(pthread_t) * num);
    if (!p)
        return (0);
    i = 0;
    while (i < num)
    {
        pthread_create(&(p[i]), 0, run, &(info[i]));
        i += 2;
    }
    i = 1;
    while (i < num)
    {
        pthread_create(&(p[i]), 0, run_reverse_fork, &(info[i]));
        i += 2;
    }
    return (p);
}

pthread_t   *run_odd_philo(t_philo_info *info, int num)
{
    int i;
    pthread_t   *p;

    p = (pthread_t *)malloc(sizeof(pthread_t) * num);
    if (!p)
        return (0);
    i = 0;
    while (i < num)
    {
        pthread_create(&(p[i]), 0, run, &(info[i]));
        i += 2;
    }
    i = 1;
    while (i < num)
    {
        pthread_create(&(p[i]), 0, run, &(info[i]));
        i += 2;
    }
    return (p);
}

pthread_t   *create_philo(t_philo_info *info, int num)
{
    if (num % 2 == 1)
        return (run_odd_philo(info, num));
    else
        return (run_even_philo(info, num));
    return (0);
}