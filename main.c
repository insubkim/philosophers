/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:30:19 by inskim            #+#    #+#             */
/*   Updated: 2023/02/04 08:39:04 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


int main(int argc, char *argv[])
{
    int arg[5];
    pthread_mutex_t *mutex[2];
    t_queue *queue;
    t_philo_info    *info;
    
    // set_arg(arg, argc, argv);
    arg[0] = 5;
    arg[1] = 410;
    arg[2] = 200;
    arg[3] = 200;
    arg[4] = -1;

    //make n mutex1, mutex2
    mutex[0] = make_mutex(arg[0]);
    mutex[1] = make_mutex(arg[0]);
    //lock all mutex1
    lock_mutex_arr(mutex[0], arg[0]);
    //make queue
    queue = make_mutex_queue(mutex, arg[0]);
    //to circular queue
    queue->front->next = queue->rear;
    queue->rear->back = queue->front;

    //make philo info
    info = set_philo_info(arg, mutex);

    //run philo
    create_philo(info, arg[0]);

    //run killer
    run_killer(info, arg[0]);


    //run scheduler
    run_scheduler(queue, arg[0]);

    //free
    return (0);
}
