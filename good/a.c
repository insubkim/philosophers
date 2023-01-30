/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:10:11 by inskim            #+#    #+#             */
/*   Updated: 2023/01/30 21:35:26 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    *run(void    *infos)
{
    t_philo_info *info = (t_philo_info*)infos;
   
    while (1)
    {     
    // //eat
    if (info->id % 2 == 0)//not odd
    {
        pthread_mutex_lock(info->left_fork);
        pthread_mutex_lock(info->right_fork);
        info->is_eating=1;
        printf("%llu\t%d is eating\n", get_time() - info->start_time, info->id);
        usleep(info->time_to_eat);
        info->last_ate_time = get_time();
        info->is_eating=0;
        pthread_mutex_unlock(info->right_fork);
        pthread_mutex_unlock(info->left_fork);
    }   
    else
    {
        pthread_mutex_lock(info->right_fork);
        pthread_mutex_lock(info->left_fork);
        info->is_eating=1;
        printf("%llu\t%d is eating\n", get_time() - info->start_time, info->id);
        usleep(info->time_to_eat);
        
        printf("%llu\t%d is awake------\n", get_time() - info->start_time, info->id);
        
        info->last_ate_time = get_time();
        info->is_eating=0;
        pthread_mutex_unlock(info->left_fork);
        pthread_mutex_unlock(info->right_fork);
    } 
    
    // //sleep
    printf("%llu\t%d is sleeping\n", get_time() - info->start_time, info->id);
    usleep(info->time_to_sleep);
    // //think
    pthread_mutex_lock(info->write_mutex);
    printf("%llu\t%d is thinking\n", get_time() - info->start_time, info->id);
    pthread_mutex_unlock(info->write_mutex);    
    }
    return (0);
}


void    check_death(t_philo_info *info, int num)
{
    int i;

    while (1)
    {
        i = 0;
        while (i < num)
        {
            
            if (!info[i].is_eating && get_time() - info[i].last_ate_time >= info[i].time_to_die)
            {
                    pthread_mutex_lock(info->write_mutex);
                    printf("%llu\t%d is death\n", get_time() - info->start_time, info->id);
                    pthread_mutex_unlock(info->write_mutex);
                    exit(1); 
            }
            i++;
        }
    }
}

int main(void)
{
    //make 4 philos
    int num = 5;
    t_philo_info    info[num];
    int i;
    long long   time;
    int         time_to_die;
    int         time_to_eat;
    int         time_to_sleep;
    int         must_eat_number;
    

    time_to_die = 2500;
    time_to_eat = 2000000;
    time_to_sleep = 1000000;
    must_eat_number = -1;
    i = 0;
    time = get_time();
    pthread_mutex_t write_mutex;
    pthread_mutex_init(&write_mutex, 0);
    
    while (i < num)
    {
        info[i].id = i;
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

    //create 4 threads and run
    pthread_t p[num];
    i = 0;
    while (i < num)
    {
        pthread_create(&p[i], 0, run, &info[i]);
        i += 2;
    }
    i = 1;
    while (i < num)
    {
        pthread_create(&p[i], 0, run, &info[i]);
        i +=2;
    }
    //check death philo
    //queue??
    check_death(info, num);
    void *a;
    i = 0;
    while (i < num)
        pthread_join(p[i++],&a);
    
}