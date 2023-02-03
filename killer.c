/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   killer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:30:19 by inskim            #+#    #+#             */
/*   Updated: 2023/02/04 01:52:17 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int run_killer(t_philo_info *info, int num)
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
                    return (0); 
            }
            pthread_mutex_unlock(info->write_mutex);
            i++;
        }
    }
}