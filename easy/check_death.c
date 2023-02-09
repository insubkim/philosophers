/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:00:26 by inskim            #+#    #+#             */
/*   Updated: 2023/02/10 00:15:38 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int    check_death(t_philo_info *info, int num)
{
    int i;

    while (1)
    {
        i = 0;
        while (i < num)
        {
            pthread_mutex_lock(info->write_mutex);
            // long long a =  get_time();
            // long long b = info[i].last_ate_time;
            // long long c =  get_time() - info[i].last_ate_time;
            if (!info[i].is_eating && get_time() - info[i].last_ate_time >= info->time_to_die)
            {
                    printf("%llu\t%d is death\n", get_time() - info->start_time, info[i].id);
                    return (0);
            }
            pthread_mutex_unlock(info->write_mutex);
            i++;
        }
    }
    return (1);
}