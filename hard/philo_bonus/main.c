/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:22:06 by insub             #+#    #+#             */
/*   Updated: 2023/02/14 01:33:16 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	pid_t			*p;
	t_philo_info	*info;
	pthread_t		*check_eat_done;
	int				arg[5];

	if (!set_arg(arg, --argc, ++argv))
		return (handle_error(0));
	if (!arg[0])
		return (0);
	info = set_philo_info(arg);
	if (!info)
		return (handle_error(0));
	if (arg[4] != -1)
		create_all_ate(info, arg);
	p = create_philo(info, arg[0]);
	if (!p)
		return (handle_error(info));
	wait_process(p, arg);
	return (0);
}
