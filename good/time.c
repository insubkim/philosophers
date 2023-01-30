/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:37:33 by inskim            #+#    #+#             */
/*   Updated: 2023/01/30 21:08:10 by inskim           ###   ########.fr       */
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