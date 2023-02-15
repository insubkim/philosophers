/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:30:19 by inskim            #+#    #+#             */
/*   Updated: 2023/02/15 23:10:09 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*free_info(t_philo_info *info)
{
	free(info);
	return (0);
}

int	set_sem_info(t_philo_info *info, int num)
{
	int	i;
	sem_t	*sem[3];

	sem[0] = sem_open("fork", O_CREAT | O_EXCL, 0644, num);
	sem[1] = sem_open("scheduler", O_CREAT | O_EXCL, 0644, num / 2);
	sem[2] = sem_open("write", O_CREAT | O_EXCL, 0644, 1);
	i = -1;
	while (++i < num)
	{
		info[i].fork = sem[0];
		info[i].scheduler = sem[1];
		info[i].write = sem[2];
		info[i].eat_done = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!info[i].eat_done)
			return (0);
		pthread_mutex_init(info[i].eat_done, 0);
		pthread_mutex_lock(info[i].eat_done);
	}
	return (1);
}

t_philo_info	*set_philo_info(int arg[])
{
	t_philo_info	*info;
	int				i;
	long long		time;

	info = (t_philo_info *)malloc(sizeof(t_philo_info) * arg[0]);
	if (!info)
		return (0);
	time = get_time();
	i = -1;
	while (++i < arg[0])
	{
		info[i].id = i + 1;
		info[i].is_eating = 0;
		info[i].last_ate_time = time;
		info[i].time_to_die = arg[1];
		info[i].time_to_eat = arg[2];
		info[i].time_to_sleep = arg[3];
		info[i].must_eat_number = arg[4];
		info[i].start_time = time;
		info[i].eat_num = 0;
		info[i].done = 0;
	}
	if (!set_sem_info(info, arg[0]))
		return (free_info(info));
	return (info);
}
