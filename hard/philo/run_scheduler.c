/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_scheduler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:17:37 by insub             #+#    #+#             */
/*   Updated: 2023/02/25 16:39:35 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_mutexes(t_philo_info *info, int num)
{
	while (--num >= 0)
		pthread_mutex_lock(info[num].scheduler);
}

void	*schedule(t_schedule_info *info)
{
	t_philo_info	*p_info;
	int				cnt;

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
	lock_mutexes(((t_schedule_info *)info)->queue1->front->info, ((t_schedule_info *)info)->num);
	return (schedule((info)));
}

pthread_t	*run_scheduler(t_philo_info *info, int num, t_schedule_info \
		*schedule_info)
{
	pthread_t	*p;
	int			i;

	p = (pthread_t *)malloc(sizeof(pthread_t) * (num + 1));
	if (!p)
		return (0);
	pthread_create(&(p[num]), 0, create_schedule, schedule_info);
	i = -1;
	while (++i < num)
		info[i].last_ate_time = get_time();
	i = -1;
	while (++i < num)
		pthread_create(&(p[i]), 0, create_philo, &(info[i]));
	return (p);
}
