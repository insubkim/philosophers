/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:37:33 by inskim            #+#    #+#             */
/*   Updated: 2023/02/12 10:21:39 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long   get_time(void)
{
    struct timeval tv;

    gettimeofday(&tv, 0);
    return ((long long)tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
