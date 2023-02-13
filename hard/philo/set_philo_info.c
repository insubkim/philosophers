/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:30:19 by inskim            #+#    #+#             */
/*   Updated: 2023/02/13 20:01:20 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	set_mutex_info(t_philo_info *info, int num)
{
	int				i;
	pthread_mutex_t	*write_mutex;

	write_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (!write_mutex)
		return (0);
	pthread_mutex_init(write_mutex, 0);
	i = -1;
	while (++i < num)
	{
		info[i].left_fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!info[i].left_fork)
			return (0);
		pthread_mutex_init(info[i].left_fork, 0);
		info[i].scheduler = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (!info[i].scheduler)
			return (0);
		pthread_mutex_init(info[i].scheduler, 0);
		if (i != 0)
			info[i - 1].right_fork = info[i].left_fork;
		if (i == num - 1)
			info[i].right_fork = info[0].left_fork;
		info[i].write_mutex = write_mutex;
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
	if (!set_mutex_info(info, arg[0]))
		return (free_info(info, arg[0]));
	return (info);
}
