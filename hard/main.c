/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:23:30 by inskim            #+#    #+#             */
/*   Updated: 2023/02/08 20:47:09 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int    lock_mutex(t_philo_info *info, int num)
{
    while (num-- > 0)
    {
        if(pthread_mutex_lock(info->mutex1))
            return (0);
        if(pthread_mutex_lock(info->mutex2))
            return (0);
        info++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int arg[5];
    t_philo_info    *info;
    
    //check arg 
    if (!set_arg(arg, --argc, ++argv))
        return (handle_error(0));
    //set philo info
    info = set_philo_info(arg);//free info on error
    if (!info)
        return (handle_error(0));
    //lock mutex1
    lock_mutex(info, arg[0]);
    //run philo
    if (!run_philo(info, arg[0]))
        return (handle_error(0));
        //run scheduler
    if (!run_scheduler(info, arg[0]))
        return (handle_error(0));
    //run killer
    if (!check_death(info, arg[0]))
        return (handle_error(0));
    return (0);
}