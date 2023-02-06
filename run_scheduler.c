/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_scheduler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:12:26 by inskim            #+#    #+#             */
/*   Updated: 2023/02/06 18:18:49 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int run_scheduler(t_philo_info *info, int num)
{
    //unlock N/2 process's mutex
    //lock N/2 process's mutex
    //odd -> even 
    //in sequence
    pthread_mutex_unlock(info->mutex1);
    pthread_mutex_lock(info->mutex1);
    return (1);
}