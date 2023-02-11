/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_schedule_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:37:58 by insub             #+#    #+#             */
/*   Updated: 2023/02/11 18:56:40 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_schedule_info *set_schedule_info(t_philo_info *info, int num)
{
    t_schedule_info *schedule_info;

    schedule_info = (t_schedule_info *)malloc(sizeof(t_schedule_info));
    if (!schedule_info)
        return (0);
    schedule_info->info = info;
    schedule_info->num = num;
    return (schedule_info);   
}