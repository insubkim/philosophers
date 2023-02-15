/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:11:47 by inskim            #+#    #+#             */
/*   Updated: 2023/02/15 23:04:38 by insub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <semaphore.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>
# include <limits.h>
# include <signal.h>

typedef struct s_philo_info
{
	int				id;
	sem_t	*fork;
	sem_t	*scheduler;
	sem_t	*write;
	pthread_mutex_t	*eat_done;
	int				done;
	int				is_eating;
	long long		last_ate_time;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				must_eat_number;
	int				eat_num;
	long long		start_time;
}	t_philo_info;

typedef struct s_all_ate_info
{
	t_philo_info	*info;
	int num;
	int *end;
}	t_all_ate_info;


long long		get_time(void);
int				set_arg(int arg[], int argc, char *argv[]);
int				handle_error(t_philo_info *info);
long long		micro_get_time(void);
void			ft_usleep(long long time);
t_philo_info	*set_philo_info(int arg[]);
void    check_end(pid_t *p, int num, int *end);
void    create_all_ate(t_philo_info *philo_info, int *arg, int *end);
pid_t   *create_philo(t_philo_info *info, int num);

#endif
