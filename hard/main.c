/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:22:06 by insub             #+#    #+#             */
/*   Updated: 2023/02/11 18:37:19 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
    int arg[5];
    t_philo_info    *info;
    pthread_t       *p;
    t_schedule_info *schedule_info;
    
    if (!set_arg(arg, --argc, ++argv))
        return (handle_error(0, 0));
    info = set_philo_info(arg);
    if (!info)
        return (handle_error(0, 0));
    schedule_info = set_schedule_info(info, arg[0]);
    if (!schedule_info)
        return (handle_error(info, arg[0]));        
    p = run_scheduler(info, arg[0], schedule_info);
    if (!p)
        return (handle_error(info, arg[0]));    
    check_end(info, arg[0]);
    return (0);
}