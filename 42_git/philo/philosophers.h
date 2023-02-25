/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: insub <insub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 20:11:47 by inskim            #+#    #+#             */
/*   Updated: 2023/02/13 20:07:55 by inskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_philo_info
{
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*write_mutex;
	pthread_mutex_t	*scheduler;
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

typedef struct s_node
{
	t_philo_info	*info;
	struct s_node	*next;
}	t_node;

typedef struct s_queue
{
	t_node	*front;
	t_node	*back;
}	t_queue;

typedef struct s_schedule_info
{
	t_queue			*queue1;
	t_queue			*queue2;
	int				num;
}	t_schedule_info;

long long		get_time(void);
int				set_arg(int arg[], int argc, char *argv[]);
int				handle_error(t_philo_info *info, \
		t_schedule_info *schedule_info, int num);
t_schedule_info	*set_schedule_info(t_philo_info *info, int num);
size_t			ft_strlen(const char *s);
t_philo_info	*set_philo_info(int arg[]);
pthread_t		*run_philo(t_philo_info *info, int num);
int				check_end(t_philo_info *info, int num);
long long		micro_get_time(void);
void			*create_philo(void *data);
pthread_t		*run_scheduler(t_philo_info *info, int num, t_schedule_info \
		*schedule_info);
t_queue			*make_queue(void);
t_philo_info	*dequeue_enqueue(t_queue *queue);
t_node			*make_node(t_philo_info *info);
void			enqueue(t_queue *queue, t_node *node);
void			*free_info(t_philo_info *info, int num);
void			*free_queue(t_queue *queue);
void			*free_schedule_info(t_schedule_info *schedule_info);
void			ft_usleep(long long time);

#endif
