/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:52:14 by insub             #+#    #+#             */
/*   Updated: 2023/02/15 22:59:28 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void    check_end(pid_t *p, int num, int *end)
{
    int status;

    while (1)
    {
        if (*end)
            exit(1);
        if (waitpid(-1, &status, WNOHANG))
            exit(1);
        usleep(700);
    }
}