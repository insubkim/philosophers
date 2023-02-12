/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_schedule_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:37:58 by insub             #+#    #+#             */
/*   Updated: 2023/02/12 15:46:19 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	make_node_enqueue(t_queue *queue, t_philo_info *info)
{
	t_node	*node;

	node = make_node(info);
	if (!node)
		return (0);
	enqueue(queue, node);
	return (1);
}

t_queue	*make_schedule_queue(t_philo_info *info, int num)
{
	t_queue	*queue;
	int	i;

	queue = make_queue();
	if (!queue)
		return (0);
	i = 0;
	while (i < num)
	{
		if (!make_node_enqueue(queue, &(info[i])))
			return (free_queue(queue));
		i = i + 2;
	}
	i = 1;
	while (i < num)
	{
		if (!make_node_enqueue(queue, &(info[i])))
			return (free_queue(queue));
		i = i + 2;
	}
	return (queue);
}

void	*free_schedule_info(t_schedule_info *schedule_info)
{
	if (schedule_info->queue1)
		free_queue(schedule_info->queue1);
	if (schedule_info->queue2)
		free_queue(schedule_info->queue2);
	return (0);
	free(schedule_info);
}

t_schedule_info	*set_schedule_info(t_philo_info *info, int num)
{
	t_schedule_info	*schedule_info;

	schedule_info = (t_schedule_info *)malloc(sizeof(t_schedule_info));
	if (!schedule_info)
		return (0);
	schedule_info->num = num;
	schedule_info->queue1 = make_schedule_queue(info, num);
	schedule_info->queue2 = make_schedule_queue(info, num);
	if (!schedule_info->queue1 || !schedule_info->queue2)
		return (free_schedule_info(schedule_info));
	return (schedule_info);
}
