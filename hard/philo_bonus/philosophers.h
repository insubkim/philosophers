/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inskim <inskim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:11:47 by inskim            #+#    #+#             */
/*   Updated: 2023/02/13 23:42:32 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <semaphore.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>
# include <signal.h>

typedef struct s_philo_info
{
	int				id;
	sem_t	*fork;
	sem_t	*write_sem;
	sem_t	*scheduler;
	sem_t	*eat_message;
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

long long		get_time(void);
int				set_arg(int arg[], int argc, char *argv[]);
int				handle_error(t_philo_info *info);
size_t			ft_strlen(const char *s);
t_philo_info	*set_philo_info(int arg[]);
int				check_end(t_philo_info *info, int num);
long long		micro_get_time(void);
pid_t	*create_philo(t_philo_info *info, int num);
void			*free_info(t_philo_info *info);
void			ft_usleep(long long time);
void	unlink_sem(void);
char	*ft_itoa(int n);

#endif
