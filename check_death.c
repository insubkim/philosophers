/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:00:26 by inskim            #+#    #+#             */
/*   Updated: 2023/02/06 18:20:09 by inskim           ###   ########.fr       */
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
            if (!info[i].is_eating && get_time() - info[i].last_ate_time >= info[i].time_to_die)
            {
                    printf("%llu\t%d is death\n", get_time() - info->start_time, info->id);
                    return (0);
            }
            pthread_mutex_unlock(info->write_mutex);
            i++;
        }
    }
    return (1);
}