/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:52:14 by insub             #+#    #+#             */
/*   Updated: 2023/02/16 22:55:20 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    check_end(pid_t *p, int num, int *end)
{
    int status;
    int i;

    while (1)
    {
        if (*end)//data race
            break ;
        if (waitpid(-1, &status, WNOHANG))
            break ;
        usleep(700);
    }
    i = 0;
    while (i < num)
        kill(p[i++], SIGILL);
}