/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 19:18:31 by inskim            #+#    #+#             */
/*   Updated: 2023/01/24 00:09:41 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	handle_error(int error_reason)
{
	write(2, "Error\n", 6);
	if (MALLOC_ERROR == error_reason)
		write(2, "malloc error\n", ft_strlen("malloc error\n"));
	else if (ARG_ERROR == error_reason)
		write(2, "arg error\n", ft_strlen("arg error\n"));
	else if (MUTEX_LOCK_ERROR == error_reason)
		write(2, "mutex lock error\n", ft_strlen("mutex lock error\n"));
	else
		write(2, "unknown error\n", ft_strlen("unknown error\n"));
		
	return (1);
}
