/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/02/12 10:49:01 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_queue	*make_queue(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (0);
	queue->front = 0;
	queue->back = 0;
	return (queue);
}

void	enqueue(t_queue *queue, t_node *node)
{
	if (!(queue->front))
	{
		queue->front = node;
		queue->back = node;
		node->next = node;
	}
	else
	{
		queue->back->next = node;
		node->next = queue->front;
		queue->back = node;
	}
}

t_philo_info	*dequeue_enqueue(t_queue *queue)
{
	t_node	*node;

	node = queue->front;
	queue->front = queue->front->next;
	queue->back = queue->back->next;
	return (node->info);
}

t_node	*make_node(t_philo_info *info)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->info = info;
	node->next = 0;
	return (node);
}

void	*free_queue(t_queue *queue)
{
	t_node	*node;

	node = queue->front;
	while (queue->front)
	{
		node = queue->front;
		queue->front = node -> next;
		free(node);
	}
	free(queue);
	return (0);
}
