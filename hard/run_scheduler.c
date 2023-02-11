/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_scheduler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:17:37 by insub             #+#    #+#             */
/*   Updated: 2023/02/11 18:53:42 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    lock_mutexes(t_philo_info *info, int num)
{
    while (num-- > 0)
        pthread_mutex_lock(info[num].scheduler);
}

void    busy_wait(t_philo_info *info)
{
    while (1)
    {
        pthread_mutex_lock(info->scheduler);
        if (!info->done)
        {
            pthread_mutex_unlock(info->scheduler);
            break ;    
        }
        pthread_mutex_unlock(info->scheduler);
    }
}

void    *create_philo(void *data)
{
    t_philo_info    *info;

    info = data;
    while (1)
    {
        pthread_mutex_lock(info->scheduler);
        //take 2 fork 
        info->done = 1;
        pthread_mutex_unlock(info->scheduler);
        usleep(info->time_to_eat * 1000);
        //sleep
        usleep(info->time_to_sleep * 1000);
        //think
        busy_wait(info);
    }
    return (0);
}

void    *create_schedule(void *data)
{
    t_schedule_info *info;

    info = data;
    while (1)
    {
        
    }
    return (0);
}

pthread_t   *run_scheduler(t_philo_info *info, int num, t_schedule_info \
*schedule_info)
{
    pthread_t  *p;
    int         i;
    lock_mutexes(info, num);
    p = (pthread_t *)malloc(sizeof(pthread_t) * (num + 1));
    if (!p)
        return (0);
    i = -1;
    while (++i < num)
        pthread_create(&(p[i]), 0, create_philo, &(info[i]));
    //run scheduler
    pthread_create(&(p[i]), 0, create_schedule, schedule_info);
    return (p);
}