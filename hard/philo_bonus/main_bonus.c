/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:22:06 by insub             #+#    #+#             */
/*   Updated: 2023/02/17 22:47:52 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	pid_t			*p;
	t_philo_info	*info;
	int				arg[5];
	int				*end;

	if (!set_arg(arg, --argc, ++argv))
		return (handle_error(0, 0, 0));
	if (!arg[0] || !arg[4])
		return (0);
	info = set_philo_info(arg);
	if (!info)
		return (handle_error(0, 0, 0));
	end = (int *)malloc(sizeof(int));
	if (!end)
		return (handle_error(info, 0, 0));
	p = create_philo(info, arg[0]);
	if (!p)
		return (handle_error(info, end, 0));
	*end = 0;
	if (arg[4] != -1)
		if (!create_all_ate(info, arg, end))
			return (handle_error(info, end, p));
	check_end(p, arg[0], end);
	free_info(info);
	return (0);
}
