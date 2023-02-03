/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:30:19 by inskim            #+#    #+#             */
/*   Updated: 2023/02/04 01:12:28 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t *make_mutex(int num)
{
    int i;
    pthread_mutex_t *arr;

    arr = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
    if (!arr)
        return (0);
    i = 0;
    while (i < num)
    {
        if (pthread_mutex_init(&(arr[i]), 0))
            return (0);
        i++;
    }
    return (arr);
}

int    lock_mutex_arr(pthread_mutex_t *mutex1, int num)
{
    while (--num >= 0)
    {
        if(pthread_mutex_lock(mutex1++))
            return (0);
    }
    return (1);
}

t_queue *make_mutex_queue(pthread_mutex_t *mutex[], int num)
{
    t_queue *queue;
    t_node  *node;
    int     i;

    queue = init_queue();
    if (!queue)
        return (0);
    i = 0;
    while (i < num)
    {
        node = make_node(mutex[i]);
        if (!node)
            return (0);
        enqueue(queue, node);
        i += 2;
    }
    i  = 1;
    while (i < num)
    {
        node = make_node(mutex[i]);
        if (!node)
            return (0);
        enqueue(queue, node);
        i += 2;
    }
    return (queue);
}