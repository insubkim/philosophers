/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:02:00 by insub             #+#    #+#             */
/*   Updated: 2023/02/11 18:14:41 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*free_info(t_philo_info *info, int num)
{
	int	i;

	if (!info)
		return (0);
	if (info->write_mutex)
	{
		i = 0;
		while (i < num)
		{
			if (!info[i].left_fork)
				break ;
			free(info[i].left_fork);
			if (!info[i].scheduler)
				break ;
			free(info[i].scheduler);
			i++;
		}
		free(info->write_mutex);
	}
	free(info);
	return (0);
}
