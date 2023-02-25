/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/02/17 22:28:33 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	handle_error(t_philo_info *info, int *end, pid_t *p)
{
	write(2, "Error\n", 6);
	if (info)
		free_info(info);
	if (end)
		free(end);
	if (p)
		free(p);
	return (1);
}
