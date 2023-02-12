/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:09:51 by insub             #+#    #+#             */
/*   Updated: 2023/02/13 03:49:55 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	busy_wait(t_philo_info *info)
{
	while (1)
	{
		pthread_mutex_lock(info->scheduler);
		if (!info->done)
		{
			pthread_mutex_unlock(info->scheduler);
			break ;
		}
		pthread_mutex_unlock(info->scheduler);
	}
}

void	print_message(int flag, t_philo_info *info)
{
	pthread_mutex_lock(info->write_mutex);
	if (flag == 0)
		printf("%llu\t%d has taken a fork\n", \
				get_time() - info->start_time, info->id);
	else if (flag == 1)
	{
		info->is_eating = 1;
		info->last_ate_time = get_time();
		printf("%llu\t%d has taken a fork\n", \
				get_time() - info->start_time, info->id);
		printf("%llu\t%d is eating\n", \
				get_time() - info->start_time, info->id);
	}
	else if (flag == 2)
		printf("%llu\t%d is sleeping\n", \
				get_time() - info->start_time, info->id);
	else if (flag == 3)
		printf("%llu\t%d is thinking\n", \
				get_time() - info->start_time, info->id);
	pthread_mutex_unlock(info->write_mutex);
}

void	*create_philo(void *data)
{
	t_philo_info	*info;

	info = data;
	while (1)
	{
		pthread_mutex_lock(info->scheduler);
		pthread_mutex_lock(info->left_fork);
		print_message(0, info);
		pthread_mutex_lock(info->right_fork);
		print_message(1, info);
		info->done = 1;
		pthread_mutex_unlock(info->scheduler);
		ft_usleep(info->time_to_eat * 1000);
		pthread_mutex_lock(info->write_mutex);
		info->is_eating = 0;
		info->eat_num++;
		pthread_mutex_unlock(info->write_mutex);
		pthread_mutex_unlock(info->left_fork);
		pthread_mutex_unlock(info->right_fork);
		print_message(2, info);
		ft_usleep(info->time_to_sleep * 1000);
		print_message(3, info);
		busy_wait(info);
	}
	return (0);
}
