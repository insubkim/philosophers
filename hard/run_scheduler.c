/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_scheduler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:17:37 by insub             #+#    #+#             */
/*   Updated: 2023/02/12 10:20:11 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_mutexes(t_philo_info *info, int num)
{
	while (num-- > 0)
		pthread_mutex_lock(info[num].scheduler);
}

void	*schedule(t_schedule_info *info)
{
	t_philo_info	*p_info;
	int		cnt;

	while (1)
	{
		cnt = 0;
		while (cnt++ < info->num / 2)
			pthread_mutex_unlock(dequeue_enqueue(info->queue1)->scheduler);
		cnt = 0;
		while (cnt++ < info->num / 2)
		{
			p_info = dequeue_enqueue(info->queue2);
			while (1)
			{
				pthread_mutex_lock(p_info->scheduler);
				if (p_info->done)
				{
					p_info->done = 0;
					break ;
				}
				pthread_mutex_unlock(p_info->scheduler);
			}
		}
	}
	return (0);
}

void	*create_schedule(void *info)
{
	return (schedule((info)));
}

pthread_t	*run_scheduler(t_philo_info *info, int num, t_schedule_info \
		*schedule_info)
{
	pthread_t	*p;
	int		i;

	lock_mutexes(info, num);
	p = (pthread_t *)malloc(sizeof(pthread_t) * (num + 1));
	if (!p)
		return (0);
	i = -1;
	while (++i < num)
		pthread_create(&(p[i]), 0, create_philo, &(info[i]));
	pthread_create(&(p[i]), 0, create_schedule, schedule_info);
	return (p);
}
