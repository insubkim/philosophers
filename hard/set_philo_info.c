/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:30:19 by inskim            #+#    #+#             */
/*   Updated: 2023/02/06 17:35:46 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t *make_mutex(int num)
{
    int i;
    pthread_mutex_t *arr;

    arr = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
    if (!arr)
        return (0);
    i = 0;
    while (i < num)
    {
        if (pthread_mutex_init(&(arr[i]), 0))
            return (0);
        i++;
    }
    return (arr);
}

int set_mutex_info(t_philo_info *info, int num)
{
    int i;
    pthread_mutex_t *write_mutex;

    write_mutex = make_mutex(1);
    if (!write_mutex)
        return (0);
    i = 0;
    while (i < num)
    {
        info[i].left_fork = make_mutex(1);
        if (!info[i].left_fork)
            return (0);
        if (i != 0)
            info[i - 1].right_fork = info[i].left_fork;
        if (i == num - 1)
            info[i].right_fork = info[0].left_fork; 
        info[i].write_mutex = write_mutex;
        info[i].mutex1 = make_mutex(1);
        if (!info[i].mutex1)
            return (0);
        info[i].mutex2 = make_mutex(1);
        if (!info[i].mutex2)
            return (0);
        i++;
    }
    return (1);
}

t_philo_info    *set_philo_info(int arg[])
{
    t_philo_info    *info;
    int             i;
    long long       time;

    info = (t_philo_info *)malloc(sizeof(t_philo_info) * arg[0]);
    if (!info)
        return (0);
    time = micro_get_time();
    i = 0;
    while (i < arg[0])
    {
        info[i].id = i + 1;
        info[i].is_eating = 0;
        info[i].last_ate_time = time;
        info[i].time_to_die = arg[1];
        info[i].time_to_eat = arg[2];
        info[i].time_to_sleep = arg[3];
        info[i].must_eat_number = arg[4];
        info[i].start_time = time;
        i++;
    }
    if (!set_mutex_info(info, arg[0]))
        return (0);
    return (info);
}