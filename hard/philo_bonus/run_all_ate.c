/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_all_ate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:27:29 by inskim            #+#    #+#             */
/*   Updated: 2023/02/16 22:50:17 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*run_all_ate(void *info)
{
	t_all_ate_info	*all_ate_info;
	int		i;

	all_ate_info = info;
	i = 0;
	while (i < all_ate_info->num)
		pthread_mutex_lock(all_ate_info->info[i++].eat_done);
	*(all_ate_info->end) = 1;//data race
	return (0);
}

void	create_all_ate(t_philo_info *philo_info, int *arg, int *end)
{
	pthread_t	p;
	t_all_ate_info	all_ate_info;

	all_ate_info.info = philo_info;
	all_ate_info.num = arg[0];
	all_ate_info.end = end;
	pthread_create(&p, 0, run_all_ate, &all_ate_info);
}
