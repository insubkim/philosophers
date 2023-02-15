/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:37:33 by inskim            #+#    #+#             */
/*   Updated: 2023/02/15 21:53:10 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long   get_time(void)
{
    struct timeval tv;

    gettimeofday(&tv, 0);
    return ((long long)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

long long   micro_get_time(void)
{
    struct timeval tv;

    gettimeofday(&tv, 0);
    return ((long long)tv.tv_sec * 1000000 + tv.tv_usec);
}

void    ft_usleep(long long time)
{
        long long       start;

        start = micro_get_time();
        usleep(time * 0.7);
        while (micro_get_time() < start + time)
                usleep(700);
}