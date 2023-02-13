/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_all_ate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:27:29 by inskim            #+#    #+#             */
/*   Updated: 2023/02/14 01:33:09 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    create_all_ate(t_philo_info *info, int *arg)
{
    pthread_t   p;

    pthread_create(&p, 0, run_all_ate, info)
}