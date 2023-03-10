/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:00:26 by inskim            #+#    #+#             */
/*   Updated: 2023/02/15 21:49:46 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int    check_death(t_philo_info *info, int num)
{
    int i;
    int end;

    while (1)
    {
        i = 0;
        end = 1;
        while (i < num)
        {
            pthread_mutex_lock(info->write_mutex);
            if (!info[i].is_eating && get_time() - info[i].last_ate_time >= info->time_to_die)
            {
                    printf("%llu\t%d is death\n", get_time() - info->start_time, info[i].id);
                    return (0);
            }
            pthread_mutex_unlock(info->write_mutex);
            i++;
        }
        usleep(100);
    }
    return (1);
}