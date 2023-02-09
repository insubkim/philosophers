/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:46:42 by inskim            #+#    #+#             */
/*   Updated: 2023/02/06 18:11:58 by inskim           ###   ########.fr       */
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
        pthread_mutex_lock(info->mutex1);
        pthread_mutex_lock(info->left_fork);
        pthread_mutex_lock(info->right_fork);
        pthread_mutex_lock(info->write_mutex);
        info->is_eating = 1;
        printf("%llu\t\t%d is eating\n", micro_get_time(), info->id);
        usleep(info->time_to_eat);
        info->last_ate_time = micro_get_time();
        info->must_eat_number++;
        pthread_mutex_unlock(info->write_mutex);
        pthread_mutex_unlock(info->left_fork);
        pthread_mutex_unlock(info->right_fork);
        //sleep
        pthread_mutex_lock(info->write_mutex);
        printf("%llu\t\t%d is sleeping\n", micro_get_time(), info->id);
        usleep(info->time_to_sleep);
        pthread_mutex_unlock(info->write_mutex);
        //think
        pthread_mutex_lock(info->write_mutex);
        printf("%llu\t\t%d is thinking\n", micro_get_time(), info->id);
        pthread_mutex_unlock(info->write_mutex);    
    }    
}

pthread_t *run_philo(t_philo_info *info, int num)
{
    pthread_t *p;
    int        i;

    p = (pthread_t *)malloc(sizeof(pthread_t) * num);
    if (!p)
        return (0);
    i = 0;
    while (i < num)
    {
        pthread_create(&p[i], 0, run, &info[i]);
        i++;
    }
    return (p);
}