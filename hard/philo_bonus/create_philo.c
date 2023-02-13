/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:09:51 by insub             #+#    #+#             */
/*   Updated: 2023/02/13 22:04:32 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_message(int flag, t_philo_info *info)
{
	sem_wait(info->write_sem);
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
	sem_post(info->write_sem);
}

void	run_philo(t_philo_info *info)
{
	while (1)
	{
		sem_wait(info->scheduler);
		sem_wait(info->fork);
		print_message(0, info);
		sem_wait(info->fork);
		print_message(1, info);
		ft_usleep(info->time_to_eat * 1000);
		sem_wait(info->write_sem);
		info->is_eating = 0;
		info->eat_num++;
		sem_post(info->write_sem);
		sem_post(info->fork);
		sem_post(info->fork);
		sem_post(info->scheduler);
		print_message(2, info);
		ft_usleep(info->time_to_sleep * 1000);
		print_message(3, info);
	}
	exit(0);
}

pid_t	*create_philo(t_philo_info *info, int num)
{
	pid_t	*p;
	int		i;

	p = (pid_t *)malloc(sizeof(pid_t)*num);
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
