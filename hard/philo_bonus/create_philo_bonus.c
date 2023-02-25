/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:32:29 by insub             #+#    #+#             */
/*   Updated: 2023/02/25 17:01:02 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	print_message(int flag, t_philo_info *info)
{
	sem_wait(info->write);
	if (flag == 0)
		printf("%llu\t%d has taken a fork\n", \
				get_time() - info->start_time, info->id);
	else if (flag == 1)
	{
		pthread_mutex_lock(info->mu1);
		info->is_eating = 1;
		info->last_ate_time = get_time();
		printf("%llu\t%d has taken a fork\n", \
				get_time() - info->start_time, info->id);
		printf("%llu\t%d is eating\n", \
				get_time() - info->start_time, info->id);
		pthread_mutex_unlock(info->mu1);
	}
	else if (flag == 2)
		printf("%llu\t%d is sleeping\n", \
				get_time() - info->start_time, info->id);
	else if (flag == 3)
		printf("%llu\t%d is thinking\n", \
				get_time() - info->start_time, info->id);
	sem_post(info->write);
}

void	*philo(void *data)
{
	t_philo_info	*info;

	info = data;
	sem_wait(info->eat_done);
	while (1)
	{
		sem_wait(info->scheduler);
		sem_wait(info->fork);
		print_message(0, info);
		sem_wait(info->fork);
		print_message(1, info);
		ft_usleep(info->time_to_eat * 1000);
		sem_wait(info->write);
		pthread_mutex_lock(info->mu1);
		info->is_eating = 0;
		if (++(info->eat_num) == info->must_eat_number)
			sem_post(info->eat_done);
		pthread_mutex_unlock(info->mu1);
		
		sem_post(info->write);
		sem_post(info->fork);
		sem_post(info->fork);
		sem_post(info->scheduler);
		print_message(2, info);
		ft_usleep(info->time_to_sleep * 1000);
		print_message(3, info);
	}
	return (0);
}

void	run_philo(t_philo_info *info)
{
	pthread_t	p;

	pthread_create(&p, 0, philo, info);
	while (1)
	{
		sem_wait(info->write);
		pthread_mutex_lock(info->mu1);
		if (!info->is_eating && \
				get_time() - info->last_ate_time >= info->time_to_die)
		{
			printf("%llu\t%d is death\n", \
					get_time() - info->start_time, info->id);
			break ;
		}
		pthread_mutex_unlock(info->mu1);
		sem_post(info->write);
		usleep(500);
	}
	exit(0);
}

pid_t	*create_philo(t_philo_info *info, int num)
{
	pid_t	*p;
	int		i;

	p = (pid_t *)malloc(sizeof(pid_t) * num);
	if (!p)
		return (0);
	i = 0;
	while (i < num)
	{
		p[i] = fork();
		if (!p[i])
			run_philo(&(info[i]));
		i++;
	}
	return (p);
}
