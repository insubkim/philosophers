/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:52:14 by insub             #+#    #+#             */
/*   Updated: 2023/02/17 22:47:54 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	check_end(pid_t *p, int num, int *end)
{
	int	status;
	int	i;
	int	id;

	while (1)
	{
		if (*end)
			break ;
		id = waitpid(-1, &status, WNOHANG);
		if (id)
			break ;
		usleep(700);
	}
	i = -1;
	while (++i < num)
		if (p[i] != id)
			kill(p[i], SIGKILL);
	i = -1;
	while (++i < num)
		if (p[i] != id)
			waitpid(p[i], &status, 0);
	free(p);
	free(end);
}
