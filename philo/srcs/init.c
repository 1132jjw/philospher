/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeujeon <jeujeon@student.42seoul.co.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:31:45 by jeujeon           #+#    #+#             */
/*   Updated: 2021/08/26 21:48:31 by jeujeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_arg_init(t_philo *philo, int argc, char **argv)
{
	philo->number_of_philosopher = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo->number_of_must_eat = ft_atoi(argv[5]);
	else
		philo->number_of_must_eat = -1;
}

void	ft_philo_memset(t_philo *philo)
{
	int		num_of_philo;

	num_of_philo = philo->number_of_philosopher;
	memset(philo->is_take_fork, 0, num_of_philo);
	memset(philo->num_eat, 0, num_of_philo);
	memset(philo->is_eat, 0, num_of_philo);
	memset(philo->is_dead, 0, num_of_philo);
	memset(philo->is_sleep, 0, num_of_philo);
	memset(philo->fork, 0, num_of_philo);
	memset(philo->is_think, 0, num_of_philo);
}

void	ft_philo_malloc(t_philo *philo)
{
	int		num_of_philo;

	num_of_philo = philo->number_of_philosopher;
	philo->fork_mutex = malloc(sizeof(pthread_mutex_t) * num_of_philo);
	philo->is_think = malloc(sizeof(int) * num_of_philo);
	philo->die_start = malloc(sizeof(struct timeval) * num_of_philo);
	philo->die_end = malloc(sizeof(struct timeval) * num_of_philo);
	philo->end_time = malloc(sizeof(struct timeval) * num_of_philo);
	philo->thread = malloc(sizeof(pthread_t) * num_of_philo);
	philo->is_take_fork = malloc(sizeof(int) * num_of_philo);
	philo->num_eat = malloc(sizeof(int) * num_of_philo);
	philo->is_eat = malloc(sizeof(int) * num_of_philo);
	philo->is_dead = malloc(sizeof(int) * num_of_philo);
	philo->is_sleep = malloc(sizeof(int) * num_of_philo);
	philo->fork = malloc(sizeof(int) * num_of_philo);
}

int	ft_mutex_init(t_philo *philo)
{
	int	i;
	int	is_error;

	pthread_mutex_init(&philo->die_mutex, NULL);
	pthread_mutex_init(&philo->name_mutex, NULL);
	i = 0;
	while (i < philo->number_of_philosopher)
	{
		is_error = \
		pthread_mutex_init(&philo->fork_mutex[i], NULL);
		if (is_error != 0)
		{
			printf("error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_philo_init(t_philo *philo, int argc, char **argv)
{	
	ft_arg_init(philo, argc, argv);
	ft_philo_malloc(philo);
	ft_philo_memset(philo);
	if (ft_mutex_init(philo))
		return (1);
	philo->is_end = 0;
	philo->num = 0;
	philo->created_philo = 0;
	return (0);
}
