/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:35:11 by insub             #+#    #+#             */
/*   Updated: 2023/02/13 02:59:09 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    *run(void *data)
{
    t_philo_info    *info;

    info = (t_philo_info *)data;
    pthread_mutex_t *l = info->left_fork;
    pthread_mutex_t *r = info->right_fork;
    pthread_mutex_t *w = info->write_mutex;
    int id = info->id;
    long long s = info->start_time;
    long long eat = info->time_to_eat;
    long long sleep = info->time_to_sleep;
    while (1)
    {
        //eat
        pthread_mutex_lock(l);
        printf("%llu\t%d has taken a fork\n", get_time() - s, id);
        pthread_mutex_lock(r);
        pthread_mutex_lock(w);
        info->is_eating = 1;
        info->last_ate_time = get_time();
        pthread_mutex_unlock(w);
        printf("%llu\t%d has taken a fork\n", get_time() - s, id);
        printf("%llu\t%d is eating\n", get_time() - s, id);
        usleep(eat * 1000);
        pthread_mutex_unlock(l);
        pthread_mutex_unlock(r);
        
        pthread_mutex_lock(w);
        info->is_eating = 0;
        pthread_mutex_unlock(w);
        
        //sleep
        printf("%llu\t%d is sleeping\n", get_time() - s, id);
        
        usleep(sleep * 1000);
        
        //think
        printf("%llu\t%d is thinking\n", get_time() - s, id);
        
    }
}

void    *run_reverse_fork(void *data)
{
    t_philo_info    *info;

    info = (t_philo_info    *)data;
    pthread_mutex_t *l = info->left_fork;
    pthread_mutex_t *r = info->right_fork;
    pthread_mutex_t *w = info->write_mutex;
    int id = info->id;
    long long s = info->start_time;
    long long eat = info->time_to_eat;
    long long sleep = info->time_to_sleep;
    while (1)
    {
        //eat
        pthread_mutex_lock(r);
        printf("%llu\t%d has taken a fork\n", get_time() - s, id);
        pthread_mutex_lock(l);
        pthread_mutex_lock(w);
        info->is_eating = 1;
        info->last_ate_time = get_time();
        pthread_mutex_unlock(w);
        printf("%llu\t%d has taken a fork\n", get_time() - s, id);
        printf("%llu\t%d is eating\n", get_time() - s, id);
        usleep(eat * 1000);
        pthread_mutex_unlock(r);
        pthread_mutex_unlock(l);
        
        pthread_mutex_lock(w);
        info->is_eating = 0;
        pthread_mutex_unlock(w);
        
        //sleep
        printf("%llu\t%d is sleeping\n", get_time() - s, id);
        usleep(sleep * 1000);
        //think
        printf("%llu\t%d is thinking\n", get_time() - s, id);
        
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