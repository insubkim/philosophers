/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_all_ate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:27:29 by inskim            #+#    #+#             */
/*   Updated: 2023/02/17 22:47:53 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	*run_all_ate(void *info)
{
	t_all_ate_info	*all_ate_info;
	int				i;

	all_ate_info = info;
	ft_usleep(all_ate_info->info->time_to_eat + 10000);
	i = 0;
	while (i < all_ate_info->num)
		sem_wait(all_ate_info->info[i++].eat_done);
	*(all_ate_info->end) = 1;
	free(all_ate_info);
	return (0);
}

int	create_all_ate(t_philo_info *philo_info, int *arg, int *end)
{
	pthread_t		p;
	t_all_ate_info	*all_ate_info;

	all_ate_info = (t_all_ate_info *)malloc(sizeof(t_all_ate_info));
	if (!all_ate_info)
		return (0);
	all_ate_info->info = philo_info;
	all_ate_info->num = arg[0];
	all_ate_info->end = end;
	pthread_create(&p, 0, run_all_ate, all_ate_info);
	pthread_detach(p);
	return (1);
}
