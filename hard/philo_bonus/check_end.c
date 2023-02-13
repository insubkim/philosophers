/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:00:26 by inskim            #+#    #+#             */
/*   Updated: 2023/02/13 22:04:54 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	check(t_philo_info *info, int num, int end)
{
	int	i;

	i = 0;
	sem_wait(info->write_sem);
	while (i < num)
	{
		if (!info[i].is_eating && \
		get_time() - info[i].last_ate_time >= info->time_to_die)
		{
			printf("%llu\t%d is death\n", \
			get_time() - info->start_time, info[i].id);
			return (0);
		}
		if (end && info[i].eat_num < info[i].must_eat_number)
			end = 0;
		else if (end && i == num - 1)
			return (0);
		i++;
	}
	sem_post(info->write_sem);
	return (1);
}

int	check_end(t_philo_info *info, int num)
{
	int	end;

	while (1)
	{
		end = 1;
		if (info->must_eat_number == -1)
			end = 0;
		if (!check(info, num, end))
			return (1);
		usleep(500);
	}
	return (1);
}
