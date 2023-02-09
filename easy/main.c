/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:22:06 by insub             #+#    #+#             */
/*   Updated: 2023/02/08 22:15:33 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int main(int argc, char **argv)
{
    int arg[5];
    t_philo_info    *info;
    pthread_t       *p;
    
    if (!set_arg(arg, --argc, ++argv))
        return (handle_error(0));
    info = set_philo_info(arg);
    if (!info)
        return (handle_error(0));
    p = create_philo(info, arg[0]);
    if (!p)
        return (handle_error(0));
    check_death(info, arg[0]);
    return (0);
}