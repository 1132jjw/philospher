/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:31:53 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/27 12:49:52 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <time.h>

# define DEAD_NO_ONE 0
# define DEAD_ME 1
# define DEAD_OTHER 2

typedef struct s_philo
{
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	name_mutex;
	pthread_t		*thread;
	struct timeval	start_time;
	struct timeval	*end_time;
	struct timeval	*die_start;
	struct timeval	*die_end;
	int				*fork;
	int				*is_take_fork;
	int				created_philo;
	int				num;
	int				number_of_philosopher;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_must_eat;
	int				is_end;
	int				*is_think;
	int				*num_eat;
	int				*is_dead;
	int				*is_eat;
	int				*is_sleep;
}				t_philo;

int		arg_check(int argc, char **argv);
int		arg_number_check(int argc);
int		arg_is_num_check(int argc, char **argv);
int		ft_philo_init(t_philo *philo, int argc, char **argv);
float	time_diff(struct timeval *start, struct timeval *end);
void	ft_eat(t_philo *philo, int philo_num);
void	ft_sleep(t_philo *philo, int philo_num);
void	ft_take_fork(t_philo *philo, int num);
void	ft_put_fork(t_philo *philo, int num);
void	ft_think(t_philo *philo, int num);
void	time_stamp(t_philo *philo, int num, char *stat);
int		philo_end_check(t_philo *philo, int num);
int		ft_usleep_divide(int time);
void	*philo_routine(void *philo_temp);
int		philo_name(t_philo *philo);
void	philo_create(t_philo *philo);
void	philo_join(t_philo *philo);
void	ft_waiting_die(t_philo *philo, int num);
int		philo_end_check(t_philo *philo, int num);
int		philo_must_eat_check(t_philo *philo, int num);
void	philo_free(t_philo *philo);
void	*philo_routine(void *philo_temp);
void	waiting_create(t_philo *philo);
void	philo_count(t_philo *philo);
int		ft_atoi(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	philo_destroy(t_philo *philo);

#endif