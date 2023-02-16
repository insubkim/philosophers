/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:22:06 by insub             #+#    #+#             */
/*   Updated: 2023/02/15 22:52:04 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	pid_t		*p;
	t_philo_info	*info;
	int		arg[5];
	int		end;

	if (!set_arg(arg, --argc, ++argv))
		return (handle_error(0));
	if (!arg[0])
		return (0);
	info = set_philo_info(arg);
	if (!info)
		return (handle_error(0));
	end = 0;
	if (arg[4] != -1)
		create_all_ate(info, arg, &end);
	p = create_philo(info, arg[0]);
	if (!p)
		return (handle_error(info));
	check_end(p, arg[0], &end);
	return (0);
}
