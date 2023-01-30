/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:06:24 by inskim            #+#    #+#             */
/*   Updated: 2023/01/31 06:42:23 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    init_philo_info(t_philo_info *info, int num)
{
    long long   time = micro_get_time();
    long long   time_to_die = 410000;
    long long   time_to_eat = 200000;
    long long   time_to_sleep = 200000;
    int         must_eat_number = -1;
    int i = 0;
    pthread_mutex_t write_mutex;
    pthread_mutex_init(&write_mutex, 0);
    
    while (i < num)
    {
        info[i].id = i + 1;
        info[i].is_eating = 0;
        info[i].last_ate_time = time;
        info[i].left_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
        pthread_mutex_init(info[i].left_fork, 0); 
        info[i].write_mutex = &write_mutex;
        info[i].time_to_die = time_to_die;
        info[i].time_to_eat = time_to_eat;
        info[i].time_to_sleep = time_to_sleep;
        info[i].must_eat_number = must_eat_number;
        info[i].start_time = time;
        i++;
    }
    i = 0;
    while (i < num)
    {
        if (i != num - 1)
            info[i].right_fork = info[i + 1].left_fork;
        else
            info[i].right_fork = info[0].left_fork;   
        i++;
    }
}

void    run_odd(t_philo_info *info)
{
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
        usleep(info->time_to_sleep);
    }
}


void    run_even(t_philo_info *info)
{
    while (1)
    {
        pthread_mutex_lock(info->right_fork);
        pthread_mutex_lock(info->left_fork);
        pthread_mutex_lock(info->write_mutex);
        info->is_eating=1;
        pthread_mutex_unlock(info->write_mutex);
        printf("%llu\t\t%d is eating\n", micro_get_time() - info->start_time, info->id);
        usleep(info->time_to_eat);
        pthread_mutex_lock(info->write_mutex);
        info->last_ate_time = micro_get_time();
        info->is_eating=0;
        pthread_mutex_unlock(info->write_mutex);
        pthread_mutex_unlock(info->right_fork);
        pthread_mutex_unlock(info->left_fork);
        usleep(info->time_to_sleep);
    }
}

void    *run1(void *info)
{
    run_odd((t_philo_info *)info);
    return (0);
}

void    *run2(void *info)
{
    run_even((t_philo_info *)info);
    return (0);
}

void    create_philo(pthread_t *p, t_philo_info *info, int num)
{
    //create 4 threads and run
    int i = 0;
    while (i < num)
    {
        pthread_create(&p[i], 0, run1, &info[i]);
        i += 2;
    }
    i = 1;
    while (i < num)
    {
        if (num % 2)//num is odd
            pthread_create(&p[i], 0, run1, &info[i]);
        else//num is even
            pthread_create(&p[i], 0, run2, &info[i]);
        i +=2;
    }
}

void    check_death(t_philo_info *info, int num)
{
    int i;

    while (1)
    {
        i = 0;
        while (i < num)
        {
            
            pthread_mutex_lock(info->write_mutex);        
            if (!info[i].is_eating && micro_get_time() - info[i].last_ate_time >= info[i].time_to_die)
            {
                    printf("%llu\t%d is death\n", micro_get_time() - info[i].start_time, info[i].id);
                    exit(1); 
            }
            pthread_mutex_unlock(info->write_mutex);
            i++;
        }
    }
}

int main(void)
{
    int num = 200;
    
    t_philo_info    info[num];
    init_philo_info(info, num);
    pthread_t p[num];
    create_philo(p, info, num);
    
    //check death philo
    //queue??
    check_death(info, num);
    void *a;
    int i = 0;
    while (i < num)
        pthread_join(p[i++],&a);
    return (0);
}