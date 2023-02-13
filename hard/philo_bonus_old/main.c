/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 23:22:06 by insub             #+#    #+#             */
/*   Updated: 2023/02/14 00:21:19 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	kill_philo(pid_t *p, int num)
{
	int	i;
	int	status;

	i = 0;
	while (i < num)
	{
		kill(p[i], SIGKILL);
		i++;
	}
	i = 0;
	while (i < num)
	{
		waitpid(p[i], &status, WIFEXITED);
		i++;
	}
}

void	unlink_sem(void)
{
		sem_unlink("fork");
		sem_unlink("write");
		sem_unlink("scheduler");
}

int	main(int argc, char **argv)
{
	pid_t			*p;
	t_philo_info	*info;
	int				arg[5];

	if (!set_arg(arg, --argc, ++argv))
		return (handle_error(0));
	if (!arg[0])
		return (0);
	info = set_philo_info(arg);
	if (!info)
		return (handle_error(0));
	p = create_philo(info, arg[0]);
	if (!p)
		return (handle_error(info));	
	check_end(info, arg[0]);
	kill_philo(p, arg[0]);
	unlink_sem();
	return (0);
}
