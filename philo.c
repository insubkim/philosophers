/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:30:19 by inskim            #+#    #+#             */
/*   Updated: 2023/02/04 08:42:11 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    *run_philo(void *info_data)
{
    t_philo_info    *info;

    info = info_data;
    while (1)
    {
        pthread_mutex_lock(info->left_fork);
        pthread_mutex_lock(info->right_fork);
        pthread_mutex_lock(info->write_mutex);
        info->is_eating=1;
        pthread_mutex_unlock(info->write_mutex);
        printf("%llu\t\t%d is eating\n", micro_get_time() - info->start_time, info->id);
        usleep(info->time_to_eat);
        pthread_mutex_lock(info->write_mutex);
        info->last_ate_time = micro_get_time();
        info->is_eating=0;
        pthread_mutex_unlock(info->write_mutex);
        pthread_mutex_unlock(info->left_fork);
        pthread_mutex_unlock(info->right_fork);
        printf("%llu\t\t%d is sleeping\n", micro_get_time() - info->start_time, info->id);
        usleep(info->time_to_sleep);
        printf("%llu\t\t%d is thinking\n", micro_get_time() - info->start_time, info->id);
        
    }
}

pthread_t   *create_philo(t_philo_info *info, int num)
{
    pthread_t   *thread_arr;
    int         i;

    thread_arr = (pthread_t *)malloc(sizeof(pthread_t) * num);
    if (!thread_arr)
        return (0);
    i = 0;
    while (i < num)
        pthread_create(&(thread_arr[i++]), 0, run_philo, info++);
    return (thread_arr);
}